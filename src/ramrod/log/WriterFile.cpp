#include "ramrod/log/WriterFile.hpp"

#include "Constants.hpp"

namespace ramrod
{
WriterFile::WriterFile(File& file)
    : Writer{},
      file_{file}
{
}

void WriterFile::clear()
{
    file_.clear();
}

void WriterFile::clear_format()
{
    // Do nothing since files are not compatible with ANSI format
}

void WriterFile::end()
{
    // Nothing to do with ANSI format since files are not compatible with it, just
    // adding a new line to the end of the file
    file_ << ENDL;
}

WriterFile& WriterFile::file_info(const char* file, const int line)
{
    const std::filesystem::path filename{Writer::get_filename(file)};
    file_ << INFO_PREFIX << filename.c_str() << INFO_SEPARATOR << line << INFO_SUFFIX;
    return *this;
}

void WriterFile::flush()
{
    file_.flush();
}

void WriterFile::format(const char*)
{
    // Do nothing since files are not compatible with ANSI format
}

void WriterFile::header(const char*, const char* level_tag)
{
    // ansi_format is ignored since files are not compatible with ANSI format
    file_ << date() << level_tag;
}

WriterFile& WriterFile::operator<<(const bool message)
{
    file_ << message;
    return *this;
}

WriterFile& WriterFile::operator<<(const char message)
{
    file_ << message;
    return *this;
}

WriterFile& WriterFile::operator<<(const unsigned char message)
{
    file_ << message;
    return *this;
}

WriterFile& WriterFile::operator<<(const char* message)
{
    file_ << message;
    return *this;
}

WriterFile& WriterFile::operator<<(const unsigned char* message)
{
    file_ << message;
    return *this;
}

WriterFile& WriterFile::operator<<(const short message)
{
    file_ << message;
    return *this;
}

WriterFile& WriterFile::operator<<(const unsigned short message)
{
    file_ << message;
    return *this;
}

WriterFile& WriterFile::operator<<(const int message)
{
    file_ << message;
    return *this;
}

WriterFile& WriterFile::operator<<(const unsigned int message)
{
    file_ << message;
    return *this;
}

WriterFile& WriterFile::operator<<(const float message)
{
    file_ << message;
    return *this;
}

WriterFile& WriterFile::operator<<(const long message)
{
    file_ << message;
    return *this;
}

WriterFile& WriterFile::operator<<(const unsigned long message)
{
    file_ << message;
    return *this;
}

WriterFile& WriterFile::operator<<(const double message)
{
    file_ << message;
    return *this;
}

WriterFile& WriterFile::operator<<(const long double message)
{
    file_ << message;
    return *this;
}

WriterFile& WriterFile::operator<<(const long long message)
{
    file_ << message;
    return *this;
}

WriterFile& WriterFile::operator<<(const unsigned long long message)
{
    file_ << message;
    return *this;
}

WriterFile& WriterFile::operator<<(const void* message)
{
    file_ << message;
    return *this;
}

WriterFile& WriterFile::operator<<(const std::error_code& message)
{
    // The full string should be: "(<error_code>) <error_message>"
    file_ << ERROR_CODE_PREFIX << message.value() << ERROR_CODE_SUFFIX << message.message().c_str();
    return *this;
}

WriterFile& WriterFile::operator<<(const Endl&)
{
    file_ << ENDL;
    return *this;
}
} // namespace ramrod
