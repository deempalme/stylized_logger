#include "ramrod/log/Writer.hpp"

#include "Constants.hpp"

#include <chrono>
#include <cstring>
#include <ctime>
#include <iostream>

namespace
{
/// @brief Size of the date buffer, string should contain "[2026-03-01 12:00:00.000001]"
///        (32 chars) plus null terminator; use 32 to allow for all timezone formats.
static constexpr std::size_t DATE_DEFAULT_BUFFER_SIZE{32ul};
/// @brief Format used to print the date and time, e.g. "2026-03-01 12:00:00"
static constexpr char DATE_DEFAULT_FORMAT[]{"%Y-%m-%d %H:%M:%S"};
/// @brief Size of an empty buffer
static constexpr std::size_t EMPTY_BUFFER_SIZE{};
/// @brief Empty date string
static constexpr char EMPTY_DATE[]{""};
/// @brief Null terminator
static constexpr char NULL_TERMINATOR{'\0'};
/// @brief Size of the printf buffer
static constexpr std::size_t PRINTF_BUFFER_DEFAULT_SIZE{1024ul};
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
    if ((date_buffer_ == nullptr) || (date_buffer_size_ == EMPTY_BUFFER_SIZE) ||
        (date_format_ == nullptr))
        return EMPTY_DATE;
    /// @brief String used to prefix the date: "["
    static constexpr char DATE_PREFIX{'['};
    /// @brief Size of a single character
    static constexpr std::size_t CHARACTER_SIZE{1ul};
    std::size_t offset{CHARACTER_SIZE};
    *date_buffer_ = DATE_PREFIX;

    const std::chrono::high_resolution_clock::time_point now{
        std::chrono::high_resolution_clock::now()};
    const std::time_t t{std::chrono::high_resolution_clock::to_time_t(now)};

    std::tm local_time{};
    offset += std::strftime(date_buffer_ + offset, date_buffer_size_, date_format_,
                            ::localtime_r(&t, &local_time));
    if (offset == CHARACTER_SIZE)
        // Date's format is not supported by the system
        return EMPTY_DATE;

    /// @brief Index of the last character (where the null terminator will be placed)
    const std::size_t last_character{date_buffer_size_ - CHARACTER_SIZE};

    if (add_microseconds_)
    {
        const long microseconds_since_epoch{
            std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()).count()};
        static constexpr long MICROSECONDS_PER_SECOND{1'000'000};
        const long microseconds{microseconds_since_epoch % MICROSECONDS_PER_SECOND};

        offset = std::min(offset, last_character);
        const int count{std::snprintf(date_buffer_ + offset, date_buffer_size_ - offset, ".%06ld",
                                      microseconds)};
        offset += static_cast<std::size_t>(count);
    }

    /// @brief Index of the character before the last
    const std::size_t before_last_character{date_buffer_size_ - CHARACTER_SIZE - CHARACTER_SIZE};
    offset = std::min(offset, before_last_character);
    static constexpr char DATE_SUFFIX{']'};
    *(date_buffer_ + offset) = DATE_SUFFIX;
    ++offset;

    offset = std::min(offset, last_character);
    *(date_buffer_ + offset) = NULL_TERMINATOR;

    return date_buffer_;
}

const char* Writer::date_format() const
{
    return date_format_;
}

bool Writer::date_format(const std::string& date_format, const size_t date_buffer_size,
                         const bool add_microseconds)
{
    if (date_format.empty() || (date_buffer_size == EMPTY_BUFFER_SIZE))
        return false;

    if (date_format_ != nullptr)
        delete[] date_format_;
    /// @brief Padding to ensure the string is null-terminated
    static constexpr size_t STRING_PADDING{1ul};
    date_format_ = new char[date_format.size() + STRING_PADDING];
    std::strncpy(date_format_, date_format.c_str(), date_format.size());

    // Making sure the string is null-terminated
    date_format_[date_format.size()] = NULL_TERMINATOR;

    date_buffer_size_ = date_buffer_size;
    if (date_buffer_ != nullptr)
        delete[] date_buffer_;
    date_buffer_ = new char[date_buffer_size_];

    add_microseconds_ = add_microseconds;

    return !std::string_view{date()}.empty();
}

void Writer::end()
{
    std::cout << std::endl;
}

Writer& Writer::file_info(const char* file, const int line)
{
    std::cout << INFO_PREFIX << Writer::get_filename(file).c_str() << INFO_SEPARATOR << line
              << INFO_SUFFIX;
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
    std::cout << ERROR_CODE_PREFIX << message.value() << ERROR_CODE_SUFFIX
              << message.message().c_str();
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
