/**
 * @file test_info.cpp
 * @brief Unit tests for ramrod::Info (info-level logger, green ANSI, "[INFO]" tag).
 */

#include "ramrod/log/Endl.hpp"
#include "ramrod/log/Info.hpp"
#include "ramrod/log/Writer.hpp"

#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>

#include <gtest/gtest.h>

// Verifies that Info constructs with a Writer and header() runs without throwing.
TEST(InfoTest, ConstructionWithWriter)
{
    ramrod::Writer writer;
    ramrod::Info info(writer);
    EXPECT_NO_THROW(info.header());
}

// Verifies that file_info() returns reference to the same object and stream output does not throw.
TEST(InfoTest, FileInfoAndStream)
{
    ramrod::Writer writer;
    ramrod::Info info(writer);
    ramrod::Base& ref{info.file_info(__FILE__, __LINE__)};
    EXPECT_EQ(&ref, static_cast<ramrod::Base*>(&info));
    EXPECT_NO_THROW(info << "info message");
}

// Verifies that printf() writes to the writer and returns a non-negative character count.
TEST(InfoTest, Printf)
{
    ramrod::Writer writer;
    ramrod::Info info(writer);
    int n{info.printf("value %d\n", 100)};
    EXPECT_GE(n, 0);
}

// Verifies that all operator<< overloads in Info (Base) write without throwing.
TEST(InfoTest, OperatorShiftAllOverloads)
{
    ramrod::Writer writer;
    ramrod::Info info(writer);
    info.header();

    EXPECT_NO_THROW(info << true << ramrod::endl);
    EXPECT_NO_THROW(info << 'x' << ramrod::endl);
    EXPECT_NO_THROW(info << static_cast<unsigned char>('y') << ramrod::endl);
    EXPECT_NO_THROW(info << "cstr" << ramrod::endl);
    const unsigned char ustr[]{"ustr"};
    EXPECT_NO_THROW(info << ustr << ramrod::endl << ramrod::endl);
    EXPECT_NO_THROW(info << static_cast<short>(-1) << ramrod::endl);
    EXPECT_NO_THROW(info << static_cast<unsigned short>(1) << ramrod::endl);
    EXPECT_NO_THROW(info << 42 << ramrod::endl);
    EXPECT_NO_THROW(info << 43u << ramrod::endl);
    EXPECT_NO_THROW(info << 3.14f << ramrod::endl);
    EXPECT_NO_THROW(info << 100L << ramrod::endl);
    EXPECT_NO_THROW(info << 101UL << ramrod::endl);
    EXPECT_NO_THROW(info << 2.718 << ramrod::endl);
    EXPECT_NO_THROW(info << 3.14159L << ramrod::endl);
    EXPECT_NO_THROW(info << -999LL << ramrod::endl);
    EXPECT_NO_THROW(info << 999ULL << ramrod::endl);
    EXPECT_NO_THROW(info << std::string{"std::string"} << ramrod::endl);
    EXPECT_NO_THROW(info << std::string_view{"string_view"} << ramrod::endl);
    int obj{};
    EXPECT_NO_THROW(info << static_cast<void*>(&obj) << ramrod::endl);
    EXPECT_NO_THROW(info << std::runtime_error("err") << ramrod::endl);
    EXPECT_NO_THROW(info << std::error_code(1, std::generic_category()) << ramrod::endl);
}
