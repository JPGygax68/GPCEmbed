#
# test_nonzero.cmake
#
# Tests that the specified command returns a non-zero value.
#
# Parameter variables:
# CMD         command to execute (with parameters)
# WORK_DIR    working directory

if (NOT WORK_DIR)
  set(WORK_DIR ${CMAKE_CURRENT_BINARY_DIR})
endif()

execute_process(COMMAND ${CMD}
  WORKING_DIRECTORY "${WORK_DIR}" 
  RESULT_VARIABLE result
)

if (${result} EQUAL 0)
  message(FATAL_ERROR "Commmand returned 0")
endif()
