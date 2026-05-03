/**
 * @file DataProcessor.cpp
 * @brief Implements the DataProcessor base class for measurement data
 * processing.
 */
#include "DataProcessor.hpp"
#include "DataProcessorAlpha.hpp"
#include <array>
#include <chrono>
#include <iostream>

/**
 * @brief Runs the data processing algorithm
 */
void AlgorithmsLib::DataProcessor::Run() { AlgorithmImplementation(); }
