#!/bin/bash
#
# Run RamRodLog unit tests. Builds the test target if BUILD_TESTING is enabled,
# then runs the test executable directly (not via ctest).
# Usage: from project root:  ./tests/run_tests.sh [gtest_filter]
#        or from tests dir:  ./run_tests.sh [gtest_filter]
#        e.g.               ./run_tests.sh "LoggerTest.*"
#        e.g.               ./run_tests.sh --gtest_filter=LoggerTest.DefaultConstruction
#

# ::::::::::: LOG STYLIZER :::::::::::

. $(dirname "$0")/../bash/log_and_style.sh

# ::::::::: HELPER FUNCTIONS :::::::::

print_message() {
    print_yellow ">>>>>>>>>>>>>>>>>>> $1...\n\n"
}

project_name="RamRodLogTests"


print_message "Setting up project environment"
# Project root is the parent of the directory containing this script
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
BUILD_DIR="$PROJECT_ROOT/build"

cd "$PROJECT_ROOT"
check_error $? "Error changing to project root"

# Configure with tests enabled if not already configured that way
if [ ! -f "$BUILD_DIR/CMakeCache.txt" ] || ! grep -q "BUILD_TESTING:BOOL=ON" "$BUILD_DIR/CMakeCache.txt" 2>/dev/null; then
    print_message "Configuring with BUILD_TESTING=ON"
    cmake -B build -DBUILD_TESTING=ON -DCMAKE_BUILD_TYPE=Debug ${CMAKE_EXTRA_ARGS:+ $CMAKE_EXTRA_ARGS}
    check_error $? "Error configuring $project_name"
fi

print_message "Building $project_name"
cmake --build build --target $project_name
check_error $? "Error building $project_name"

print_message "Running tests"
if [ -n "$1" ]; then
    if [ "${1#--gtest_filter=}" != "$1" ]; then
        "$BUILD_DIR/tests/$project_name" "$1"
    else
        "$BUILD_DIR/tests/$project_name" --gtest_filter="$1"
    fi
else
    "$BUILD_DIR/tests/$project_name"
fi
check_error $? "Error running tests"
