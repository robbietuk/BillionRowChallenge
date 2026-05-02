#pragma once
#include "DataProcessor.hpp"
#include <chrono>
#include <string>

namespace BenchmarkLib
{

enum class EBenchmarkStatus
{
    NotStarted,
    Running,
    Completed,
    Failed
};

class BenchmarkStatistics
{
public:
    BenchmarkStatistics(const AlgorithmsLib::DataProcessor* processor)
        : BenchmarkStatistics(processor->GetAlgorithmName())
    {
    }
    BenchmarkStatistics(const std::string& algorithmName)
        : _algorithmName(algorithmName)
    {
    }

    inline void Start()
    {
        _status = EBenchmarkStatus::Running;
        _startTime = std::chrono::high_resolution_clock::now();
    }
    inline void End()
    {
        _endTime = std::chrono::high_resolution_clock::now();
        _status = EBenchmarkStatus::Completed;
    }
    inline void Fail()
    {
        _endTime = std::chrono::high_resolution_clock::now();
        _status = EBenchmarkStatus::Failed;
    }

    std::chrono::milliseconds ExecutionTime() const;
    void Print() const;

private:
    std::string _algorithmName;
    std::chrono::high_resolution_clock::time_point _startTime;
    std::chrono::high_resolution_clock::time_point _endTime;
    EBenchmarkStatus _status = EBenchmarkStatus::NotStarted;
};
} // namespace BenchmarkLib
