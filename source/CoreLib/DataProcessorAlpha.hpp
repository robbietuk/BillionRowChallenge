#pragma once
#include "DataManager.hpp"
#include "DataProcessor.hpp"
#include <iostream>

namespace CoreLib
{
/**
 * @class DataProcessorAlpha
 * @brief Example implementation of DataProcessor for a specific algorithm.
 */
class DataProcessorAlpha : public DataProcessor
{
public:
    /**
     * @brief Constructs DataProcessorAlpha with a DataManager pointer.
     * @param dataManager Non-owning pointer to a DataManager instance.
     */
    DataProcessorAlpha(const DataManager* dataManager);
    /**
     * @brief Implements the specific data processing algorithm.
     */
    void AlgorithmImplementation() override;
};

}; // namespace CoreLib