cmake_minimum_required(VERSION 3.1)

message("TOOL_PATH=${TOOL_PATH}")

add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/generated/data.dat.c
  COMMAND "${TOOL_PATH}" ${CMAKE_CURRENT_SOURCE_DIR}/data.dat 
    --source=${CMAKE_CURRENT_BINARY_DIR}/generated/data.dat.c
    --header=${CMAKE_CURRENT_BINARY_DIR}/generated/data.dat.h
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/data.dat
)

add_executable(test_exe 
  main.cpp
  # Generated files
  ${CMAKE_CURRENT_BINARY_DIR}/generated/data.dat.c
)

target_include_directories(test_exe PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/generated)
