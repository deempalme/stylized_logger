/**
 * @file test_error.cpp
 * @brief Unit tests for ramrod::Error (error-level logger, red ANSI, "[ERROR]" tag).
 */

#include "ramrod/log/Endl.hpp"
#include "ramrod/log/Error.hpp"
#include "ramrod/log/WriterCerr.hpp"

#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>

#include <gtest/gtest.h>

// Verifies that Error constructs with WriterCerr and header() runs without throwing.
TEST(ErrorTest, ConstructionWithWriterCerr)
{
    ramrod::WriterCerr writer;
    ramrod::Error error(writer);
    EXPECT_NO_THROW(error.header());
}

// Verifies that file_info() returns reference to the same object and stream output does not throw.
TEST(ErrorTest, FileInfoAndStream)
{
    ramrod::WriterCerr writer;
    ramrod::Error error(writer);
    ramrod::Base& ref{error.file_info(__FILE__, __LINE__)};
    EXPECT_EQ(&ref, static_cast<ramrod::Base*>(&error));
    EXPECT_NO_THROW(error << "error message");
}

// Verifies that printf() writes to the writer and returns a non-negative character count.
TEST(ErrorTest, Printf)
{
    ramrod::WriterCerr writer;
    ramrod::Error error(writer);
    int n{error.printf("err %d\n", 1)};
    EXPECT_GE(n, 0);
}

// Verifies that all operator<< overloads in Error (Base) write without throwing.
TEST(ErrorTest, OperatorShiftAllOverloads)
{
    ramrod::WriterCerr writer;
    ramrod::Error error(writer);
    error.header();

    EXPECT_NO_THROW(error << true << ramrod::endl);
    EXPECT_NO_THROW(error << 'x' << ramrod::endl);
    EXPECT_NO_THROW(error << static_cast<unsigned char>('y') << ramrod::endl);
    EXPECT_NO_THROW(error << "cstr" << ramrod::endl);
    const unsigned char ustr[]{"ustr"};
    EXPECT_NO_THROW(error << ustr << ramrod::endl << ramrod::endl);
    EXPECT_NO_THROW(error << static_cast<short>(-1) << ramrod::endl);
    EXPECT_NO_THROW(error << static_cast<unsigned short>(1) << ramrod::endl);
    EXPECT_NO_THROW(error << 42 << ramrod::endl);
    EXPECT_NO_THROW(error << 43u << ramrod::endl);
    EXPECT_NO_THROW(error << 3.14f << ramrod::endl);
    EXPECT_NO_THROW(error << 100L << ramrod::endl);
    EXPECT_NO_THROW(error << 101UL << ramrod::endl);
    EXPECT_NO_THROW(error << 2.718 << ramrod::endl);
    EXPECT_NO_THROW(error << 3.14159L << ramrod::endl);
    EXPECT_NO_THROW(error << -999LL << ramrod::endl);
    EXPECT_NO_THROW(error << 999ULL << ramrod::endl);
    EXPECT_NO_THROW(error << std::string{"std::string"} << ramrod::endl);
    EXPECT_NO_THROW(error << std::string_view{"string_view"} << ramrod::endl);
    int obj{};
    EXPECT_NO_THROW(error << static_cast<void*>(&obj) << ramrod::endl);
    EXPECT_NO_THROW(error << std::runtime_error("err") << ramrod::endl);
    EXPECT_NO_THROW(error << std::error_code(1, std::generic_category()) << ramrod::endl);
}
