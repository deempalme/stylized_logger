/**
 * @file test_file.cpp
 * @brief Unit tests for ramrod::File (append-mode file stream with clear/flush/path).
 */

#include "ramrod/log/File.hpp"

#include <filesystem>
#include <fstream>
#include <string>

#include <gtest/gtest.h>

namespace fs = std::filesystem;

// Verifies that constructing with a path opens the file and path() returns that path.
TEST(FileTest, ConstructionOpensFile)
{
    fs::path path{(fs::temp_directory_path() / "ramrod_file_test_open.txt").lexically_normal()};
    if (fs::exists(path))
        fs::remove(path);
    {
        ramrod::File file(path);
        EXPECT_TRUE(file.is_open());
        EXPECT_EQ(file.path(), path);
    }
    fs::remove(path);
}

// Verifies that data written via operator<< can be read back from the file.
TEST(FileTest, WriteAndReadBack)
{
    fs::path path{(fs::temp_directory_path() / "ramrod_file_test_write.txt").lexically_normal()};
    if (fs::exists(path))
        fs::remove(path);
    {
        ramrod::File file(path);
        ASSERT_TRUE(file.is_open());
        file << "hello"
             << " "
             << "world" << 42;
    }
    std::ifstream f(path);
    ASSERT_TRUE(f.is_open());
    std::string content((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    f.close();
    EXPECT_NE(content.find("hello"), std::string::npos);
    EXPECT_NE(content.find("world"), std::string::npos);
    EXPECT_NE(content.find("42"), std::string::npos);
    fs::remove(path);
}

// Verifies that clear() truncates the file to zero size.
TEST(FileTest, ClearTruncatesFile)
{
    fs::path path{(fs::temp_directory_path() / "ramrod_file_test_clear.txt").lexically_normal()};
    if (fs::exists(path))
        fs::remove(path);
    {
        ramrod::File file(path);
        file << "content";
    }
    {
        ramrod::File file(path);
        file.clear();
    }
    std::ifstream f(path);
    ASSERT_TRUE(f.is_open());
    std::string content((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    EXPECT_TRUE(content.empty());
    fs::remove(path);
}

// Verifies that after close(), is_open() returns false.
TEST(FileTest, CloseMakesIsOpenFalse)
{
    fs::path path{(fs::temp_directory_path() / "ramrod_file_test_close.txt").lexically_normal()};
    if (fs::exists(path))
        fs::remove(path);
    ramrod::File file(path);
    EXPECT_TRUE(file.is_open());
    file.close();
    EXPECT_FALSE(file.is_open());
    fs::remove(path);
}

// Verifies that open() with a new path reopens the file and path() returns the new path.
TEST(FileTest, OpenReopensWithNewPath)
{
    fs::path path1{(fs::temp_directory_path() / "ramrod_file_test_a.txt").lexically_normal()};
    fs::path path2{(fs::temp_directory_path() / "ramrod_file_test_b.txt").lexically_normal()};
    if (fs::exists(path1))
        fs::remove(path1);
    if (fs::exists(path2))
        fs::remove(path2);
    ramrod::File file(path1);
    EXPECT_TRUE(file.is_open());
    EXPECT_EQ(file.path(), path1);
    EXPECT_TRUE(file.open(path2));
    EXPECT_EQ(file.path(), path2);
    fs::remove(path1);
    fs::remove(path2);
}

// Verifies that flush() runs without throwing.
TEST(FileTest, FlushDoesNotThrow)
{
    fs::path path{(fs::temp_directory_path() / "ramrod_file_test_flush.txt").lexically_normal()};
    if (fs::exists(path))
        fs::remove(path);
    ramrod::File file(path);
    EXPECT_NO_THROW(file.flush());
    fs::remove(path);
}

// Verifies that all operator<< overloads in File write without throwing.
TEST(FileTest, OperatorShiftAllOverloads)
{
    fs::path path{(fs::temp_directory_path() / "ramrod_file_test_operator_shift.txt").lexically_normal()};
    if (fs::exists(path))
        fs::remove(path);

    ramrod::File file(path);
    ASSERT_TRUE(file.is_open());
    EXPECT_NO_THROW(file << true);
    EXPECT_NO_THROW(file << 'x');
    EXPECT_NO_THROW(file << static_cast<unsigned char>('y'));
    EXPECT_NO_THROW(file << "cstr");
    const unsigned char ustr[]{"ustr"};
    EXPECT_NO_THROW(file << ustr);
    EXPECT_NO_THROW(file << static_cast<short>(-1));
    EXPECT_NO_THROW(file << static_cast<unsigned short>(1));
    EXPECT_NO_THROW(file << 42);
    EXPECT_NO_THROW(file << 43u);
    EXPECT_NO_THROW(file << 3.14f);
    EXPECT_NO_THROW(file << 100L);
    EXPECT_NO_THROW(file << 101UL);
    EXPECT_NO_THROW(file << 2.718);
    EXPECT_NO_THROW(file << 3.14159L);
    EXPECT_NO_THROW(file << -999LL);
    EXPECT_NO_THROW(file << 999ULL);
    int obj{};
    EXPECT_NO_THROW(file << static_cast<void*>(&obj));

    fs::remove(path);
}
