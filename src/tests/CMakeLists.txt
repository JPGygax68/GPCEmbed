
add_test(NAME Fails_with_no_parameters
  COMMAND ${CMAKE_COMMAND} 
    -DCMD=$<TARGET_FILE:GPCEmbed>
    -DERROR_CONTAINS=No\ data\ file\ specified
    -P ${CMAKE_CURRENT_SOURCE_DIR}/test_command.cmake
)

add_test(NAME Test_program_builds
  COMMAND ${CMAKE_COMMAND} 
    -DSOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}/test1
    -DBUILD_DIR=${CMAKE_CURRENT_BINARY_DIR}/test1
    -DTOOL_PATH=$<TARGET_FILE:GPCEmbed>
    -P ${CMAKE_CURRENT_SOURCE_DIR}/test_build.cmake
)
