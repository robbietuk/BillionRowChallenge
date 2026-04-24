# BillionRowChallenge

[![Build and Test (CMake Matrix)](https://github.com/robbietuk/BillionRowChallenge/actions/workflows/build-and-test.yml/badge.svg)](https://github.com/robbietuk/BillionRowChallenge/actions/workflows/build-and-test.yml)

This project is my attempt at an implementation and benchmarking of the Java Billion Row Challenge, adapted for C++.
The goal is to efficiently process and analyze a dataset containing a billion rows, focusing on performance, memory usage, and code clarity.

The Billion Row Challenge is a well-known problem in the data processing community, where the task is to read, process, and analyze a large dataset (often in CSV format) containing a billion rows.
The challenge is to do this efficiently, both in terms of speed and memory usage.
The original can be found here: https://github.com/gunnarmorling/1brc.
The record was 1.535 seconds for the entire process, which is quite impressive.

The rough structure is:
1. 1B rows of data
1. Each is constructed as: `<City>;<Temperature>
1. The city is any string.
1. The temperature is a decimal number to one decimal place, representing the average temperature in Celsius for that city.
1. Each column is separated by a semicolon (`;`), and each row is dicated by a newline (`\n`).
1. The dataset is stored in a text file (e.g., `measurements.csv`) and the full 1B rows is around 12GB in size.
1. The task is to read the file and compute the minium, maximum, and average temperature for each city, and output the results.

## Example data

```
Hamburg;12.0
Bulawayo;8.9
Palembang;38.8
St. John's;15.2
Cracow;12.6
Bridgetown;26.9
Istanbul;6.2
Roseau;34.4
Conakry;31.2
Istanbul;23.0
```

## Project Goals
- Explore algorithms and modern C++
- Improve iteratively, start simple
- Use AI for research only—focus on learning
- Build support tools: benchmarking, CI, formatting, static analysis

## Tasks outline
*This list is not complete*
- [x] Setup README and repo basics
- [x] Init CMake with HelloWorld
- [ ] Generate data file (<1B rows to start)
- [ ] Build MVP
  - [ ] File reader
  - [ ] Processing algorithm
- [ ] Build basic benchmarking tools
- [ ] Benchmark file reading (find SSD/HDD lower bound)
- [ ] Profile for bottlenecks
- [ ] Apply multithreading

## Build Instructions

1. Create a build directory:
   ```sh
   mkdir build && cd build
   ```
2. Run CMake and build:
   ```sh
   cmake ..
   cmake --build .
   ```

## Workflows
- **Clang Format Check:** Ensures code style consistency using clang-format.
- **CppCheck** A static analysis workflow to catch potential issues and enforce code quality.
- **Build and Test:** Builds the project and runs tests on every push and pull request.

## License
MIT License (add LICENSE file if needed)
