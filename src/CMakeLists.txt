cmake_minimum_required(VERSION 3.0)

#------------------------------------------------
# Project + basics
#

add_executable(GPCBin2C bin2c.cpp)

#------------------------------------------------
# Tests
#

enable_testing()

add_subdirectory(tests)

#------------------------------------------------
# Export this build tree for use by other CMake projects.
#

# Create a config file for build tree usage:
set(TARGET_SET "GPCBin2C")
set(TARGETSET_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(TARGETSET_LIB_DIR     ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(TARGETSET_CMAKE_DIR   ${CMAKE_CURRENT_BINARY_DIR}/src)
configure_file("project-config.cmake.in" "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake" @ONLY)

export(TARGETS GPCBin2C FILE "GPCBin2C-targets.cmake")

export(PACKAGE GPCBin2C)

#------------------------------------------------
# INSTALLATION
#

# Note: this requires CMAKE_INSTALL_PREFIX to be defined by the user

# Create a config file for the install tree:
set(TARGETSET_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include)
set(TARGETSET_LIB_DIR     ${CMAKE_INSTALL_PREFIX}/lib) # not needed with header-only libraries
set(TARGETSET_CMAKE_DIR   ${CMAKE_INSTALL_PREFIX}/CMake)
configure_file("project-config.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/InstallFiles/GPCBin2C-config.cmake"
  @ONLY)
  
install(TARGETS GPCBin2C 
  EXPORT GPCBin2C-targets
  RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
)

install(EXPORT GPCBin2C-targets DESTINATION "cmake")
