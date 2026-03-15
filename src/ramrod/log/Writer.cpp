#include "ramrod/log/Writer.hpp"

#include "Constants.hpp"

#include <cstring>
#include <ctime>
#include <iostream>

namespace
{
/// @brief Size of the date buffer, string should contain "[2026-03-01 12:00:00 +0100]"
///        (28 chars) plus null terminator; use 28 to allow for all timezone formats.
static constexpr size_t DATE_DEFAULT_BUFFER_SIZE{28ul};
/// @brief Format used to print the date and time, e.g. "[2026-03-01 12:00:00 +0100]"
static constexpr char DATE_DEFAULT_FORMAT[]{"[%Y-%m-%d %H:%M:%S %z]"};
/// @brief Size of the printf buffer
static constexpr size_t PRINTF_BUFFER_DEFAULT_SIZE{1024ul};
} // Unnamed namespace

namespace ramrod
{
Writer::Writer()
    : date_buffer_{},
      date_buffer_size_{},
      date_format_{},
      printf_buffer_{new char[PRINTF_BUFFER_DEFAULT_SIZE]},
      printf_buffer_size_{PRINTF_BUFFER_DEFAULT_SIZE}
{
    date_format(DATE_DEFAULT_FORMAT, DATE_DEFAULT_BUFFER_SIZE);
}

Writer::~Writer()
{
    if (date_buffer_ != nullptr)
        delete[] date_buffer_;
    if (date_format_ != nullptr)
        delete[] date_format_;
    if (printf_buffer_ != nullptr)
        delete[] printf_buffer_;
}

void Writer::clear() {}

void Writer::clear_format()
{
    std::cout << CLEAR_FORMAT;
}

const char* Writer::date()
{
    if (date_buffer_ == nullptr || date_buffer_size_ == 0)
        return "";
    const std::time_t t{std::time(nullptr)};
    std::strftime(date_buffer_, date_buffer_size_, date_format_, std::localtime(&t));
    return date_buffer_;
}

const char* Writer::date_format() const
{
    return date_format_;
}

bool Writer::date_format(const std::string& date_format, const size_t date_buffer_size)
{
    if (date_format.empty() || (date_buffer_size == 0))
        return false;

    if (date_format_ != nullptr)
        delete[] date_format_;
    /// @brief Padding to ensure the string is null-terminated
    static constexpr size_t STRING_PADDING{1ul};
    date_format_ = new char[date_format.size() + STRING_PADDING];
    std::strncpy(date_format_, date_format.c_str(), date_format.size());

    // Making sure the string is null-terminated
    static constexpr char NULL_TERMINATOR{'\0'};
    date_format_[date_format.size()] = NULL_TERMINATOR;

    date_buffer_size_ = date_buffer_size;
    if (date_buffer_ != nullptr)
        delete[] date_buffer_;
    date_buffer_ = new char[date_buffer_size_];

    return (date_format_ != nullptr) && (date_buffer_ != nullptr);
}

void Writer::end()
{
    std::cout << std::endl;
}

Writer& Writer::file_info(const char* file, const int line)
{
    std::cout << INFO_PREFIX << get_filename(file).c_str() << INFO_SEPARATOR << line << INFO_SUFFIX;
    return *this;
}

void Writer::flush()
{
    std::cout.flush();
}

void Writer::format(const char* ansi_format)
{
    std::cout << ansi_format;
}

void Writer::header(const char* ansi_format, const char* level_tag)
{
    std::cout << ansi_format << date() << level_tag << CLEAR_FORMAT;
}

char* Writer::printf_buffer()
{
    return printf_buffer_;
}

size_t Writer::printf_buffer_size() const
{
    return printf_buffer_size_;
}

void Writer::printf_buffer_size(const size_t new_size)
{
    if (printf_buffer_ != nullptr)
        delete[] printf_buffer_;
    printf_buffer_ = new char[new_size];
    printf_buffer_size_ = new_size;
}

Writer& Writer::operator<<(const bool message)
{
    std::cout << message;
    return *this;
}

Writer& Writer::operator<<(const char message)
{
    std::cout << message;
    return *this;
}

Writer& Writer::operator<<(const unsigned char message)
{
    std::cout << message;
    return *this;
}

Writer& Writer::operator<<(const char* message)
{
    std::cout << message;
    return *this;
}

Writer& Writer::operator<<(const unsigned char* message)
{
    std::cout << message;
    return *this;
}

Writer& Writer::operator<<(const short message)
{
    std::cout << message;
    return *this;
}

Writer& Writer::operator<<(const unsigned short message)
{
    std::cout << message;
    return *this;
}

Writer& Writer::operator<<(const int message)
{
    std::cout << message;
    return *this;
}

Writer& Writer::operator<<(const unsigned int message)
{
    std::cout << message;
    return *this;
}

Writer& Writer::operator<<(const float message)
{
    std::cout << message;
    return *this;
}

Writer& Writer::operator<<(const long message)
{
    std::cout << message;
    return *this;
}

Writer& Writer::operator<<(const unsigned long message)
{
    std::cout << message;
    return *this;
}

Writer& Writer::operator<<(const double message)
{
    std::cout << message;
    return *this;
}

Writer& Writer::operator<<(const long double message)
{
    std::cout << message;
    return *this;
}

Writer& Writer::operator<<(const long long message)
{
    std::cout << message;
    return *this;
}

Writer& Writer::operator<<(const unsigned long long message)
{
    std::cout << message;
    return *this;
}

Writer& Writer::operator<<(const void* message)
{
    std::cout << message;
    return *this;
}

Writer& Writer::operator<<(const std::error_code& message)
{
    std::cout << ERROR_CODE_PREFIX << message.value() << ERROR_CODE_SUFFIX << message.message().c_str();
    return *this;
}

Writer& Writer::operator<<(const Endl&)
{
    std::cout << std::endl;
    return *this;
}

std::filesystem::path Writer::get_filename(const char* file)
{
    return std::filesystem::path(file).filename();
}
} // namespace ramrod
