cmake_minimum_required(VERSION 3.4)
project(arithmetics)

option(BUILD_TESTS "Build tests" OFF)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(arithmetics STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/arithmetics.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)

add_executable(example1 ${CMAKE_CURRENT_SOURCE_DIR}/examples/example1.cpp)

target_link_libraries(example1 arithmetics)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(third_party/gtest)
    file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
    add_executable(check ${${PROJECT_NAME}_TEST_SOURCES})
    target_link_libraries(check ${PROJECT_NAME} gtest_main)
    add_test(NAME simple_test COMMAND check)
endif()

install(TARGETS example1 RUNTIME DESTINATION bin)
install(TARGETS arithmetics DESTINATION lib)
