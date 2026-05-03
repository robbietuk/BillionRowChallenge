#pragma once
#include "DataManager.hpp"
#include "Statistics.hpp"
#include <memory>
#include <vector>

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

    virtual ~DataProcessor() = default;

    /// @brief Creates a new instance of a DataProcessor-derived class for the
    /// given DataManager.
    /// @param dataManager Non-owning pointer to a DataManager instance.
    /// @return Unique pointer to a new DataProcessor instance.
    static std::unique_ptr<DataProcessor> Create(const DataManager* dataManager)
    {
        throw std::runtime_error(
            "Create() not implemented for base DataProcessor class");
    }

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
    const DataManager* _dataManager; ///< Non-owning pointer, readable here
    /**
     * @brief Algorithm implementation to be provided by derived classes.
     */
    virtual void AlgorithmImplementation() = 0;

private:
    std::string _algorithmName;
};

} // namespace AlgorithmsLib