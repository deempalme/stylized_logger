#include "ramrod/log/Output.hpp"

#include "ramrod/log/Constants.hpp"

#include <iostream>

namespace ramrod
{
void Output::clear()
{
    std::cout << CLEAR_TERMINAL;
}

void Output::clear_format()
{
    std::cout << CLEAR_FORMAT;
}

void Output::end()
{
    std::cout << CLEAR_FORMAT << std::endl;
}

Output& Output::file_info(const char* file, const int line)
{
    std::cout << INFO_PREFIX << file << INFO_SEPARATOR << line << INFO_SUFFIX;
    return *this;
}

void Output::flush()
{
    std::cout.flush();
}

void Output::format(const char* ansi_format)
{
    std::cout << ansi_format;
}

void Output::header(const char* ansi_format, const char* date, const char* level_tag)
{
    std::cout << ansi_format << date << level_tag;
}

bool Output::verify_status()
{
    return true;
}

Output& Output::operator<<(const bool message)
{
    std::cout << message;
    return *this;
}

Output& Output::operator<<(const char message)
{
    std::cout << message;
    return *this;
}

Output& Output::operator<<(const std::int8_t message)
{
    std::cout << message;
    return *this;
}

Output& Output::operator<<(const std::uint8_t message)
{
    std::cout << message;
    return *this;
}

Output& Output::operator<<(const char* message)
{
    std::cout << message;
    return *this;
}

Output& Output::operator<<(const std::int8_t* message)
{
    std::cout << message;
    return *this;
}

Output& Output::operator<<(const std::uint8_t* message)
{
    std::cout << message;
    return *this;
}

Output& Output::operator<<(const std::int16_t message)
{
    std::cout << message;
    return *this;
}

Output& Output::operator<<(const std::uint16_t message)
{
    std::cout << message;
    return *this;
}

Output& Output::operator<<(const std::int32_t message)
{
    std::cout << message;
    return *this;
}

Output& Output::operator<<(const std::uint32_t message)
{
    std::cout << message;
    return *this;
}

Output& Output::operator<<(const float message)
{
    std::cout << message;
    return *this;
}

Output& Output::operator<<(const std::int64_t message)
{
    std::cout << message;
    return *this;
}

Output& Output::operator<<(const std::uint64_t message)
{
    std::cout << message;
    return *this;
}

Output& Output::operator<<(const double message)
{
    std::cout << message;
    return *this;
}

Output& Output::operator<<(const long double message)
{
    std::cout << message;
    return *this;
}

Output& Output::operator<<(const std::string& message)
{
    std::cout << message.c_str();
    return *this;
}

Output& Output::operator<<(const std::string_view& message)
{
    std::cout << message.data();
    return *this;
}

Output& Output::operator<<(const void* message)
{
    std::cout << message;
    return *this;
}

Output& Output::operator<<(const std::exception& message)
{
    std::cout << message.what();
    return *this;
}

Output& Output::operator<<(const std::error_code& message)
{
    // The full string should be: "(<error_code>) <error_message>"
    std::cout << ERROR_PREFIX << message.value() << ERROR_SUFFIX << message.message().c_str();
    return *this;
}
} // namespace ramrod
