#include "ramrod/log/Output.hpp"
#include "ramrod/log/OutputFile.hpp"

#include <fstream>
#include <string>

#include <gtest/gtest.h>
#include <filesystem>

namespace fs = std::filesystem;

TEST(OutputTest, VerifyStatusReturnsTrue)
{
    ramrod::Output out;
    EXPECT_TRUE(out.verify_status());
}

TEST(OutputTest, ClearAndEndDoNotThrow)
{
    ramrod::Output out;
    EXPECT_NO_THROW(out.clear());
    EXPECT_NO_THROW(out.end());
}

TEST(OutputTest, FormatDoesNotThrow)
{
    ramrod::Output out;
    EXPECT_NO_THROW(out.format("\e[0m"));
}

TEST(OutputFileTest, CreateAndVerifyStatus)
{
    fs::path path = fs::temp_directory_path() / "ramrod_log_test_create.txt";
    {
        ramrod::OutputFile out(path);
        EXPECT_TRUE(out.verify_status());
    }
    fs::remove(path);
}

TEST(OutputFileTest, WriteAndReadBack)
{
    fs::path path = fs::temp_directory_path() / "ramrod_log_test_write.txt";
    {
        ramrod::OutputFile out(path);
        ASSERT_TRUE(out.verify_status());
        out("hello", " ", "world", 42);
        out.end();
    }
    std::ifstream f(path);
    ASSERT_TRUE(f.is_open());
    std::string line;
    std::getline(f, line);
    EXPECT_EQ(line, "hello world42");
    fs::remove(path);
}

TEST(OutputFileTest, ClearTruncatesFile)
{
    fs::path path = fs::temp_directory_path() / "ramrod_log_test_clear.txt";
    {
        ramrod::OutputFile out(path);
        ASSERT_TRUE(out.verify_status());
        out("content");
        out.end();
    }
    {
        ramrod::OutputFile out(path);
        out.clear();
        EXPECT_TRUE(out.verify_status());
    }
    std::ifstream f(path);
    ASSERT_TRUE(f.is_open());
    std::string content((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    EXPECT_TRUE(content.empty());
    fs::remove(path);
}

TEST(OutputFileTest, VerifyStatusWithInvalidPath)
{
    fs::path path = fs::temp_directory_path() / "nonexistent_subdir_xyz" / "log.txt";
    ramrod::OutputFile out(path);
    EXPECT_FALSE(out.verify_status());
}
