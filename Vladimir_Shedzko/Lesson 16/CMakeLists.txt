# # version 3.15 or later of CMake is needed
cmake_minimum_required(VERSION 3.15)

project(Lesson16 VERSION 1.0.1 DESCRIPTION "figures testing")

include(GoogleTest)
include(CTest)
include(FetchContent)

enable_testing() 

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  if(MSVC)
    add_compile_options(/MD$<$<CONFIG:Debug>:d>)
  endif()   # MSVC
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()     # NOT googletest_POPULATED

mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

set_target_properties(gtest PROPERTIES FOLDER extern)
set_target_properties(gtest_main PROPERTIES FOLDER extern)
set_target_properties(gmock PROPERTIES FOLDER extern)
set_target_properties(gmock_main PROPERTIES FOLDER extern)

macro(package_add_test_with_libraries TESTNAME FILES LIBRARIES TEST_WORKING_DIRECTORY)
    add_executable(${TESTNAME} ${FILES})
    target_link_libraries(${TESTNAME} gtest gmock gtest_main ${LIBRARIES})
    gtest_discover_tests(${TESTNAME}
        WORKING_DIRECTORY ${TEST_WORKING_DIRECTORY}
        PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${TEST_WORKING_DIRECTORY}"
    )
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

#Include headers
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src")

# Custom figure tests
# without it public headers won't get installed

add_library(Container STATIC)

target_sources(Container
  PRIVATE
      src/Figures.cpp
      src/Container.cpp
)

set(public_headers
  include/Figures.h
  include/Container.h
)

target_include_directories(Container
    PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        # where top-level project will look for the library's public headers
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        # where external projects will look for the library's public headers
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# note that ${public_headers} has to be in quotes
set_target_properties(Container PROPERTIES PUBLIC_HEADER "${public_headers}")


set_target_properties(Container PROPERTIES VERSION ${PROJECT_VERSION})


add_executable(task_6 src/task_6.cpp) # add test executable

target_link_libraries(
    task_6

    Container
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(task_6) # discovers tests in compiled file