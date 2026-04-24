// create_measurements.cpp
// Generates random weather measurements, similar to the Python script
// Usage: ./create_measurements <num_records>

#include "MeasurementGenerator.hpp"
#include <chrono>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

/**
 * @brief Constructs a MeasurementGenerator and loads station names.
 * @param station_file Path to the weather station CSV file.
 * @param output_dir Directory where the output file will be written.
 */
MeasurementGenerator::MeasurementGenerator(const std::string& station_file,
                                           const std::string& output_dir)
    : _stationFile(station_file), _outputDir(output_dir)
{
    _stationNames = ReadStationNames(_stationFile);
}

/**
 * @brief Reads weather station names from a CSV file.
 * @param filename Path to the CSV file.
 * @return Vector of station names.
 */
std::vector<std::string>
MeasurementGenerator::ReadStationNames(const std::string& filename)
{
    std::vector<std::string> names;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty() || line[0] == '#')
            continue;
        auto pos = line.find(';');
        if (pos != std::string::npos)
        {
            names.push_back(line.substr(0, pos));
        }
    }
    return names;
}

/**
 * @brief Converts a byte count to a human-readable string.
 * @param bytes Number of bytes.
 * @return Human-readable string (e.g., "1.2 MiB").
 */
std::string MeasurementGenerator::HumanReadableBytes(size_t bytes)
{
    const char* sizes[] = {"bytes", "KiB", "MiB", "GiB"};
    int order = 0;
    double num = bytes;
    while (num >= 1024 && order < 3)
    {
        order++;
        num /= 1024;
    }
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << num << " " << sizes[order];
    return oss.str();
}

/**
 * @brief Prints a progress bar to stdout.
 * @param current Current progress value.
 * @param total Total value for completion.
 */
void MeasurementGenerator::PrintProgress(size_t current, size_t total)
{
    int percent = static_cast<int>(100.0 * current / total);
    int bars = percent / 2;
    std::cout << "\r[" << std::string(bars, '=') << std::string(50 - bars, ' ')
              << "] " << percent << "%" << std::flush;
}

/**
 * @brief Generates and writes random measurements to the output file.
 *
 * This method generates the specified number of random temperature measurements
 * for weather stations and writes them to a file in the output directory.
 *
 * @param num_records Number of measurement records to generate.
 * @return 0 on success, nonzero on error.
 */
int MeasurementGenerator::Run(size_t num_records)
{
    if (_stationNames.empty())
    {
        std::cerr << "No station names found in " << _stationFile << "\n";
        return 1;
    }

    // Estimate file size
    double avg_name_len = 0;
    for (const auto& s : _stationNames)
        avg_name_len += s.size();
    avg_name_len /= _stationNames.size();
    double avg_temp_len = 4.4; // as in Python
    double avg_line_len = avg_name_len + avg_temp_len + 2;
    std::cout << "Estimated max file size is:  "
              << HumanReadableBytes(
                     static_cast<size_t>(num_records * avg_line_len))
              << "\n";

    // Prepare output directory
    fs::path out_dir = fs::path(_outputDir);
    if (!fs::exists(out_dir))
    {
        fs::create_directories(out_dir);
    }
    fs::path out_file = out_dir / "measurements.txt";
    std::ofstream out(out_file);
    if (!out)
    {
        std::cerr << "Failed to open output file: " << out_file << "\n";
        return 1;
    }

    std::mt19937_64 rng(std::random_device{}());
    std::uniform_int_distribution<size_t> station_dist(0, _stationNames.size() -
                                                              1);
    std::uniform_real_distribution<double> temp_dist(-99.9, 99.9);

    const size_t batch_size = 10000;
    size_t chunks = num_records / batch_size;
    size_t remainder = num_records % batch_size;
    auto start = std::chrono::steady_clock::now();
    std::cout << "Building test data...\n";
    for (size_t chunk = 0; chunk < chunks; ++chunk)
    {
        for (size_t i = 0; i < batch_size; ++i)
        {
            const auto& station = _stationNames[station_dist(rng)];
            double temp = temp_dist(rng);
            out << station << ";" << std::fixed << std::setprecision(1) << temp
                << "\n";
        }
        if ((chunk + 1) * 100 / chunks > chunk * 100 / chunks)
        {
            PrintProgress(chunk + 1, chunks);
        }
    }
    for (size_t i = 0; i < remainder; ++i)
    {
        const auto& station = _stationNames[station_dist(rng)];
        double temp = temp_dist(rng);
        out << station << ";" << std::fixed << std::setprecision(1) << temp
            << "\n";
    }
    out.close();
    std::cout << "\n";
    auto end = std::chrono::steady_clock::now();
    auto elapsed =
        std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
    auto file_size = fs::file_size(out_file);
    std::cout << "Test data successfully written to " << out_file << "\n";
    std::cout << "Actual file size:  " << HumanReadableBytes(file_size) << "\n";
    std::cout << "Elapsed time: " << elapsed << " seconds\n";
    std::cout << "Test data build complete." << std::endl;
    return 0;
}
