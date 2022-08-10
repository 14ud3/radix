cmake_minimum_required(VERSION 3.19)
project(radix)

set(CMAKE_CXX_STANDARD 17)
include_directories(${PROJECT_SOURCE_DIR}/module/triemplate)

add_subdirectory("module/triemplate")
add_executable(radix
        include/Parameters.h
        src/radix.cpp
        test/test.cpp)
