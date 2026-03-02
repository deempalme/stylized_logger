#!/bin/bash

# ::::::::::: LOG STYLIZER :::::::::::

. $(dirname "$0")/bash/log_and_style.sh

# ::::::::: HELPER FUNCTIONS :::::::::

print_message() {
    print_yellow ">>>>>>>>>>>>>>>>>>> $1...\n\n"
}

project_name="RamRodLog"

# Creates the build directory just in case it does not exist
print_message "Creating directory"
mkdir -p build

# Running CMake
print_message "Configuring $project_name"
cmake -B build -DCMAKE_BUILD_TYPE:String=Debug -DCMAKE_C_COMPILER:String=/usr/bin/gcc -DCMAKE_CXX_COMPILER:String=/usr/bin/g++
check_error $? "Error configuring $project_name"

print_message "Compiling $project_name"
cd build
# Using 70% of the available cores
jobs=$(get_jobs 70)
cmake --build . --target all -j $jobs
check_error $? "Error compiling $project_name library"
