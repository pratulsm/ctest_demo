cmake_minimum_required(VERSION 3.14)
project(Ctest-demo VERSION 1.0.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
enable_testing()

# Set VcPkg toolchain
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")

# Find required packages
find_package(GTest CONFIG REQUIRED)
find_package(benchmark CONFIG REQUIRED)
find_package(OpenMP REQUIRED)
find_package(OpenCL REQUIRED)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(benchmarks)

# Configure CTest
set(CTEST_OUTPUT_ON_FAILURE ON)
set(CTEST_TEST_OUTPUT_XML_PATH "${CMAKE_BINARY_DIR}/test-results.xml")