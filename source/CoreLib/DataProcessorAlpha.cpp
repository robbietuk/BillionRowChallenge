#include "DataProcessorAlpha.hpp"

CoreLib::DataProcessorAlpha::DataProcessorAlpha(const DataManager* dataManager)
    : DataProcessor(dataManager)
{
}
void CoreLib::DataProcessorAlpha::Run()
{
    std::cout << "DataProcessorAlpha" << std::endl;
}