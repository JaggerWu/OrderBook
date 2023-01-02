cmake_minimum_required(VERSION 3.23)
project(OrderBook)

# set headers
file(GLOB Header_Files *.h)

# set cpp files
file(GLOB Source_Files *.cc)

# set all files
set(ALL_FILES
    ${Header_Files}
    ${Source_Files}
)

add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET OrderBook PROPERTY CXX_STANDARD 17)
endif()
