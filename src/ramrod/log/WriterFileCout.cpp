#include "ramrod/log/WriterFileCout.hpp"

#include "Constants.hpp"

#include <iostream>

namespace ramrod
{
WriterFileCout::WriterFileCout(File& file)
    : Writer{},
      file_{file}
{
}

void WriterFileCout::clear()
{
    file_.clear();
}

void WriterFileCout::end()
{
    // Nothing to do with ANSI format since files are not compatible with it, just
    // adding a new line to the end of the file
    file_ << ENDL;
    std::cout << CLEAR_FORMAT << std::endl;
}

WriterFileCout& WriterFileCout::file_info(const char* file, const int line)
{
    const std::filesystem::path filename{Writer::get_filename(file)};
    file_ << INFO_PREFIX << filename.c_str() << INFO_SEPARATOR << line << INFO_SUFFIX;
    std::cout << INFO_PREFIX << filename.c_str() << INFO_SEPARATOR << line << INFO_SUFFIX;
    return *this;
}

void WriterFileCout::flush()
{
    file_.flush();
    std::cout.flush();
}

void WriterFileCout::header(const char* ansi_format, const char* level_tag)
{
    // ansi_format is ignored since files are not compatible with ANSI format
    file_ << date() << level_tag;
    std::cout << ansi_format << date() << level_tag << CLEAR_FORMAT;
}

WriterFileCout& WriterFileCout::operator<<(const bool message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

WriterFileCout& WriterFileCout::operator<<(const char message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

WriterFileCout& WriterFileCout::operator<<(const unsigned char message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

WriterFileCout& WriterFileCout::operator<<(const char* message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

WriterFileCout& WriterFileCout::operator<<(const unsigned char* message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

WriterFileCout& WriterFileCout::operator<<(const short message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

WriterFileCout& WriterFileCout::operator<<(const unsigned short message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

WriterFileCout& WriterFileCout::operator<<(const int message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

WriterFileCout& WriterFileCout::operator<<(const unsigned int message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

WriterFileCout& WriterFileCout::operator<<(const float message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

WriterFileCout& WriterFileCout::operator<<(const long message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

WriterFileCout& WriterFileCout::operator<<(const unsigned long message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

WriterFileCout& WriterFileCout::operator<<(const double message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

WriterFileCout& WriterFileCout::operator<<(const long double message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

WriterFileCout& WriterFileCout::operator<<(const long long message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

WriterFileCout& WriterFileCout::operator<<(const unsigned long long message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

WriterFileCout& WriterFileCout::operator<<(const void* message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

WriterFileCout& WriterFileCout::operator<<(const std::error_code& message)
{
    // The full string should be: "(<error_code>) <error_message>"
    file_ << ERROR_CODE_PREFIX << message.value() << ERROR_CODE_SUFFIX << message.message().c_str();
    std::cout << ERROR_CODE_PREFIX << message.value() << ERROR_CODE_SUFFIX << message.message().c_str();
    return *this;
}

WriterFileCout& WriterFileCout::operator<<(const Endl&)
{
    file_ << ENDL;
    std::cout << std::endl;
    return *this;
}
} // namespace ramrod
