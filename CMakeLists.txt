cmake_minimum_required(VERSION 3.4)
project(arithmetics)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(arithmetics STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/arithmetics.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)

add_executable(example1 ${CMAKE_CURRENT_SOURCE_DIR}/examples/example1.cpp)

target_link_libraries(example1 arithmetics)

install(TARGETS example1 RUNTIME DESTINATION bin)
install(TARGETS arithmetics DESTINATION lib)
