
#include "DataManager.hpp"
#include <filesystem>
#include <iostream>
#include <print>

namespace CoreLib
{
DataManager::DataManager(std::string measurementFilePath)
    : measurementFilePath(measurementFilePath)
{
    if (!std::filesystem::exists(measurementFilePath))
    {
        throw std::runtime_error("Measurement file does not exist: " +
                                 measurementFilePath);
    }
}

int DataManager::GetFileSizeBytes()
{
    return std::filesystem::file_size(measurementFilePath);
}

int DataManager::GetFileSizekB() { return GetFileSizeBytes() / 1024; }

int DataManager::GetFileSizeMB() { return GetFileSizekB() / 1024; }

int DataManager::GetEstimateNumberOfRows()
{
    return GetFileSizeBytes() / averageRowSizeBytes;
}
}; // namespace CoreLib