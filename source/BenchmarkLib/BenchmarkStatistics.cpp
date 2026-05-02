#include "BenchmarkStatistics.hpp"
#include <chrono>
#include <iostream>
#include <stdexcept>

using namespace BenchmarkLib;

std::chrono::milliseconds BenchmarkStatistics::ExecutionTime() const
{
    if (_status != EBenchmarkStatus::Completed &&
        _status != EBenchmarkStatus::Failed)
    {
        throw std::runtime_error("Cannot calculate execution time: "
                                 "Benchmark is not completed or failed.");
    }
    return std::chrono::duration_cast<std::chrono::milliseconds>(_endTime -
                                                                 _startTime);
}

void BenchmarkLib::BenchmarkStatistics::Print() const
{
    switch (_status)
    {
        case EBenchmarkStatus::NotStarted:
            std::cout << "Benchmark has not been started yet." << std::endl;
            break;
        case EBenchmarkStatus::Failed:
            std::cout << "Benchmark failed after " << ExecutionTime().count()
                      << " ms." << std::endl;
            break;
        case EBenchmarkStatus::Running:
        {
            auto now = std::chrono::high_resolution_clock::now();
            auto elapsed =
                std::chrono::duration_cast<std::chrono::milliseconds>(
                    now - _startTime);
            std::cout << "Benchmark is still running. Elapsed time: "
                      << elapsed.count() << " ms." << std::endl;
            break;
        }
        case EBenchmarkStatus::Completed:
        {
            std::string msg = "Benchmark completed successfully in " +
                              std::to_string(ExecutionTime().count()) + " ms.";
            std::cout << msg << std::endl;
            break;
        }
    }
};