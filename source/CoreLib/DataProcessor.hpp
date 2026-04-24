#pragma once

#include "DataManager.hpp"

namespace CoreLib
{
class DataProcessor
{
public:
    virtual void Run() = 0;

protected:
    DataProcessor(const DataManager* dataManager);
    virtual ~DataProcessor() = default; // virtual destructor
    const DataManager* _dataManager;    ///< Non-owning pointer, readable here
};
}; // namespace CoreLib