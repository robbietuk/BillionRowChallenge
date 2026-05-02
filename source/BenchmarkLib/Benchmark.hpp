
#pragma once
#include "BenchmarkStatistics.hpp"
#include "DataProcessor.hpp"
#include <stdexcept>

namespace BenchmarkLib
{

/// @brief Class to perform benchmarks on different data processing algorithms.
/// This class needs to have a number of features:
/// - It should be able to run benchmarks on different implementations of the
///   DataProcessor class, such as DataProcessorAlpha, DataProcessorBeta, etc.
/// - It should be able to measure the execution time of the algorithms and
///   report the results in a clear and concise manner.
/// - It should be able to perform multiple runs of the benchmarks to ensure
/// statistical significance of the results.
class Benchmark
{

public:
    explicit Benchmark(AlgorithmsLib::DataProcessor& processor)
        : _processor(processor), _statistics(&_processor)
    {
    }

    void RunBenchmark();
    void PrintResults() const { _statistics.Print(); }

private:
    AlgorithmsLib::DataProcessor& _processor;
    BenchmarkStatistics _statistics;
};

} // namespace BenchmarkLib