add_executable(testbin2c main.cpp)
add_dependencies(testbin2c GPCBin2C)

# Header-only library: just adding include directory here
target_include_directories(testbin2c BEFORE PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/external/boost.process)

target_compile_definitions(testbin2c PRIVATE "APPLICATION_PATH=\"$<TARGET_FILE:GPCBin2C>\"")

add_test(NAME fails_without_parameters COMMAND testbin2c "$<TARGET_FILE:GPCBin2C>" non-zero)
