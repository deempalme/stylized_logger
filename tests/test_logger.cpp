/**
 * @file test_logger.cpp
 * @brief Unit tests for ramrod::Logger (aggregate of level loggers and output switching).
 */

#include "ramrod/log/Logger.hpp"

#include <filesystem>
#include <fstream>
#include <string>

#include <gtest/gtest.h>

namespace fs = std::filesystem;

// Verifies that default-constructed Logger allows error() and info() stream output without throwing.
TEST(LoggerTest, DefaultConstruction)
{
    ramrod::Logger log;
    EXPECT_NO_THROW(log.error() << "test");
    EXPECT_NO_THROW(log.info() << "test");
}

// Verifies that debug(), error(), info(), verbose(), and warning() return working level loggers.
TEST(LoggerTest, LevelAccessors)
{
    ramrod::Logger log;
    EXPECT_NO_THROW(log.debug() << "debug msg");
    EXPECT_NO_THROW(log.error() << "error msg");
    EXPECT_NO_THROW(log.info() << "info msg");
    EXPECT_NO_THROW(log.verbose() << "verbose msg");
    EXPECT_NO_THROW(log.warning() << "warning msg");
}

// Verifies that all level loggers write to file with correct tags when output is FILE.
TEST(LoggerTest, LevelAccessorsWriteToFile)
{
    fs::path path{(fs::temp_directory_path() / "ramrod_logger_levels.txt").lexically_normal()};
    if (fs::exists(path))
        fs::remove(path);
    {
        ramrod::Logger log(ramrod::Logger::OutputType::FILE, path);
        log.debug() << "debug line";
        log.error() << "error line";
        log.info() << "info line";
        log.verbose() << "verbose line";
        log.warning() << "warning line";
    }
    std::ifstream f(path);
    ASSERT_TRUE(f.is_open()) << "File: " << path;
    std::string content((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    f.close();
    EXPECT_NE(content.find("[DEBUG]"), std::string::npos);
    EXPECT_NE(content.find("debug line"), std::string::npos);
    EXPECT_NE(content.find("[ERROR]"), std::string::npos);
    EXPECT_NE(content.find("error line"), std::string::npos);
    EXPECT_NE(content.find("[INFO]"), std::string::npos);
    EXPECT_NE(content.find("info line"), std::string::npos);
    EXPECT_NE(content.find("[VERBOSE]"), std::string::npos);
    EXPECT_NE(content.find("verbose line"), std::string::npos);
    EXPECT_NE(content.find("[WARNING]"), std::string::npos);
    EXPECT_NE(content.find("warning line"), std::string::npos);
    fs::remove(path);
}

// Verifies that all OutputType values (CONSOLE, FILE, FILE_AND_CONSOLE) work: construction and write.
TEST(LoggerTest, AllOutputTypes)
{
    using OT = ramrod::Logger::OutputType;
    fs::path path{(fs::temp_directory_path() / "ramrod_logger_output_types.txt").lexically_normal()};
    if (fs::exists(path))
        fs::remove(path);

    // CONSOLE: default or explicit CONSOLE, write does not throw, output() is TO_CONSOLE (empty path).
    {
        ramrod::Logger log(OT::CONSOLE);
        EXPECT_TRUE(log.output().empty() || log.output() == ramrod::Logger::TO_CONSOLE);
        EXPECT_NO_THROW(log.info() << "console");
    }

    // FILE: output goes only to file.
    {
        ramrod::Logger log(OT::FILE, path);
        EXPECT_EQ(log.output(), path);
        log.info() << "file only";
    }
    {
        std::ifstream f(path);
        ASSERT_TRUE(f.is_open());
        std::string content((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
        f.close();
        EXPECT_NE(content.find("file only"), std::string::npos);
    }

    // FILE_AND_CONSOLE: output goes to file and stdout/stderr.
    if (fs::exists(path))
        fs::remove(path);
    {
        ramrod::Logger log(OT::FILE_AND_CONSOLE, path);
        EXPECT_EQ(log.output(), path);
        EXPECT_NO_THROW(log.info() << "file and console");
    }
    {
        std::ifstream f(path);
        ASSERT_TRUE(f.is_open());
        std::string content((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
        f.close();
        EXPECT_NE(content.find("file and console"), std::string::npos);
    }
    fs::remove(path);
}

// Verifies that Logger(OutputType::FILE, path) writes error and info lines to the file with level tags.
TEST(LoggerTest, FileConstruction)
{
    fs::path path{(fs::temp_directory_path() / "ramrod_logger_test.txt").lexically_normal()};
    if (fs::exists(path))
        fs::remove(path);
    {
        ramrod::Logger log(ramrod::Logger::OutputType::FILE, path);
        log.error() << "error line";
        log.info() << "info line";
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

// Verifies that output(FILE, path2) switches output to path2 and subsequent writes go to the new file.
TEST(LoggerTest, ChangeLogOutput)
{
    fs::path path1{(fs::temp_directory_path() / "ramrod_logger_path1.txt").lexically_normal()};
    fs::path path2{(fs::temp_directory_path() / "ramrod_logger_path2.txt").lexically_normal()};
    if (fs::exists(path1))
        fs::remove(path1);
    if (fs::exists(path2))
        fs::remove(path2);
    ramrod::Logger log(ramrod::Logger::OutputType::FILE, path1);
    log.info() << "first file";
    bool ok{log.output(ramrod::Logger::OutputType::FILE, path2)};
    EXPECT_TRUE(ok);
    log.info() << "second file";
    log.flush();
    {
        std::ifstream f(path2);
        ASSERT_TRUE(f.is_open());
        std::string content((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
        EXPECT_NE(content.find("second file"), std::string::npos);
    }
    fs::remove(path1);
    fs::remove(path2);
}

// Verifies that printf_buffer_size() returns a positive default and setter updates the size.
TEST(LoggerTest, PrintfBufferSize)
{
    ramrod::Logger log;
    size_t default_size{log.printf_buffer_size()};
    EXPECT_GT(default_size, 0u);
    log.printf_buffer_size(2048ul);
    EXPECT_EQ(log.printf_buffer_size(), 2048ul);
}

// Verifies that date_format() accepts a new format string and buffer size and info() still writes.
TEST(LoggerTest, ChangeDateFormat)
{
    fs::path path{(fs::temp_directory_path() / "ramrod_logger_datefmt.txt").lexically_normal()};
    ramrod::Logger log(ramrod::Logger::OutputType::FILE, path);
    EXPECT_TRUE(log.date_format("[%Y-%m-%d %H:%M:%S]", 24));
    log.info() << "after date format change";
    fs::remove(path);
}

// Verifies that error().printf() writes formatted text to the file output.
TEST(LoggerTest, PrintfToFile)
{
    fs::path path{(fs::temp_directory_path() / "ramrod_logger_printf.txt").lexically_normal()};
    {
        ramrod::Logger log(ramrod::Logger::OutputType::FILE, path);
        log.error().printf("code %d: %s", 42, "message");
    }
    std::ifstream f(path);
    ASSERT_TRUE(f.is_open());
    std::string content((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    EXPECT_NE(content.find("42"), std::string::npos);
    EXPECT_NE(content.find("message"), std::string::npos);
    fs::remove(path);
}

// Verifies that clear() and end() on a default Logger do not throw.
TEST(LoggerOutputTest, ClearAndEndDoNotThrow)
{
    ramrod::Logger log;
    EXPECT_NO_THROW(log.clear());
    EXPECT_NO_THROW(log.end());
}

// Verifies that Logger with FILE output and a valid path creates the file and can write.
TEST(LoggerOutputTest, FileOutputSucceedsWithValidPath)
{
    fs::path path{(fs::temp_directory_path() / "ramrod_log_test_create.txt").lexically_normal()};
    if (fs::exists(path))
        fs::remove(path);
    {
        ramrod::Logger log(ramrod::Logger::OutputType::FILE, path);
        log.info() << "created";
        log.end();
    }
    ASSERT_TRUE(fs::exists(path));
    fs::remove(path);
}

// Verifies that data written via info() and end() can be read back from the log file.
TEST(LoggerOutputTest, WriteAndReadBack)
{
    fs::path path{(fs::temp_directory_path() / "ramrod_log_test_write.txt").lexically_normal()};
    {
        ramrod::Logger log(ramrod::Logger::OutputType::FILE, path);
        log.info() << "hello"
                  << " "
                  << "world" << 42;
        log.end();
    }
    std::ifstream f(path);
    ASSERT_TRUE(f.is_open());
    std::string line;
    std::getline(f, line);
    EXPECT_NE(line.find("hello"), std::string::npos);
    EXPECT_NE(line.find("world"), std::string::npos);
    EXPECT_NE(line.find("42"), std::string::npos);
    fs::remove(path);
}

// Verifies that clear() on a Logger with file output truncates the file.
TEST(LoggerOutputTest, ClearTruncatesFile)
{
    fs::path path{(fs::temp_directory_path() / "ramrod_log_test_clear.txt").lexically_normal()};
    {
        ramrod::Logger log(ramrod::Logger::OutputType::FILE, path);
        log.info() << "content";
        log.end();
    }
    {
        ramrod::Logger log(ramrod::Logger::OutputType::FILE, path);
        log.clear();
    }
    std::ifstream f(path);
    ASSERT_TRUE(f.is_open());
    std::string content((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    EXPECT_TRUE(content.empty());
    fs::remove(path);
}

// Verifies that output(FILE, invalid_path) returns false and does not throw.
TEST(LoggerOutputTest, InvalidPathReturnsFalse)
{
    fs::path path{(fs::temp_directory_path() / "nonexistent_subdir_xyz" / "log.txt").lexically_normal()};
    ramrod::Logger log;
    EXPECT_FALSE(log.output(ramrod::Logger::OutputType::FILE, path));
}

// Verifies that RR_LOG, RR_LOGD, RR_LOGE, RR_LOGI, RR_LOGV, RR_LOGW, and RR_ENDL macros work.
TEST(LoggerTest, Macros)
{
    EXPECT_EQ(&RR_LOG, &ramrod::global_logger);
    EXPECT_NO_THROW(RR_LOGD << "debug" << RR_ENDL);
    EXPECT_NO_THROW(RR_LOGE << "error" << RR_ENDL);
    EXPECT_NO_THROW(RR_LOGI << "info" << RR_ENDL);
    EXPECT_NO_THROW(RR_LOGV << "verbose" << RR_ENDL);
    EXPECT_NO_THROW(RR_LOGW << "warning" << RR_ENDL);
}
