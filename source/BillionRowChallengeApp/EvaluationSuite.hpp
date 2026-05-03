#pragma once
#include "DataManager.hpp"
#include "DataProcessor.hpp"
#include "DataProcessorFactory.hpp"
#include <Benchmark.hpp>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

namespace BenchmarkLib
{
/// @brief Class to manage benchmarks for all algorithms and present the results
/// in a clear and concise manner.

class EvaluationSuite
{
public:
    explicit EvaluationSuite(AlgorithmsLib::DataManager* dataManager)
        : _dataManager(dataManager)
    {
    }
    void RunAllBenchmarks()
    {
        auto processors =
            AlgorithmsLib::DataProcessorFactory::CreateAllDataProcessors(
                _dataManager);
        if (processors.empty())
        {
            throw std::runtime_error(
                "No data processors registered. Cannot run benchmarks.");
        }

        for (const auto& processor : processors)
        {
            Benchmark benchmark(*processor);
            benchmark.Run();
            benchmark.PrintResults();
        }
    }

private:
    AlgorithmsLib::DataManager* _dataManager;
};

} // namespace BenchmarkLib