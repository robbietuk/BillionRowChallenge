add_library(BenchmarkLib STATIC
    Benchmark.hpp
    Benchmark.cpp
)
target_include_directories(BenchmarkLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
