cmake_minimum_required(VERSION 4.2)
project(LibraryFree C ASM)

set(CMAKE_C_STANDARD 11)

add_subdirectory(src/slib)

add_executable(LibraryFree src/main.c)

target_link_libraries(LibraryFree PUBLIC slib)

target_include_directories(LibraryFree PUBLIC "{$PROJECT_BINARY_DIR}" "{$PROJECT_BINARY_DIR}/slib")

add_compile_options(-ffreestanding)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")
