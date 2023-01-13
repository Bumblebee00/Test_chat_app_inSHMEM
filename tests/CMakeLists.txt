project(Tests)
set(CMAKE_CXX_STANDARD 17)

# add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Adds tests for Example Library
add_executable(ExampleLibrary_test ExampleLibrary_test.cpp)
target_link_libraries(ExampleLibrary_test gtest gtest_main)
target_link_libraries(ExampleLibrary_test ExampleLibrary)   # Links Example Library to its test

add_test(NAME    ExampleLibrary_test   # Adds test to cmake
         COMMAND ExampleLibrary_test)