
/**
 * @file DataManager.cpp
 * @brief Implements file size and row estimation utilities for measurement data
 * files.
 */

#include "DataManager.hpp"
#include <filesystem>
#include <iostream>
#include <print>

namespace CoreLib
{

/**
 * @brief Constructs a DataManager for a given measurement file.
 * @param measurementFilePath Path to the measurement data file.
 * @throws std::runtime_error if the file does not exist.
 */
DataManager::DataManager(std::string measurementFilePath)
    : _measurementFilePath(measurementFilePath)
{
    if (!std::filesystem::exists(measurementFilePath))
    {
        throw std::runtime_error("Measurement file does not exist: " +
                                 measurementFilePath);
    }
}

/**
 * @brief Gets the file size in bytes.
 * @return File size in bytes.
 */
int DataManager::GetFileSizeBytes() const
{
    return std::filesystem::file_size(_measurementFilePath);
}

/**
 * @brief Gets the file size in kilobytes.
 * @return File size in kB.
 */
int DataManager::GetFileSizekB() const { return GetFileSizeBytes() / 1024; }

/**
 * @brief Gets the file size in megabytes.
 * @return File size in MB.
 */
int DataManager::GetFileSizeMB() const { return GetFileSizekB() / 1024; }

/**
 * @brief Estimates the number of rows in the file based on average row size.
 * @return Estimated number of rows.
 */
int DataManager::GetEstimateNumberOfRows() const
{
    return GetFileSizeBytes() / _averageRowSizeBytes;
}

void DataManager::PrintFileInfo() const
{
    std::cout << "File size (MB): " << GetFileSizeMB() << std::endl;
    std::cout << "Estimated number of rows: " << GetEstimateNumberOfRows()
              << std::endl;
}

}; // namespace CoreLib