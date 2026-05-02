
#include "Benchmark.hpp"
#include "BenchmarkStatistics.hpp"
#include <chrono>
#include <iostream>

using namespace BenchmarkLib;

void BenchmarkLib::Benchmark::RunBenchmark()
{
    try
    {
        _statistics.Start();
        _processor->Run();
        _statistics.End();
    }
    catch (const std::exception& ex)
    {
        _statistics.Fail();
        std::cerr << "Error during algorithm execution: " << ex.what()
                  << std::endl;
    }
    _statistics.Print();
}
