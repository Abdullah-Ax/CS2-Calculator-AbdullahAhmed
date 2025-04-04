cmake_minimum_required(VERSION 3.10)
project(CS2_Calculator VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add calculator library
add_library(calculator calculator.cpp)

# Add executable
add_executable(test_calculator test.cpp)

# Link the executable with the calculator library
target_link_libraries(test_calculator calculator)

# Add include directories
target_include_directories(calculator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(test_calculator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Print status message
message(STATUS "Calculator project configured successfully")

