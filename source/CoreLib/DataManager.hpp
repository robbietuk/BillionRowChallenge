#pragma once

#include <string>
class DataManager
{
public:
    DataManager(std::string measurementFilePath);
    int GetFileSizeBytes();
    int GetFileSizekB();
    int GetFileSizeMB();
    int GetEstimateNumberOfRows();

private:
    const float averageRowSizeBytes = 15.7f;
    std::string measurementFilePath;
};
