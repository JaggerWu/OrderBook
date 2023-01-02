cmake_minimum_required(VERSION 3.23)
project(OrderBookDemo)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_subdirectory(src)
add_subdirectory(tests)

