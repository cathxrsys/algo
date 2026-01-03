cmake_minimum_required(VERSION 3.10)

project(algo VERSION 1.0)

add_executable(algo main.cpp)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(tests test.cpp)
target_link_libraries(tests gtest_main)
add_test(NAME tests COMMAND tests)