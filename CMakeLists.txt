cmake_minimum_required(VERSION 3.10)

project(ArithmeticCalculator VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/calculator.cpp
)

# Add include directories
target_include_directories(${PROJECT_NAME} PRIVATE include)


# Add compiler options
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Werror
    )
endif()
