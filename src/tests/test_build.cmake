# SOURCE_DIR    root source directory (containing root CMakeLists.txt)
# BUILD_DIR     build ("binary") directory
# TOOL_PATH     path of a tool require by CMakeLists.txt

# Configure

if (NOT SOURCE_DIR)
  message(FATAL_ERROR "No SOURCE_DIR specified")
endif()
if (NOT BUILD_DIR)
  set(BUILD_DIR ${SOURCE_DIR}/build)
  message("No BUILD_DIR specified, set to \"${BUILD_DIR}\"")
endif()

file(MAKE_DIRECTORY ${BUILD_DIR})
file(REMOVE ${BUILD_DIR}/*)

message("SOURCE_DIR=${SOURCE_DIR}")
message("TOOL_PATH =${TOOL_PATH}")

set(definitions)
if (TOOL_PATH)
  list(APPEND definitions "-DTOOL_PATH=${TOOL_PATH}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} ${definitions} ${SOURCE_DIR}
  WORKING_DIRECTORY "${BUILD_DIR}"
  RESULT_VARIABLE result
  OUTPUT_VARIABLE output
  ERROR_VARIABLE error
)

if (NOT (result EQUAL 0))
  message(FATAL_ERROR "CMake configuration failed with output:\n${output}\n..and error output:\n${error}")
endif()
message("CMake configuration output:\n${output}")

# Build

execute_process(COMMAND ${CMAKE_COMMAND} --build "${BUILD_DIR}" --config Debug
  WORKING_DIRECTORY "${BUILD_DIR}" 
  RESULT_VARIABLE result
  OUTPUT_VARIABLE output
  ERROR_VARIABLE error
)

if (NOT (result EQUAL 0))
  message(FATAL_ERROR "CMake build failed with output:\n${output}\n..and error output:\n${error}")
endif()
message("CMake build output:\n${output}")
