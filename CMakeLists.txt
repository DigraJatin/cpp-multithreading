cmake_minimum_required(VERSION 3.10)
project(MultithreadingExamples)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "easy/*.cpp" "medium/*.cpp" "hard/*.cpp")

foreach(source_file ${SOURCES})
    get_filename_component(exe_name ${source_file} NAME_WE)
    string(REPLACE "/" "_" exe_name ${exe_name})
    add_executable(${exe_name} ${source_file})
endforeach()
