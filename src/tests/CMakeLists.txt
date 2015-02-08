
if (0)
add_executable(TestDriver main.cpp)
add_dependencies(TestDriver GPCEmbed)

# Header-only library: just adding include directory here
target_include_directories(TestDriver BEFORE PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/external/boost.process)

target_compile_definitions(TestDriver PRIVATE "APPLICATION_PATH=\"$<TARGET_FILE:GPCEmbed>\"")
endif()

add_test(NAME fails_without_parameters 
  COMMAND ${CMAKE_COMMAND} 
    -DCMD=$<TARGET_FILE:GPCEmbed>
    -DERROR_CONTAINS=No\ data\ file\ specified
    # TODO: instead of just non-zero, also check for the text "no data file specified"
    -P ${CMAKE_CURRENT_SOURCE_DIR}/test_command.cmake
)

if (0)
add_test(NAME fails_without_any_output_file COMMAND TestDriver --non-zero 
  "$<TARGET_FILE:GPCEmbed>" ${CMAKE_CURRENT_SOURCE_DIR}/data/data.bin
)
endif()
