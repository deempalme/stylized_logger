#include "ramrod/log/WriterFileCerr.hpp"

#include "Constants.hpp"

#include <iostream>

namespace ramrod
{
WriterFileCerr::WriterFileCerr(File& file)
    : Writer{},
      file_{file}
{
}

void WriterFileCerr::clear()
{
    file_.clear();
}

void WriterFileCerr::clear_format()
{
    std::cerr << CLEAR_FORMAT;
}

void WriterFileCerr::end()
{
    // Nothing to do with ANSI format since files are not compatible with it, just
    // adding a new line to the end of the file
    file_ << ENDL;
    std::cerr << std::endl;
}

WriterFileCerr& WriterFileCerr::file_info(const char* file, const int line)
{
    const std::filesystem::path filename{get_filename(file)};
    file_ << INFO_PREFIX << filename.c_str() << INFO_SEPARATOR << line << INFO_SUFFIX;
    std::cerr << INFO_PREFIX << filename.c_str() << INFO_SEPARATOR << line << INFO_SUFFIX;
    return *this;
}

void WriterFileCerr::flush()
{
    file_.flush();
    std::cerr.flush();
}

void WriterFileCerr::format(const char* ansi_format)
{
    // ansi_format is ignored since files are not compatible with ANSI format
    std::cerr << ansi_format;
}

void WriterFileCerr::header(const char* ansi_format, const char* level_tag)
{
    // ansi_format is ignored since files are not compatible with ANSI format
    file_ << date() << level_tag;
    std::cerr << ansi_format << date() << level_tag << CLEAR_FORMAT;
}

WriterFileCerr& WriterFileCerr::operator<<(const bool message)
{
    file_ << message;
    std::cerr << message;
    return *this;
}

WriterFileCerr& WriterFileCerr::operator<<(const char message)
{
    file_ << message;
    std::cerr << message;
    return *this;
}

WriterFileCerr& WriterFileCerr::operator<<(const unsigned char message)
{
    file_ << message;
    std::cerr << message;
    return *this;
}

WriterFileCerr& WriterFileCerr::operator<<(const char* message)
{
    file_ << message;
    std::cerr << message;
    return *this;
}

WriterFileCerr& WriterFileCerr::operator<<(const unsigned char* message)
{
    file_ << message;
    std::cerr << message;
    return *this;
}

WriterFileCerr& WriterFileCerr::operator<<(const short message)
{
    file_ << message;
    std::cerr << message;
    return *this;
}

WriterFileCerr& WriterFileCerr::operator<<(const unsigned short message)
{
    file_ << message;
    std::cerr << message;
    return *this;
}

WriterFileCerr& WriterFileCerr::operator<<(const int message)
{
    file_ << message;
    std::cerr << message;
    return *this;
}

WriterFileCerr& WriterFileCerr::operator<<(const unsigned int message)
{
    file_ << message;
    std::cerr << message;
    return *this;
}

WriterFileCerr& WriterFileCerr::operator<<(const float message)
{
    file_ << message;
    std::cerr << message;
    return *this;
}

WriterFileCerr& WriterFileCerr::operator<<(const long message)
{
    file_ << message;
    std::cerr << message;
    return *this;
}

WriterFileCerr& WriterFileCerr::operator<<(const unsigned long message)
{
    file_ << message;
    std::cerr << message;
    return *this;
}

WriterFileCerr& WriterFileCerr::operator<<(const double message)
{
    file_ << message;
    std::cerr << message;
    return *this;
}

WriterFileCerr& WriterFileCerr::operator<<(const long double message)
{
    file_ << message;
    std::cerr << message;
    return *this;
}

WriterFileCerr& WriterFileCerr::operator<<(const long long message)
{
    file_ << message;
    std::cerr << message;
    return *this;
}

WriterFileCerr& WriterFileCerr::operator<<(const unsigned long long message)
{
    file_ << message;
    std::cerr << message;
    return *this;
}

WriterFileCerr& WriterFileCerr::operator<<(const void* message)
{
    file_ << message;
    std::cerr << message;
    return *this;
}

WriterFileCerr& WriterFileCerr::operator<<(const std::error_code& message)
{
    // The full string should be: "(<error_code>) <error_message>"
    file_ << ERROR_CODE_PREFIX << message.value() << ERROR_CODE_SUFFIX << message.message().c_str();
    std::cerr << ERROR_CODE_PREFIX << message.value() << ERROR_CODE_SUFFIX << message.message().c_str();
    return *this;
}

WriterFileCerr& WriterFileCerr::operator<<(const Endl&)
{
    file_ << ENDL;
    std::cerr << std::endl;
    return *this;
}
} // namespace ramrod
