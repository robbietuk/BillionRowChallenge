/**
 * @file DataManager.hpp
 * @brief Provides file size and row estimation utilities for measurement data
 * files.
 */

#pragma once

#include <string>
namespace CoreLib
{
/**
 * @class DataManager
 * @brief Manages measurement data files and provides file statistics.
 */
class DataManager
{
public:
    /**
     * @brief Constructs a DataManager for a given measurement file.
     * @param measurementFilePath Path to the measurement data file.
     * @throws std::runtime_error if the file does not exist.
     */
    DataManager(std::string measurementFilePath);

    /**
     * @brief Gets the file size in bytes.
     * @return File size in bytes.
     */
    int GetFileSizeBytes() const;

    /**
     * @brief Gets the file size in kilobytes.
     * @return File size in kB.
     */
    int GetFileSizekB() const;

    /**
     * @brief Gets the file size in megabytes.
     * @return File size in MB.
     */
    int GetFileSizeMB() const;

    /**
     * @brief Estimates the number of rows in the file based on average row
     * size.
     * @return Estimated number of rows.
     */
    int GetEstimateNumberOfRows() const;

    void PrintFileInfo() const;

private:
    const float _averageRowSizeBytes = 15.7f; ///< Average row size in bytes
    std::string _measurementFilePath;         ///< Path to the measurement file
};
}; // namespace CoreLib