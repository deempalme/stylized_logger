#include "ramrod/log/Logger.hpp"

#include <fstream>
#include <string>

#include <gtest/gtest.h>
#include <filesystem>

namespace fs = std::filesystem;

TEST(LoggerTest, DefaultConstruction)
{
    ramrod::Logger log;
    EXPECT_NO_THROW(log.error("test"));
    EXPECT_NO_THROW(log.info("test"));
}

TEST(LoggerTest, FileConstruction)
{
    fs::path path = (fs::temp_directory_path() / "ramrod_logger_test.txt").lexically_normal();
    if (fs::exists(path))
        fs::remove(path);
    {
        ramrod::Logger log(path);
        log.error("error line");
        log.info("info line");
    }
    std::ifstream f(path);
    ASSERT_TRUE(f.is_open()) << "File: " << path;
    std::string content((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    f.close();
    EXPECT_NE(content.find("[ERROR]"), std::string::npos);
    EXPECT_NE(content.find("error line"), std::string::npos);
    EXPECT_NE(content.find("[INFO]"), std::string::npos);
    EXPECT_NE(content.find("info line"), std::string::npos);
    fs::remove(path);
}

TEST(LoggerTest, ChangeLogOutput)
{
    fs::path path1 = fs::temp_directory_path() / "ramrod_logger_path1.txt";
    fs::path path2 = fs::temp_directory_path() / "ramrod_logger_path2.txt";
    ramrod::Logger log(path1);
    log.info("first file");
    bool ok = log.change_log_output(path2);
    EXPECT_TRUE(ok);
    log.info("second file");
    {
        std::ifstream f(path2);
        ASSERT_TRUE(f.is_open());
        std::string content((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
        EXPECT_NE(content.find("second file"), std::string::npos);
    }
    fs::remove(path1);
    fs::remove(path2);
}

TEST(LoggerTest, PrintfBufferSize)
{
    ramrod::Logger log;
    size_t default_size = log.printf_buffer_size();
    EXPECT_GT(default_size, 0u);
    log.printf_buffer_size(2048);
    EXPECT_EQ(log.printf_buffer_size(), 2048u);
}

TEST(LoggerTest, ChangeDateFormat)
{
    fs::path path = fs::temp_directory_path() / "ramrod_logger_datefmt.txt";
    ramrod::Logger log(path);
    EXPECT_NO_THROW(log.change_date_format("[%Y-%m-%d %H:%M:%S]", 24));
    log.info("after date format change");
    fs::remove(path);
}

TEST(LoggerTest, PrintfToFile)
{
    fs::path path = fs::temp_directory_path() / "ramrod_logger_printf.txt";
    {
        ramrod::Logger log(path);
        log.error.printf("code %d: %s", 42, "message");
    }
    std::ifstream f(path);
    ASSERT_TRUE(f.is_open());
    std::string content((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    EXPECT_NE(content.find("42"), std::string::npos);
    EXPECT_NE(content.find("message"), std::string::npos);
    fs::remove(path);
}
