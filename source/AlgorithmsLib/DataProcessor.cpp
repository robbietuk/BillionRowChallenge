/**
 * @file DataProcessor.cpp
 * @brief Implements the DataProcessor base class for measurement data
 * processing.
 */
#include "DataProcessor.hpp"
#include <chrono>
#include <iostream>

/**
 * @brief Constructs a DataProcessor with a DataManager pointer.
 * @param dataManager Non-owning pointer to a DataManager instance.
 */
AlgorithmsLib::DataProcessor::DataProcessor(const DataManager* dataManager,
                                            std::string algorithmName)
    : _dataManager(dataManager), _algorithmName(std::move(algorithmName))
{
}

/**
 * @brief Runs the data processing algorithm
 */
void AlgorithmsLib::DataProcessor::Run() { AlgorithmImplementation(); }