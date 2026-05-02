#include "DataProcessorAlpha.hpp"
#include <fstream>

using namespace AlgorithmsLib;

Statistics
AlgorithmsLib::DataProcessorAlpha::GetCityStatistics(std::string cityName)
{
    if (!_cityStats.contains(cityName))
        throw std::runtime_error("City not found: " + cityName);
    return _cityStats.find(cityName)->second;
}

/**
 * @brief Runs the DataProcessorAlpha-specific algorithm implementation.
 */
void DataProcessorAlpha::AlgorithmImplementation()
{
    std::cout << "Running DataProcessorAlpha algorithm..." << std::endl;

    std::ifstream file(_dataManager->GetFilePath());
    std::string line;
    long numLinesRead = 0;
    while (std::getline(file, line))
    {
        numLinesRead++;
        auto index = line.find(";");
        std::string city = line.substr(0, index);
        std::string temp = line.substr(index + 1);
        AddMeasurementToCityStats(city, std::stof(temp));
    }
    std::cout << "Finished processing data. Total lines read: " << numLinesRead
              << std::endl;
}

void AlgorithmsLib::DataProcessorAlpha::AddMeasurementToCityStats(
    const std::string& city, float measurement)
{
    if (!_cityStats.contains(city))
    {
        _cityStats[city] = StatisticsAlpha();
    }
    _cityStats[city].AddMeasurement(measurement);
}
