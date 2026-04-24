/**
 * @file DataProcessor.cpp
 * @brief Implements the DataProcessor base class for measurement data processing.
 */
#include "DataProcessor.hpp"
#include <chrono>
#include <iostream>

/**
 * @brief Constructs a DataProcessor with a DataManager pointer.
 * @param dataManager Non-owning pointer to a DataManager instance.
 */
CoreLib::DataProcessor::DataProcessor(const DataManager* dataManager)
    : _dataManager(dataManager)
{
}

/**
 * @brief Runs the data processing algorithm and measures execution time.
 */
void CoreLib::DataProcessor::Run()
{
    try
    {
        auto startTime = std::chrono::high_resolution_clock::now();
        AlgorithmImplementation();
        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
            endTime - startTime);
        std::string durationStr = std::to_string(duration.count()) + " ms";
        std::string msg = "Algorithm executed in " + durationStr;
        std::cout << msg << std::endl;
    }
    catch(const std::exception& ex)
    {
        std::cerr << "Error during algorithm execution: " << ex.what() << std::endl;
    }
}