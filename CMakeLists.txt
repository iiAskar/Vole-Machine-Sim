cmake_minimum_required(VERSION 3.27)
project(Vole_Machine_Language_Simulator_main)

set(CMAKE_CXX_STANDARD 17)

# Include directories for header files
include_directories(C:/Users/askar/Downloads/Vole-Machine-Language-Simulator-main/Vole-Machine-Language-Simulator-main/)

# List all the source and header files
set(SOURCE_FILES
        main.cpp
        Machine.cpp
        Machine.h
        Memory.cpp
        Memory.h
        Register.cpp
        Register.h
)

# Create the executable with all source files
add_executable(Vole_Machine_Language_Simulator_main ${SOURCE_FILES})
