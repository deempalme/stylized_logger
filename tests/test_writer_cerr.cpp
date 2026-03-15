/**
 * @file test_writer_cerr.cpp
 * @brief Unit tests for ramrod::WriterCerr (writer to stderr with ANSI format support).
 */

#include "ramrod/log/Endl.hpp"
#include "ramrod/log/WriterCerr.hpp"

#include <system_error>

#include <gtest/gtest.h>

// Verifies that default-constructed WriterCerr supports clear() and end() without throwing.
TEST(WriterCerrTest, DefaultConstruction)
{
    ramrod::WriterCerr writer;
    EXPECT_NO_THROW(writer.clear());
    EXPECT_NO_THROW(writer.end());
}

// Verifies that file_info() returns a reference to this WriterCerr instance.
TEST(WriterCerrTest, FileInfoReturnsReference)
{
    ramrod::WriterCerr writer;
    ramrod::WriterCerr& ref{writer.file_info(__FILE__, __LINE__)};
    EXPECT_EQ(&ref, &writer);
}

// Verifies that format() and header() run without throwing.
TEST(WriterCerrTest, FormatAndHeaderDoNotThrow)
{
    ramrod::WriterCerr writer;
    EXPECT_NO_THROW(writer.format("\e[0m"));
    EXPECT_NO_THROW(writer.header("\e[0m", "[ERROR]"));
}

// Verifies that flush() runs without throwing.
TEST(WriterCerrTest, FlushDoesNotThrow)
{
    ramrod::WriterCerr writer;
    EXPECT_NO_THROW(writer.flush());
}

// Verifies that operator<< writes string and int to stderr without throwing.
TEST(WriterCerrTest, OperatorShiftWrites)
{
    ramrod::WriterCerr writer;
    EXPECT_NO_THROW(writer << "test" << 42);
}

// Verifies that all operator<< overloads in WriterCerr (Writer) write without throwing.
TEST(WriterCerrTest, OperatorShiftAllOverloads)
{
    ramrod::WriterCerr writer;
    EXPECT_NO_THROW(writer << true << ramrod::endl);
    EXPECT_NO_THROW(writer << 'x' << ramrod::endl);
    EXPECT_NO_THROW(writer << static_cast<unsigned char>('y') << ramrod::endl);
    EXPECT_NO_THROW(writer << "cstr" << ramrod::endl);
    const unsigned char ustr[]{"ustr"};
    EXPECT_NO_THROW(writer << ustr << ramrod::endl);
    EXPECT_NO_THROW(writer << static_cast<short>(-1) << ramrod::endl);
    EXPECT_NO_THROW(writer << static_cast<unsigned short>(1) << ramrod::endl);
    EXPECT_NO_THROW(writer << 42 << ramrod::endl);
    EXPECT_NO_THROW(writer << 43u << ramrod::endl);
    EXPECT_NO_THROW(writer << 3.14f << ramrod::endl);
    EXPECT_NO_THROW(writer << 100L << ramrod::endl);
    EXPECT_NO_THROW(writer << 101UL << ramrod::endl);
    EXPECT_NO_THROW(writer << 2.718 << ramrod::endl);
    EXPECT_NO_THROW(writer << 3.14159L << ramrod::endl);
    EXPECT_NO_THROW(writer << -999LL << ramrod::endl);
    EXPECT_NO_THROW(writer << 999ULL << ramrod::endl);
    int obj{};
    EXPECT_NO_THROW(writer << static_cast<void*>(&obj) << ramrod::endl);
    EXPECT_NO_THROW(writer << std::error_code(1, std::generic_category()) << ramrod::endl);
}
