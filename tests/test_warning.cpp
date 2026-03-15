/**
 * @file test_warning.cpp
 * @brief Unit tests for ramrod::Warning (warning-level logger, yellow ANSI, "[WARNING]" tag).
 */

#include "ramrod/log/Endl.hpp"
#include "ramrod/log/Warning.hpp"
#include "ramrod/log/Writer.hpp"

#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>

#include <gtest/gtest.h>

// Verifies that Warning constructs with a Writer and header() runs without throwing.
TEST(WarningTest, ConstructionWithWriter)
{
    ramrod::Writer writer;
    ramrod::Warning warning(writer);
    EXPECT_NO_THROW(warning.header());
}

// Verifies that file_info() returns reference to the same object and stream output does not throw.
TEST(WarningTest, FileInfoAndStream)
{
    ramrod::Writer writer;
    ramrod::Warning warning(writer);
    ramrod::Base& ref{warning.file_info(__FILE__, __LINE__)};
    EXPECT_EQ(&ref, static_cast<ramrod::Base*>(&warning));
    EXPECT_NO_THROW(warning << "warning message");
}

// Verifies that printf() writes to the writer and returns a non-negative character count.
TEST(WarningTest, Printf)
{
    ramrod::Writer writer;
    ramrod::Warning warning(writer);
    int n{warning.printf("warn %d\n", 1)};
    EXPECT_GE(n, 0);
}

// Verifies that all operator<< overloads in Warning (Base) write without throwing.
TEST(WarningTest, OperatorShiftAllOverloads)
{
    ramrod::Writer writer;
    ramrod::Warning warning(writer);
    warning.header();

    EXPECT_NO_THROW(warning << true << ramrod::endl);
    EXPECT_NO_THROW(warning << 'x' << ramrod::endl);
    EXPECT_NO_THROW(warning << static_cast<unsigned char>('y') << ramrod::endl);
    EXPECT_NO_THROW(warning << "cstr" << ramrod::endl);
    const unsigned char ustr[]{"ustr"};
    EXPECT_NO_THROW(warning << ustr << ramrod::endl << ramrod::endl);
    EXPECT_NO_THROW(warning << static_cast<short>(-1) << ramrod::endl);
    EXPECT_NO_THROW(warning << static_cast<unsigned short>(1) << ramrod::endl);
    EXPECT_NO_THROW(warning << 42 << ramrod::endl);
    EXPECT_NO_THROW(warning << 43u << ramrod::endl);
    EXPECT_NO_THROW(warning << 3.14f << ramrod::endl);
    EXPECT_NO_THROW(warning << 100L << ramrod::endl);
    EXPECT_NO_THROW(warning << 101UL << ramrod::endl);
    EXPECT_NO_THROW(warning << 2.718 << ramrod::endl);
    EXPECT_NO_THROW(warning << 3.14159L << ramrod::endl);
    EXPECT_NO_THROW(warning << -999LL << ramrod::endl);
    EXPECT_NO_THROW(warning << 999ULL << ramrod::endl);
    EXPECT_NO_THROW(warning << std::string{"std::string"} << ramrod::endl);
    EXPECT_NO_THROW(warning << std::string_view{"string_view"} << ramrod::endl);
    int obj{};
    EXPECT_NO_THROW(warning << static_cast<void*>(&obj) << ramrod::endl);
    EXPECT_NO_THROW(warning << std::runtime_error("err") << ramrod::endl);
    EXPECT_NO_THROW(warning << std::error_code(1, std::generic_category()) << ramrod::endl);
}
