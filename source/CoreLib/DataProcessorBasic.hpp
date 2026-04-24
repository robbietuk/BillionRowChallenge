#include "DataManager.hpp"
#include <iostream>

namespace CoreLib
{
class DataProcessorBasic
{
public:
    // Accept a non-owning pointer to DataManager. Ownership is managed
    // elsewhere.
    DataProcessorBasic(const DataManager* dataManager);

private:
    const DataManager* _dataManager; ///< Non-owning pointer, readable here
};

}; // namespace CoreLib