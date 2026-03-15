/**
 * @file test_base.cpp
 * @brief Unit tests for ramrod::Base (level-agnostic logger with header and stream API).
 */

#include "ramrod/log/Base.hpp"
#include "ramrod/log/Endl.hpp"
#include "ramrod/log/Writer.hpp"

#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>

#include <gtest/gtest.h>

// Verifies that Base constructs with a Writer and header() can be called without throwing.
TEST(BaseTest, ConstructionWithWriter)
{
    ramrod::Writer writer;
    ramrod::Base base(writer);
    EXPECT_NO_THROW(base.header());
}

// Verifies that file_info() returns a reference to this Base instance.
TEST(BaseTest, FileInfoReturnsReference)
{
    ramrod::Writer writer;
    ramrod::Base base(writer);
    ramrod::Base& ref{base.file_info(__FILE__, __LINE__)};
    EXPECT_EQ(&ref, &base);
}

// Verifies that header() returns a reference to this Base instance.
TEST(BaseTest, HeaderReturnsReference)
{
    ramrod::Writer writer;
    ramrod::Base base(writer);
    ramrod::Base& ref{base.header()};
    EXPECT_EQ(&ref, &base);
}

// Verifies that printf() writes formatted output to the writer and returns a non-negative count.
TEST(BaseTest, PrintfWritesToWriter)
{
    ramrod::Writer writer;
    ramrod::Base base(writer);
    int n{base.printf("value %d\n", 42)};
    EXPECT_GE(n, 0);
}

// Verifies that flush() runs without throwing.
TEST(BaseTest, FlushDoesNotThrow)
{
    ramrod::Writer writer;
    ramrod::Base base(writer);
    EXPECT_NO_THROW(base.flush());
}

// Verifies that operator<<(bool) writes to the writer without throwing.
TEST(BaseTest, OperatorShiftBool)
{
    ramrod::Writer writer;
    ramrod::Base base(writer);
    EXPECT_NO_THROW(base << true);
}

// Verifies that operator<<(const char*) writes to the writer without throwing.
TEST(BaseTest, OperatorShiftString)
{
    ramrod::Writer writer;
    ramrod::Base base(writer);
    EXPECT_NO_THROW(base << "hello");
}

// Verifies that operator<<(int) writes to the writer without throwing.
TEST(BaseTest, OperatorShiftInt)
{
    ramrod::Writer writer;
    ramrod::Base base(writer);
    EXPECT_NO_THROW(base << 42);
}

// Verifies that operator<<(std::string) writes to the writer without throwing.
TEST(BaseTest, OperatorShiftStdString)
{
    ramrod::Writer writer;
    ramrod::Base base(writer);
    EXPECT_NO_THROW(base << std::string("world"));
}

// Verifies that all operator<< overloads in Base write without throwing.
TEST(BaseTest, OperatorShiftAllOverloads)
{
    ramrod::Writer writer;
    ramrod::Base base(writer);
    base.header();

    EXPECT_NO_THROW(base << true << ramrod::endl);
    EXPECT_NO_THROW(base << 'x' << ramrod::endl);
    EXPECT_NO_THROW(base << static_cast<unsigned char>('y') << ramrod::endl);
    EXPECT_NO_THROW(base << "cstr" << ramrod::endl);
    const unsigned char ustr[]{"ustr"};
    EXPECT_NO_THROW(base << ustr << ramrod::endl << ramrod::endl);
    EXPECT_NO_THROW(base << static_cast<short>(-1) << ramrod::endl);
    EXPECT_NO_THROW(base << static_cast<unsigned short>(1) << ramrod::endl);
    EXPECT_NO_THROW(base << 42 << ramrod::endl);
    EXPECT_NO_THROW(base << 43u << ramrod::endl);
    EXPECT_NO_THROW(base << 3.14f << ramrod::endl);
    EXPECT_NO_THROW(base << 100L << ramrod::endl);
    EXPECT_NO_THROW(base << 101UL << ramrod::endl);
    EXPECT_NO_THROW(base << 2.718 << ramrod::endl);
    EXPECT_NO_THROW(base << 3.14159L << ramrod::endl);
    EXPECT_NO_THROW(base << -999LL << ramrod::endl);
    EXPECT_NO_THROW(base << 999ULL << ramrod::endl);
    EXPECT_NO_THROW(base << std::string{"std::string"} << ramrod::endl);
    EXPECT_NO_THROW(base << std::string_view{"string_view"} << ramrod::endl);
    int obj{};
    EXPECT_NO_THROW(base << static_cast<void*>(&obj) << ramrod::endl);
    EXPECT_NO_THROW(base << std::runtime_error("err") << ramrod::endl);
    EXPECT_NO_THROW(base << std::error_code(1, std::generic_category()) << ramrod::endl);
}
