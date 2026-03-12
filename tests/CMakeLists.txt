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
    test_output.cpp
    test_logger.cpp
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
gtest_discover_tests(RamRodLogTests)
