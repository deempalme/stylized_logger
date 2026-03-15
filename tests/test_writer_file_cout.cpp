/**
 * @file test_writer_file_cout.cpp
 * @brief Unit tests for ramrod::WriterFileCout (writes to file and stdout).
 */

#include "ramrod/log/Endl.hpp"
#include "ramrod/log/File.hpp"
#include "ramrod/log/WriterFileCout.hpp"

#include <filesystem>
#include <fstream>
#include <string>
#include <system_error>

#include <gtest/gtest.h>

namespace fs = std::filesystem;

// Verifies that WriterFileCout constructs with a File and header() runs without throwing.
TEST(WriterFileCoutTest, ConstructionWithFile)
{
    fs::path path{(fs::temp_directory_path() / "ramrod_writerfilecout_test.txt").lexically_normal()};
    if (fs::exists(path))
        fs::remove(path);
    ramrod::File file(path);
    ramrod::WriterFileCout writer(file);
    EXPECT_NO_THROW(writer.header("\e[0m", "[INFO]"));
    fs::remove(path);
}

// Verifies that data written via operator<< is present in the file.
TEST(WriterFileCoutTest, WriteToFileAndReadBack)
{
    fs::path path{(fs::temp_directory_path() / "ramrod_writerfilecout_write.txt").lexically_normal()};
    if (fs::exists(path))
        fs::remove(path);
    {
        ramrod::File file(path);
        ramrod::WriterFileCout writer(file);
        writer << "info line";
        writer.end();
    }
    std::ifstream f(path);
    ASSERT_TRUE(f.is_open());
    std::string content((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    f.close();
    EXPECT_NE(content.find("info line"), std::string::npos);
    fs::remove(path);
}

// Verifies that clear() truncates the underlying file.
TEST(WriterFileCoutTest, ClearTruncatesFile)
{
    fs::path path{(fs::temp_directory_path() / "ramrod_writerfilecout_clear.txt").lexically_normal()};
    if (fs::exists(path))
        fs::remove(path);
    {
        ramrod::File file(path);
        ramrod::WriterFileCout writer(file);
        writer << "content";
        writer.end();
    }
    {
        ramrod::File file(path);
        ramrod::WriterFileCout writer(file);
        writer.clear();
    }
    std::ifstream f(path);
    ASSERT_TRUE(f.is_open());
    std::string content((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    EXPECT_TRUE(content.empty());
    fs::remove(path);
}

// Verifies that all operator<< overloads in WriterFileCout (Writer) write without throwing.
TEST(WriterFileCoutTest, OperatorShiftAllOverloads)
{
    fs::path path{(fs::temp_directory_path() / "ramrod_writerfilecout_operator_shift.txt").lexically_normal()};
    if (fs::exists(path))
        fs::remove(path);
    ramrod::File file(path);
    ramrod::WriterFileCout writer(file);
    ASSERT_TRUE(file.is_open());
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
    fs::remove(path);
}
