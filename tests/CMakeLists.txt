# Testing library
CPMAddPackage("gh:catchorg/Catch2@2.13.6")
# Adds Catch2Catch2

# FetchContent_Declare(
#   catch
#   GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#   GIT_TAG v2.13.6)
# FetchContent_MakeAvailable(catch)
# Adds Catch2::Catch2

# Tests need to be added as executables first
add_executable(testlib tests-main.cc test-main.cc)

# I'm using C++20 in the test because concepts
target_compile_features(testlib PRIVATE cxx_std_20)

# Should be linked to the main library, as well as the Catch2 testing library
target_link_libraries(testlib PRIVATE main_library Catch2)

# If you register a test, then ctest and make test will run it.
# You can also run examples and check the output, as well.
add_test(
  NAME testlibtest
  COMMAND testlib) # Command can be a target
