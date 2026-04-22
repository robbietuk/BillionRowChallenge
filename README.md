# BillionRowChallenge

This project is my attempt at an implementation and benchmarking of the Java Billion Row Challenge, adapted for C++. The goal is to efficiently process and analyze a dataset containing a billion rows, focusing on performance, memory usage, and code clarity.

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
