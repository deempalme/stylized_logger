/**
 * @file test_verbose.cpp
 * @brief Unit tests for ramrod::Verbose (verbose-level logger, default color, "[VERBOSE]" tag).
 */

#include "ramrod/log/Endl.hpp"
#include "ramrod/log/Verbose.hpp"
#include "ramrod/log/Writer.hpp"

#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>

#include <gtest/gtest.h>

// Verifies that Verbose constructs with a Writer and header() runs without throwing.
TEST(VerboseTest, ConstructionWithWriter)
{
    ramrod::Writer writer;
    ramrod::Verbose verbose(writer);
    EXPECT_NO_THROW(verbose.header());
}

// Verifies that file_info() returns reference to the same object and stream output does not throw.
TEST(VerboseTest, FileInfoAndStream)
{
    ramrod::Writer writer;
    ramrod::Verbose verbose(writer);
    ramrod::Base& ref{verbose.file_info(__FILE__, __LINE__)};
    EXPECT_EQ(&ref, static_cast<ramrod::Base*>(&verbose));
    EXPECT_NO_THROW(verbose << "verbose message");
}

// Verifies that printf() writes to the writer and returns a non-negative character count.
TEST(VerboseTest, Printf)
{
    ramrod::Writer writer;
    ramrod::Verbose verbose(writer);
    int n{verbose.printf("verbose %d\n", 0)};
    EXPECT_GE(n, 0);
}

// Verifies that all operator<< overloads in Verbose (Base) write without throwing.
TEST(VerboseTest, OperatorShiftAllOverloads)
{
    ramrod::Writer writer;
    ramrod::Verbose verbose(writer);
    verbose.header();

    EXPECT_NO_THROW(verbose << true << ramrod::endl);
    EXPECT_NO_THROW(verbose << 'x' << ramrod::endl);
    EXPECT_NO_THROW(verbose << static_cast<unsigned char>('y') << ramrod::endl);
    EXPECT_NO_THROW(verbose << "cstr" << ramrod::endl);
    const unsigned char ustr[]{"ustr"};
    EXPECT_NO_THROW(verbose << ustr << ramrod::endl << ramrod::endl);
    EXPECT_NO_THROW(verbose << static_cast<short>(-1) << ramrod::endl);
    EXPECT_NO_THROW(verbose << static_cast<unsigned short>(1) << ramrod::endl);
    EXPECT_NO_THROW(verbose << 42 << ramrod::endl);
    EXPECT_NO_THROW(verbose << 43u << ramrod::endl);
    EXPECT_NO_THROW(verbose << 3.14f << ramrod::endl);
    EXPECT_NO_THROW(verbose << 100L << ramrod::endl);
    EXPECT_NO_THROW(verbose << 101UL << ramrod::endl);
    EXPECT_NO_THROW(verbose << 2.718 << ramrod::endl);
    EXPECT_NO_THROW(verbose << 3.14159L << ramrod::endl);
    EXPECT_NO_THROW(verbose << -999LL << ramrod::endl);
    EXPECT_NO_THROW(verbose << 999ULL << ramrod::endl);
    EXPECT_NO_THROW(verbose << std::string{"std::string"} << ramrod::endl);
    EXPECT_NO_THROW(verbose << std::string_view{"string_view"} << ramrod::endl);
    int obj{};
    EXPECT_NO_THROW(verbose << static_cast<void*>(&obj) << ramrod::endl);
    EXPECT_NO_THROW(verbose << std::runtime_error("err") << ramrod::endl);
    EXPECT_NO_THROW(verbose << std::error_code(1, std::generic_category()) << ramrod::endl);
}
