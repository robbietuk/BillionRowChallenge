# BillionRowChallenge

This project is my attempt at an implementation and benchmarking of the Java Billion Row Challenge, adapted for C++. The goal is to efficiently process and analyze a dataset containing a billion rows, focusing on performance, memory usage, and code clarity.

## Project Goals
- **Algorithm Exploration:** Implement, benchmark, and compare multiple algorithms and configurations for data processing, enabling fair and reproducible performance comparisons.
- **Comprehensive Testing Suite:** Design and maintain an automated testing framework to validate correctness, performance, and scalability of all implemented algorithms under various scenarios and dataset sizes.
- **Performance Benchmarking:** Establish clear benchmarking protocols and scripts to measure speed, memory consumption, and scalability, with results documented for transparency and future reference.
- **Learning Advanced C++:** Deepen my understanding of modern C++ (including templates, concurrency, and memory management) through practical, performance-critical coding challenges.
- **Documentation and Sharing:** Provide clear documentation, code comments, and usage examples to make the project accessible for learning and further development by others.

## Features
- High-performance C++ implementation
- Benchmarking scripts and results
- Automated formatting, pre-commit, and CI workflows

## Getting Started
Instructions for building, running, and testing will be added as the project develops.

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


## Project Structure

- `source/` - Main source directory
   - `development/` - Main entry point(s) and app logic
   - `lib/` - Utility and library code
- `tests/` - Test code and CMake config
- `CMakeLists.txt` - Main CMake configuration
- `build/` - (gitignored) Build output directory

## Executables

- The main development executable is built as `build/source/development`.


## Workflows
- **Clang Format Check:** Ensures code style consistency using clang-format.
- **Pre-commit:** Runs pre-commit hooks for code quality.
- **Build and Test:** Builds the project and runs tests on every push and pull request.

## License
MIT License (add LICENSE file if needed)
