project("pico4fun" C CXX ASM)
cmake_minimum_required(VERSION 3.13)

# Pull in Pico SDK
include(pico_sdk_import.cmake)
pico_sdk_init()

add_subdirectory(sensor)
add_subdirectory(pio)