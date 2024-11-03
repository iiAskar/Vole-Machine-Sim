cmake_minimum_required(VERSION 3.27)
project(vole)

set(CMAKE_CXX_STANDARD 17)

add_executable(vole main.cpp
        Memory.cpp
        Memory.h
        Register.cpp
        Register.h
        Cpu.cpp
        Cpu.h
        Machine.cpp
        Machine.h
)
