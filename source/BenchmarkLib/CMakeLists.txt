add_library(BenchmarkLib STATIC
    Benchmark.hpp
    Benchmark.cpp
    BenchmarkStatistics.hpp
    BenchmarkStatistics.cpp
)
target_include_directories(BenchmarkLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(BenchmarkLib PUBLIC AlgorithmsLib)
        