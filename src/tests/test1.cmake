
file(REMOVE_RECURSE ${CMAKE_CURRENT_BINARY_DIR}/test1)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/test1)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/test1/build)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/test1/test.cpp
  "int main(int argc, char *argv[]) { return 0; }\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/test1/CMakeLists.txt
  "cmake_minimum_required(VERSION 3.1)\n"
  "add_executable(test_executable test.cpp)\n"
  # TODO: add the generated source file(s)
  # TODO: put the location of the import header into the INCLUDE path
)

execute_process(COMMAND ${CMAKE_COMMAND} ..
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/test1/build
)

execute_process(COMMAND ${CMAKE_COMMAND} --build . --config Release
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/test1/build
)
