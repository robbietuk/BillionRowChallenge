
/**
 * @class MeasurementGenerator
 * @brief Generates random weather measurements and writes them to a file.
 *
 * This class reads weather station names from a CSV file and generates a
 * specified number of random temperature measurements, writing them to an
 * output file.
 */
class MeasurementGenerator
{
public:
    /**
     * @brief Constructs a MeasurementGenerator.
     * @param station_file Path to the weather station CSV file.
     * @param output_dir Directory where the output file will be written.
     */
    MeasurementGenerator(const std::string& station_file,
                         const std::string& output_dir);

    /**
     * @brief Generates and writes random measurements.
     * @param num_records Number of measurement records to generate.
     * @return 0 on success, nonzero on error.
     */
    int Run(size_t num_records);

    /**
     * @brief Reads weather station names from a CSV file.
     * @param filename Path to the CSV file.
     * @return Vector of station names.
     */
    static std::vector<std::string>
    ReadStationNames(const std::string& filename);

    /**
     * @brief Converts a byte count to a human-readable string.
     * @param bytes Number of bytes.
     * @return Human-readable string (e.g., "1.2 MiB").
     */
    static std::string HumanReadableBytes(size_t bytes);

    /**
     * @brief Prints a progress bar to stdout.
     * @param current Current progress value.
     * @param total Total value for completion.
     */
    static void PrintProgress(size_t current, size_t total);

private:
    std::string _stationFile; ///< Path to the weather station CSV file
    std::string _outputDir;   ///< Output directory for the measurements file
    std::vector<std::string> _stationNames; ///< Cached station names
};
