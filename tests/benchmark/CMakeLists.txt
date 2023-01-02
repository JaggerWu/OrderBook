cmake_minimum_required(VERSION 3.23)

set(BENCHMARK_SOURCES
    benchmark.cc
)

add_executable(benchmark ${BENCHMARK_SOURCES})
# target_link_libraries(benchmark ${TEST_LIBRARIES})
