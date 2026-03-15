#!/bin/bash
#
# Run RamRodLog unit tests. Builds the test target if BUILD_TESTING is enabled,
# then runs the test executable directly (not via ctest).
# Usage: from project root:  ./tests/run_tests.sh
#        or from tests dir:  ./run_tests.sh
#

set -e

# Project root is the parent of the directory containing this script
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
BUILD_DIR="$PROJECT_ROOT/build"

cd "$PROJECT_ROOT"

# Configure with tests enabled if not already configured that way
if [ ! -f "$BUILD_DIR/CMakeCache.txt" ] || ! grep -q "BUILD_TESTING:BOOL=ON" "$BUILD_DIR/CMakeCache.txt" 2>/dev/null; then
    echo "Configuring with BUILD_TESTING=ON..."
    cmake -B build -DBUILD_TESTING=ON -DCMAKE_BUILD_TYPE=Debug ${CMAKE_EXTRA_ARGS:+ $CMAKE_EXTRA_ARGS}
fi

echo "Building RamRodLogTests..."
cmake --build build --target RamRodLogTests

echo "Running tests..."
exec "$BUILD_DIR/tests/RamRodLogTests"
