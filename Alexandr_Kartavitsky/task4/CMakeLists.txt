cmake_minimum_required(VERSION 3.10)
project(StringTest)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_SOURCE_DIR}/googletest/googletest/include)
link_directories(${CMAKE_SOURCE_DIR}/googletest/build/lib)

add_executable(StringTest test.cpp String.cpp)

target_link_libraries(StringTest gtest gtest_main)
