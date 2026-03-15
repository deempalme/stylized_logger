#include "ramrod/log/WriterCerr.hpp"

#include "Constants.hpp"

#include <iostream>

namespace ramrod
{
void WriterCerr::clear_format()
{
    std::cerr << CLEAR_FORMAT;
}

void WriterCerr::end()
{
    std::cerr << std::endl;
}

WriterCerr& WriterCerr::file_info(const char* file, const int line)
{
    const std::filesystem::path filename{get_filename(file)};
    std::cerr << INFO_PREFIX << filename.c_str() << INFO_SEPARATOR << line << INFO_SUFFIX;
    return *this;
}

void WriterCerr::flush()
{
    std::cerr.flush();
}

void WriterCerr::format(const char* ansi_format)
{
    std::cerr << ansi_format;
}

void WriterCerr::header(const char* ansi_format, const char* level_tag)
{
    std::cerr << ansi_format << date() << level_tag << CLEAR_FORMAT;
}

WriterCerr& WriterCerr::operator<<(const bool message)
{
    std::cerr << message;
    return *this;
}

WriterCerr& WriterCerr::operator<<(const char message)
{
    std::cerr << message;
    return *this;
}

WriterCerr& WriterCerr::operator<<(const unsigned char message)
{
    std::cerr << message;
    return *this;
}

WriterCerr& WriterCerr::operator<<(const char* message)
{
    std::cerr << message;
    return *this;
}

WriterCerr& WriterCerr::operator<<(const unsigned char* message)
{
    std::cerr << message;
    return *this;
}

WriterCerr& WriterCerr::operator<<(const short message)
{
    std::cerr << message;
    return *this;
}

WriterCerr& WriterCerr::operator<<(const unsigned short message)
{
    std::cerr << message;
    return *this;
}

WriterCerr& WriterCerr::operator<<(const int message)
{
    std::cerr << message;
    return *this;
}

WriterCerr& WriterCerr::operator<<(const unsigned int message)
{
    std::cerr << message;
    return *this;
}

WriterCerr& WriterCerr::operator<<(const float message)
{
    std::cerr << message;
    return *this;
}

WriterCerr& WriterCerr::operator<<(const long message)
{
    std::cerr << message;
    return *this;
}

WriterCerr& WriterCerr::operator<<(const unsigned long message)
{
    std::cerr << message;
    return *this;
}

WriterCerr& WriterCerr::operator<<(const double message)
{
    std::cerr << message;
    return *this;
}

WriterCerr& WriterCerr::operator<<(const long double message)
{
    std::cerr << message;
    return *this;
}

WriterCerr& WriterCerr::operator<<(const long long message)
{
    std::cerr << message;
    return *this;
}

WriterCerr& WriterCerr::operator<<(const unsigned long long message)
{
    std::cerr << message;
    return *this;
}

WriterCerr& WriterCerr::operator<<(const void* message)
{
    std::cerr << message;
    return *this;
}

WriterCerr& WriterCerr::operator<<(const std::error_code& message)
{
    // The full string should be: "(<error_code>) <error_message>"
    std::cerr << ERROR_CODE_PREFIX << message.value() << ERROR_CODE_SUFFIX << message.message().c_str();
    return *this;
}

WriterCerr& WriterCerr::operator<<(const Endl&)
{
    std::cerr << std::endl;
    return *this;
}
} // namespace ramrod
