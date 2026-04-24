#include "DataManager.hpp"
#include "DataProcessor.hpp"
#include <iostream>

namespace CoreLib
{
class DataProcessorAlpha : DataProcessor
{
public:
    DataProcessorAlpha(const DataManager* dataManager);
    void Run() override;
};

}; // namespace CoreLib