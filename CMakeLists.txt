cmake_minimum_required(VERSION "3.19.2")

project(genericVector)

set(CMAKE_C_FLAGS "-Wall ")

add_subdirectory(src)

add_executable(main main.c)

target_link_libraries(main PUBLIC genericVector)

target_include_directories(genericVector PUBLIC "$(PROJECT_BINARY_DIR)"
                                                "$(PROJECT_SOURCE_DIR)/src")
