cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(HelloWorld C CXX)

set(CMAKE_CXX_FLAGS "-g -O0  -std=c++11 -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS "-g -O0  -W -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

find_package(PkgConfig)

if(CMAKE_COMPILER_IS_GNUCC)
    add_definitions( -Werror)
endif(CMAKE_COMPILER_IS_GNUCC)

add_subdirectory(mashup)


