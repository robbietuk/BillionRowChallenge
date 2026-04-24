

/**
 * @file main.cpp
 * @brief Entry point for the weather measurement data generator.
 *
 * This program generates a specified number of random weather measurements
 * using the MeasurementGenerator class. It supports options for custom station
 * file, output directory, and an overwrite flag.
 */

#include "MeasurementGenerator.hpp"
#include <filesystem>
#include <iostream>

/**
 * @brief Main entry point for the measurement generator program.
 *
 * Usage:
 *   ./GenerateData <num_records> [station_file] [output_dir] [--overwrite]
 *
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return 0 on success, nonzero on error.
 */
int main(int argc, char* argv[])
{
    // Parse command-line arguments
    if (argc < 2)
    {
        std::cerr
            << "Usage: " << argv[0]
            << " <num_records> [station_file] [output_dir] [--overwrite]\n";
        return 1;
    }
    size_t num_records = std::stoull(argv[1]);
    std::string station_file = (argc >= 3) ? argv[2] : "weather_stations.csv";
    std::string output_dir = (argc >= 4) ? argv[3] : "./data";
    bool overwrite = false;
    for (int i = 1; i < argc; ++i)
    {
        if (std::string(argv[i]) == "--overwrite")
        {
            overwrite = true;
        }
    }
    std::string out_file = output_dir + "/measurements.txt";
    // Check for existing output file unless overwrite is specified
    if (!overwrite && std::filesystem::exists(out_file))
    {
        std::cerr << "Output file '" << out_file
                  << "' already exists. Use --overwrite to overwrite.\n";
        return 2;
    }
    // Generate measurements
    Generator::MeasurementGenerator generator(station_file, output_dir);
    int result = generator.Run(num_records);
    if (result != 0)
    {
        std::cerr << "Failed to generate measurements.\n";
        return result;
    }
    return 0;
}