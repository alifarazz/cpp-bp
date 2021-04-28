cmake_minimum_required(VERSION 3.16)

project(
  some_porject
  VERSION 0.0.1
  LANGUAGES CXX)

set(PROJECT_IS_MAIN (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME))

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(PROJECT_IS_MAIN)

  # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here

  # Let's ensure -std=c++xx instead of -std=g++xx
  set(CMAKE_CXX_EXTENSIONS OFF)

  # Let's nicely support folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  # Testing only available if this is the main app
  # Note this needs to be done in the main CMakeLists
  # since it calls enable_testing, which must be in the
  # main CMakeLists.
  include(CTest)

  # # Docs only available if this is the main app
  # find_package(Doxygen)
  # if(Doxygen_FOUND)
  #   add_subdirectory(docs)
  # else()
  #   message(STATUS "Doxygen not found, not building docs")
  # endif()
endif()

# for dependencies
include(cmake/CPM.cmake)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
  CPMAddPackage(
    NAME Ccache.cmake
    GITHUB_REPOSITORY TheLartians/Ccache.cmake
    VERSION 1.2
    )
endif(CCACHE_FOUND)


add_subdirectory(src)

# Testing only available if this is the main app
if(PROJECT_IS_MAIN AND BUILD_TESTING)
  add_subdirectory(tests)
endif()
