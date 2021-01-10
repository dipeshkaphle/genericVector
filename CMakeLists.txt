cmake_minimum_required(VERSION "3.19.2")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(genericVector)

set(CMAKE_C_FLAGS "-Wall ")

add_subdirectory(src)

add_executable(main main.c)

target_link_libraries(main PUBLIC genericVector)

target_include_directories(genericVector PUBLIC "" "src")
