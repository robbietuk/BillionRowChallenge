#include "DataProcessorFactory.hpp"
#include <array>
#include <memory>
#include <vector>
namespace AlgorithmsLib
{

std::vector<std::unique_ptr<AlgorithmsLib::DataProcessor>>
DataProcessorFactory::CreateAllDataProcessors(const DataManager* dataManager)
{
    const std::vector<Factory> factories =
        CreateFactoriesFromTypes(RegisteredDataProcessors{});

    std::vector<std::unique_ptr<DataProcessor>> processors;
    processors.reserve(factories.size());
    for (const auto factory : factories)
    {
        processors.push_back(factory(dataManager));
    }
    return processors;
}
} // namespace AlgorithmsLib
