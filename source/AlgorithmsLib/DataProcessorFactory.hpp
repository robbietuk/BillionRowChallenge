#pragma once

#include "DataManager.hpp"
#include "DataProcessor.hpp"
#include "DataProcessorAlpha.hpp"
#include <memory>
#include <tuple>
#include <type_traits>
#include <vector>

namespace AlgorithmsLib
{
class DataProcessorFactory
{
public:
    /// @brief Creates instances of all registered DataProcessor types for the
    /// given DataManager.
    /// @param dataManager Non-owning pointer to a DataManager instance.
    /// @return Vector of unique pointers to DataProcessor instances.
    static std::vector<std::unique_ptr<DataProcessor>>
    CreateAllDataProcessors(const DataManager* dataManager);

private:
    /// @brief Tuple of type identities for all registered DataProcessor types.
    /// To add a new DataProcessor implementation, add a new std::type_identity
    /// entry to this tuple.
    using RegisteredDataProcessors =
        std::tuple<std::type_identity<DataProcessorAlpha>
                   // New processors would be added here as additional
                   // std::type_identity entries
                   >;

    /// @brief Type alias for a factory function that creates a DataProcessor
    /// instance.
    using Factory = std::unique_ptr<DataProcessor> (*)(const DataManager*);

    /// @brief Creates a vector of factory functions for the registered
    /// DataProcessor types.
    /// @tparam ...TDataProcessors  Variadic template parameter pack of
    /// DataProcessor types.
    /// @param std::tuple<std::type_identity<TDataProcessors>...>  A tuple of
    /// type identities for the registered DataProcessor types.
    /// @return A vector of factory functions corresponding to the registered
    /// DataProcessor types.
    template <typename... TDataProcessors>
    static std::vector<Factory>
    CreateFactoriesFromTypes(std::tuple<std::type_identity<TDataProcessors>...>)
    {
        return {TDataProcessors::Create...};
    }
};

} // namespace AlgorithmsLib