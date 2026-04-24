#pragma once
#include "DataManager.hpp"
#include "DataProcessor.hpp"
#include <iostream>
#include <unordered_map>
#include <Statistics.hpp>

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
    Statistics GetCityStatistics(std::string cityName) override
    {
        if (!_cityStats.contains(cityName))
            throw std::runtime_error("City not found: " + cityName);
        return _cityStats.find(cityName)->second;
    }

protected:
    /**
     * @brief Implements the specific data processing algorithm.
     */
    void AlgorithmImplementation() override; 
    void AddMeasurementToCityStats(const std::string& city, float measurement);

    // Dictionary to hold city statistics, e.g., sum, count, max, min for each
    // city
    std::unordered_map<std::string, StatisticsAlpha> _cityStats;
};

}; // namespace CoreLib