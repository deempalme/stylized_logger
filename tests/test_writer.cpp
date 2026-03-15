/**
 * @file test_writer.cpp
 * @brief Unit tests for ramrod::Writer (base log writer: date, format, header, stream).
 */

#include "ramrod/log/Endl.hpp"
#include "ramrod/log/Writer.hpp"

#include <string>
#include <system_error>

#include <gtest/gtest.h>

// Verifies that default-constructed Writer supports clear() and end() without throwing.
TEST(WriterTest, DefaultConstruction)
{
    ramrod::Writer writer;
    EXPECT_NO_THROW(writer.clear());
    EXPECT_NO_THROW(writer.end());
}

// Verifies that date() returns a non-null, non-empty formatted date string.
TEST(WriterTest, DateReturnsNonEmpty)
{
    ramrod::Writer writer;
    const char* date_str{writer.date()};
    ASSERT_NE(date_str, nullptr);
    EXPECT_GT(std::string(date_str).size(), 0u);
}

// Verifies that date_format() getter returns non-null and setter accepts valid format and size.
TEST(WriterTest, DateFormatGetSet)
{
    ramrod::Writer writer;
    const char* default_fmt{writer.date_format()};
    ASSERT_NE(default_fmt, nullptr);
    EXPECT_TRUE(writer.date_format("[%Y-%m-%d %H:%M:%S]", 24));
    EXPECT_NE(writer.date_format(), nullptr);
}

// Verifies that date_format() returns false for empty format or zero buffer size.
TEST(WriterTest, DateFormatRejectsEmpty)
{
    ramrod::Writer writer;
    EXPECT_FALSE(writer.date_format("", 24));
    EXPECT_FALSE(writer.date_format("[%Y]", 0));
}

// Verifies that file_info() returns a reference to this Writer instance.
TEST(WriterTest, FileInfoReturnsReference)
{
    ramrod::Writer writer;
    ramrod::Writer& ref{writer.file_info(__FILE__, __LINE__)};
    EXPECT_EQ(&ref, &writer);
}

// Verifies that clear_format() runs without throwing.
TEST(WriterTest, ClearFormatDoesNotThrow)
{
    ramrod::Writer writer;
    EXPECT_NO_THROW(writer.clear_format());
}

// Verifies that format() runs without throwing.
TEST(WriterTest, FormatDoesNotThrow)
{
    ramrod::Writer writer;
    EXPECT_NO_THROW(writer.format("\e[0m"));
}

// Verifies that header() runs without throwing.
TEST(WriterTest, HeaderDoesNotThrow)
{
    ramrod::Writer writer;
    EXPECT_NO_THROW(writer.header("\e[0m", "[TAG]"));
}

// Verifies that printf_buffer_size() returns positive default and setter updates size.
TEST(WriterTest, PrintfBufferSize)
{
    ramrod::Writer writer;
    size_t size{writer.printf_buffer_size()};
    EXPECT_GT(size, 0u);
    writer.printf_buffer_size(2048);
    EXPECT_EQ(writer.printf_buffer_size(), 2048u);
}

// Verifies that printf_buffer() returns a non-null pointer.
TEST(WriterTest, PrintfBufferNonNull)
{
    ramrod::Writer writer;
    char* buf{writer.printf_buffer()};
    EXPECT_NE(buf, nullptr);
}

// Verifies that operator<< accepts bool, char, int, string literal, and double without throwing.
TEST(WriterTest, OperatorShiftBasicTypes)
{
    ramrod::Writer writer;
    EXPECT_NO_THROW(writer << true << 'x' << 42 << "str" << 3.14);
}

// Verifies that all operator<< overloads in Writer write without throwing.
TEST(WriterTest, OperatorShiftAllOverloads)
{
    ramrod::Writer writer;
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
