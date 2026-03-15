/**
 * @file test_debug.cpp
 * @brief Unit tests for ramrod::Debug (debug-level logger, blue ANSI, "[DEBUG]" tag).
 */

#include "ramrod/log/Debug.hpp"
#include "ramrod/log/Endl.hpp"
#include "ramrod/log/Writer.hpp"

#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>

#include <gtest/gtest.h>

// Verifies that Debug constructs with a Writer and header() runs without throwing.
TEST(DebugTest, ConstructionWithWriter)
{
    ramrod::Writer writer;
    ramrod::Debug debug(writer);
    EXPECT_NO_THROW(debug.header());
}

// Verifies that file_info() returns reference to the same object and stream output does not throw.
TEST(DebugTest, FileInfoAndStream)
{
    ramrod::Writer writer;
    ramrod::Debug debug(writer);
    ramrod::Base& ref{debug.file_info(__FILE__, __LINE__)};
    EXPECT_EQ(&ref, static_cast<ramrod::Base*>(&debug));
    EXPECT_NO_THROW(debug << "message");
}

// Verifies that printf() writes to the writer and returns a non-negative character count.
TEST(DebugTest, Printf)
{
    ramrod::Writer writer;
    ramrod::Debug debug(writer);
    int n{debug.printf("code %d\n", 42)};
    EXPECT_GE(n, 0);
}

// Verifies that all operator<< overloads in Debug (Base) write without throwing.
TEST(DebugTest, OperatorShiftAllOverloads)
{
    ramrod::Writer writer;
    ramrod::Debug debug(writer);
    debug.header();

    EXPECT_NO_THROW(debug << true << ramrod::endl);
    EXPECT_NO_THROW(debug << 'x' << ramrod::endl);
    EXPECT_NO_THROW(debug << static_cast<unsigned char>('y') << ramrod::endl);
    EXPECT_NO_THROW(debug << "cstr" << ramrod::endl);
    const unsigned char ustr[]{"ustr"};
    EXPECT_NO_THROW(debug << ustr << ramrod::endl << ramrod::endl);
    EXPECT_NO_THROW(debug << static_cast<short>(-1) << ramrod::endl);
    EXPECT_NO_THROW(debug << static_cast<unsigned short>(1) << ramrod::endl);
    EXPECT_NO_THROW(debug << 42 << ramrod::endl);
    EXPECT_NO_THROW(debug << 43u << ramrod::endl);
    EXPECT_NO_THROW(debug << 3.14f << ramrod::endl);
    EXPECT_NO_THROW(debug << 100L << ramrod::endl);
    EXPECT_NO_THROW(debug << 101UL << ramrod::endl);
    EXPECT_NO_THROW(debug << 2.718 << ramrod::endl);
    EXPECT_NO_THROW(debug << 3.14159L << ramrod::endl);
    EXPECT_NO_THROW(debug << -999LL << ramrod::endl);
    EXPECT_NO_THROW(debug << 999ULL << ramrod::endl);
    EXPECT_NO_THROW(debug << std::string{"std::string"} << ramrod::endl);
    EXPECT_NO_THROW(debug << std::string_view{"string_view"} << ramrod::endl);
    int obj{};
    EXPECT_NO_THROW(debug << static_cast<void*>(&obj) << ramrod::endl);
    EXPECT_NO_THROW(debug << std::runtime_error("err") << ramrod::endl);
    EXPECT_NO_THROW(debug << std::error_code(1, std::generic_category()) << ramrod::endl);
}
