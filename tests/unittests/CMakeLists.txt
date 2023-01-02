cmake_minimum_required(VERSION 3.23)

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIR})
set(TEST_LIBRARIES ${GTEST_BOTH_LIBRARIES})

set(UNITTEST_SOURCES
    unittests.cc
)

add_executable(unittests ${UNITTEST_SOURCES})
target_link_libraries(unittests ${TEST_LIBRARIES} OrderBook)

