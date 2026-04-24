#include <filesystem>
#include <iostream>

#include "util.hpp"
#include <DataManager.hpp>

/**
 * @brief Holds application configuration options.
 *
 * Encapsulates configuration data for the BillionRowChallengeApp,
 * including parsing command-line arguments and printing configuration details.
 */
struct AppConfiguration
{
    /**
     * @brief Constructs the configuration with the given measurement file path.
     * @param measurementFile Path to the measurements file.
     */
    AppConfiguration(const std::string& measurementFile)
        : measurementFile(measurementFile)
    {
    }

public:
    /**
     * @brief Path to the measurements file.
     */
    const std::string measurementFile;

    /**
     * @brief Parses command-line arguments to create an AppConfiguration.
     * @param argc Argument count from main().
     * @param argv Argument vector from main().
     * @return AppConfiguration instance with parsed values.
     * @throws std::runtime_error if arguments are invalid.
     */
    static AppConfiguration ParseArgs(int argc, char* argv[])
    {
        if (argc < 2)
        {
            throw std::runtime_error("Usage: " + std::string(argv[0]) +
                                     " <measurement_file>");
        }
        return AppConfiguration(argv[1]);
    }

    /**
     * @brief Prints the configuration details to standard output.
     */
    void Print() const
    {
        std::string msg = "BillionRowChallengeApp Configuration:\n";
        msg += "  Measurements file: " + measurementFile + "\n";
        msg += "  Exists: " +
               std::string(std::filesystem::exists(measurementFile) ? "Yes"
                                                                    : "No") +
               "\n";
        std::cout << msg;
    }
};

int main(int argc, char* argv[])
{
    std::cout << "Hello, CMake!" << std::endl;
    CoreLib::foo();

    AppConfiguration config = AppConfiguration::ParseArgs(argc, argv);
    config.Print();

    try
    {
        CoreLib::DataManager dataManager(config.measurementFile);
        std::cout << "File size (MB): " << dataManager.GetFileSizeMB()
                  << std::endl;
        std::cout << "Estimated number of rows: "
                  << dataManager.GetEstimateNumberOfRows() << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
