cmake_minimum_required(VERSION 3.5)
project(Hello-World-Freestanding C ASM)

# C standard
set(CMAKE_C_STANDARD 11)

# Add library subdirectory
add_subdirectory(src/slib)

# Main executable
add_executable(main src/main.c)
target_include_directories(main PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_BINARY_DIR}/slib")
target_link_libraries(main PUBLIC slib)

# Freestanding flags
target_compile_options(main PRIVATE -ffreestanding -fno-builtin)
target_link_options(main PRIVATE -nostdlib -static -no-pie -Wl,-e,_start)

# Testing
enable_testing()
add_test(NAME RunMain COMMAND main)
set_property(TEST RunMain PROPERTY PASS_REGULAR_EXPRESSION "Hello, World!")
