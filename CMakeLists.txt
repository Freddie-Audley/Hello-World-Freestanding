cmake_minimum_required(VERSION 3.5)
project(Hello-World-Freestanding C ASM)

set(CMAKE_C_STANDARD 11)

add_subdirectory(src/slib)

add_executable(Hello-World-Freestanding src/main.c)

target_link_libraries(Hello-World-Freestanding PUBLIC slib)

target_include_directories(Hello-World-Freestanding PUBLIC "{$PROJECT_BINARY_DIR}" "{$PROJECT_BINARY_DIR}/slib")

add_compile_options(-ffreestanding)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")

enable_testing()

add_test(NAME RunMain
        COMMAND Hello-World-Freestanding
)

set (passRegex "Hello, World!")

set_property(TEST RunMain
        PROPERTY PASS_REGULAR_EXPRESSION "${passRegex}"
)
