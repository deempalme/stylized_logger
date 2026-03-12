#include "ramrod/log/OutputError.hpp"

#include "ramrod/log/Constants.hpp"

#include <iostream>

namespace ramrod
{
void OutputError::clear()
{
    std::cerr << CLEAR_TERMINAL;
}

void OutputError::clear_format()
{
    std::cerr << CLEAR_FORMAT;
}

void OutputError::end()
{
    std::cerr << CLEAR_FORMAT << std::endl;
}

OutputError& OutputError::file_info(const char* file, const int line)
{
    std::cerr << INFO_PREFIX << file << INFO_SEPARATOR << line << INFO_SUFFIX;
    return *this;
}

void OutputError::flush()
{
    std::cerr.flush();
}

void OutputError::format(const char* ansi_format)
{
    std::cerr << ansi_format;
}

void OutputError::header(const char* ansi_format, const char* date, const char* level_tag)
{
    std::cerr << ansi_format << date << level_tag;
}

OutputError& OutputError::operator<<(const bool message)
{
    std::cerr << message;
    return *this;
}

OutputError& OutputError::operator<<(const char message)
{
    std::cerr << message;
    return *this;
}

OutputError& OutputError::operator<<(const std::int8_t message)
{
    std::cerr << message;
    return *this;
}

OutputError& OutputError::operator<<(const std::uint8_t message)
{
    std::cerr << message;
    return *this;
}

OutputError& OutputError::operator<<(const char* message)
{
    std::cerr << message;
    return *this;
}

OutputError& OutputError::operator<<(const std::int8_t* message)
{
    std::cerr << message;
    return *this;
}

OutputError& OutputError::operator<<(const std::uint8_t* message)
{
    std::cerr << message;
    return *this;
}

OutputError& OutputError::operator<<(const std::int16_t message)
{
    std::cerr << message;
    return *this;
}

OutputError& OutputError::operator<<(const std::uint16_t message)
{
    std::cerr << message;
    return *this;
}

OutputError& OutputError::operator<<(const std::int32_t message)
{
    std::cerr << message;
    return *this;
}

OutputError& OutputError::operator<<(const std::uint32_t message)
{
    std::cerr << message;
    return *this;
}

OutputError& OutputError::operator<<(const float message)
{
    std::cerr << message;
    return *this;
}

OutputError& OutputError::operator<<(const std::int64_t message)
{
    std::cerr << message;
    return *this;
}

OutputError& OutputError::operator<<(const std::uint64_t message)
{
    std::cerr << message;
    return *this;
}

OutputError& OutputError::operator<<(const double message)
{
    std::cerr << message;
    return *this;
}

OutputError& OutputError::operator<<(const long double message)
{
    std::cerr << message;
    return *this;
}

OutputError& OutputError::operator<<(const std::string& message)
{
    std::cerr << message.c_str();
    return *this;
}

OutputError& OutputError::operator<<(const std::string_view& message)
{
    std::cerr << message.data();
    return *this;
}

OutputError& OutputError::operator<<(const void* message)
{
    std::cerr << message;
    return *this;
}

OutputError& OutputError::operator<<(const std::exception& message)
{
    std::cerr << message.what();
    return *this;
}

OutputError& OutputError::operator<<(const std::error_code& message)
{
    // The full string should be: "(<error_code>) <error_message>"
    std::cerr << ERROR_PREFIX << message.value() << ERROR_SUFFIX << message.message().c_str();
    return *this;
}
} // namespace ramrod
