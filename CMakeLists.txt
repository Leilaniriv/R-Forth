cmake_minimum_required(VERSION 3.14)
project(R_FORTH VERSION 1.0)

# Enable testing
enable_testing()

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

# Add executables
add_executable(int_stack_demo
        int_stack_demo.c
        int_stack.c)

# Add main executable
add_executable(main
        main.c
        token.c)