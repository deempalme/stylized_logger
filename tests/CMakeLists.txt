cmake_minimum_required(VERSION 3.22)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.14.0
)
set(GTEST_USE_OWN_MOCK_REFERENCE  OFF CACHE BOOL "" FORCE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(RamRodLogTests
    test_base.cpp
    test_debug.cpp
    test_error.cpp
    test_file.cpp
    test_info.cpp
    test_logger.cpp
    test_verbose.cpp
    test_warning.cpp
    test_writer.cpp
    test_writer_cerr.cpp
    test_writer_file.cpp
    test_writer_file_cerr.cpp
    test_writer_file_cout.cpp
)

target_link_libraries(RamRodLogTests
    PRIVATE
        GTest::gtest_main
        RamRodLog
)

target_include_directories(RamRodLogTests
    PRIVATE
        ${RamRodLog_INCLUDE_DIRS}
)

set_target_properties(RamRodLogTests
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED TRUE
        CXX_EXTENSIONS FALSE
)

include(GoogleTest)
# Use add_test instead of gtest_discover_tests so the executable is not run at build time
# (avoids build failure when the test binary crashes during discovery).
add_test(NAME RamRodLogTests COMMAND RamRodLogTests)
