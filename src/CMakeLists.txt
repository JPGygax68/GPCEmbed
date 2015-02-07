cmake_minimum_required(VERSION 3.0)

#------------------------------------------------
# Project + basics
#

add_executable(GPCEmbed embed.cpp)

#------------------------------------------------
# Tests
#

enable_testing()

add_subdirectory(tests)

#------------------------------------------------
# Export this build tree for use by other CMake projects.
#

# Create a config file for build tree usage:
set(TARGET_SET "GPCEmbed")
set(TARGETSET_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(TARGETSET_LIB_DIR     ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(TARGETSET_CMAKE_DIR   ${CMAKE_CURRENT_BINARY_DIR}/src)
configure_file("project-config.cmake.in" "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake" @ONLY)

export(TARGETS GPCEmbed FILE "GPCEmbed-targets.cmake")

export(PACKAGE GPCEmbed)

#------------------------------------------------
# INSTALLATION
#

# Note: this requires CMAKE_INSTALL_PREFIX to be defined by the user

# Create a config file for the install tree:
set(TARGETSET_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include)
set(TARGETSET_LIB_DIR     ${CMAKE_INSTALL_PREFIX}/lib) # not needed with header-only libraries
set(TARGETSET_CMAKE_DIR   ${CMAKE_INSTALL_PREFIX}/CMake)
configure_file("project-config.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/InstallFiles/GPCEmbed-config.cmake"
  @ONLY)
  
install(TARGETS GPCEmbed 
  EXPORT GPCEmbed-targets
  RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
)

install(EXPORT GPCEmbed-targets DESTINATION "cmake")
