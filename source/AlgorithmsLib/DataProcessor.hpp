#pragma once
#include "DataManager.hpp"
#include "Statistics.hpp"

namespace AlgorithmsLib
{
/**
 * @class DataProcessor
 * @brief Abstract base class for processing measurement data using a
 * DataManager.
 */
class DataProcessor
{
public:
    /**
     * @brief Runs the data processing algorithm.
     */
    void Run();
    virtual Statistics GetCityStatistics(std::string cityName) = 0;
    const std::string& GetAlgorithmName() const { return _algorithmName; }

protected:
    /**
     * @brief Constructs a DataProcessor with a non-owning DataManager pointer.
     * @param dataManager Non-owning pointer to a DataManager instance.
     * @param algorithmName Name of the algorithm implemented by the derived
     * class.
     */
    DataProcessor(const DataManager* dataManager, std::string algorithmName)
        : _dataManager(dataManager), _algorithmName(std::move(algorithmName))
    {
    }

    /**
     * @brief Virtual destructor for safe polymorphic use.
     */
    virtual ~DataProcessor() = default;
    const DataManager* _dataManager; ///< Non-owning pointer, readable here
    /**
     * @brief Algorithm implementation to be provided by derived classes.
     */
    virtual void AlgorithmImplementation() = 0;

private:
    std::string _algorithmName;
};
} // namespace AlgorithmsLib