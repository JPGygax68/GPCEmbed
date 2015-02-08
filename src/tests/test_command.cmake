#
# test_nonzero.cmake
#
# Tests that the specified command returns a non-zero value.
#
# Parameter variables:
# CMD                       command to execute (with parameters)
# WORK_DIR                  working directory
# ERROR_CONTAINS            check that the command's error contains the specified string

if (NOT WORK_DIR)
  set(WORK_DIR ${CMAKE_CURRENT_BINARY_DIR})
endif()

execute_process(COMMAND ${CMD}
  WORKING_DIRECTORY "${WORK_DIR}" 
  RESULT_VARIABLE result
  OUTPUT_VARIABLE output
  ERROR_VARIABLE error
)

if (ERROR_CONTAINS)
  message("ERROR_CONTAINS=${ERROR_CONTAINS}")
  #message(${error})
  string(FIND "${error}" "${ERROR_CONTAINS}" s)
  if (s LESS 0)
    message("Error output:\n${error}")
    message(FATAL_ERROR "Check failed: error output does not contain \"${ERROR_CONTAINS}\"")
  endif()
endif()

if (${result} EQUAL 0)
  message(FATAL_ERROR "Commmand returned 0")
endif()
