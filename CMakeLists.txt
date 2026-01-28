cmake_minimum_required(VERSION 1.0)
project(Hello-World-Freestanding C ASM)

set(CMAKE_C_STANDARD 11)

add_subdirectory(src/slib)

add_executable(Hello-World-Freestanding src/main.c)

target_link_libraries(Hello-World-Freestanding PUBLIC slib)

target_include_directories(Hello-World-Freestanding PUBLIC "{$PROJECT_BINARY_DIR}" "{$PROJECT_BINARY_DIR}/slib")

add_compile_options(-ffreestanding)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")

add_test(NAME RunMain COMMAND main)
