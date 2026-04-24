#pragma once
#include "DataManager.hpp"

namespace CoreLib
{
/**
 * @class DataProcessor
 * @brief Abstract base class for processing measurement data using a DataManager.
 */
class DataProcessor
{
public:
    /**
     * @brief Runs the data processing algorithm.
     */
    void Run();

protected:
    /**
     * @brief Constructs a DataProcessor with a non-owning DataManager pointer.
     * @param dataManager Non-owning pointer to a DataManager instance.
     */
    DataProcessor(const DataManager* dataManager);
    /**
     * @brief Virtual destructor for safe polymorphic use.
     */
    virtual ~DataProcessor() = default;
    const DataManager* _dataManager;    ///< Non-owning pointer, readable here
    /**
     * @brief Algorithm implementation to be provided by derived classes.
     */
    virtual void AlgorithmImplementation() = 0;
};
} // namespace CoreLib