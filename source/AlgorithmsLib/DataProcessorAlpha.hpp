#pragma once
#include "DataManager.hpp"
#include "DataProcessor.hpp"
#include <Statistics.hpp>
#include <iostream>
#include <unordered_map>

namespace AlgorithmsLib
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
    DataProcessorAlpha(const DataManager* dataManager)
        : DataProcessor(dataManager, "DataProcessorAlpha")
    {
    }

    static std::unique_ptr<DataProcessor> Create(const DataManager* dataManager)
    {
        return std::make_unique<DataProcessorAlpha>(dataManager);
    }

    Statistics GetCityStatistics(std::string cityName) override;

protected:
    /**
     * @brief Implements the specific data processing algorithm.
     */
    void AlgorithmImplementation() override;
    void AddMeasurementToCityStats(const std::string& city, float measurement);
    std::unordered_map<std::string, StatisticsAlpha> _cityStats;
};

}; // namespace AlgorithmsLib