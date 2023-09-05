cmake_minimum_required(VERSION 3.12)

# Define your project
project(Blackbird VERSION 1.0)

# Set C++17 as the standard for the entire project
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the blackbird library
add_library(blackbird INTERFACE)
target_include_directories(blackbird INTERFACE .)

# Add the "test_dir" subdirectory
add_subdirectory(test)
