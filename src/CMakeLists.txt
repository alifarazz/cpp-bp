# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${some_porject_SOURCE_DIR}/src/include/*.hh")

# Make an automatic library - will be static or dynamic based on user setting
add_library(main_library main.cc ${HEADER_LIST})
# add_library(main_library SHARED main.cc ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(main_library PUBLIC ./include/)

# # This depends on (header only) boost
# target_link_libraries(ssstopwatch_library PRIVATE Boost::boost)

# All users of this library will need at least C++20 because concepts
target_compile_features(main_library PUBLIC cxx_std_20)

# IDEs should put the headers in a nice place
# source_group(
#   TREE "${PROJECT_SOURCE_DIR}/src/include"
#   PREFIX "Private Header Files"
#   FILES ${HEADER_LIST})

source_group(
  TREE "${PROJECT_SOURCE_DIR}/src/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
