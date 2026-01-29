cmake_minimum_required(VERSION 3.5)
project(Hello-World-Freestanding C ASM)

# C standard
set(CMAKE_C_STANDARD 11)

# Default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Add library subdirectory
add_subdirectory(src/slib)

# Main executable
add_executable(main src/main.c)
target_include_directories(main PUBLIC "{$PROJECT_BINARY_DIR}" "{$PROJECT_BINARY_DIR}/slib")
target_link_libraries(main PUBLIC slib)

# Freestanding flags
target_compile_options(main PRIVATE -ffreestanding -nostdlib)
set_target_properties(main PROPERTIES LINK_FLAGS "-nostdlib")

# Testing
enable_testing()
add_test(NAME RunMain COMMAND main)
set_property(TEST RunMain PROPERTY PASS_REGULAR_EXPRESSION "Hello, World!")
