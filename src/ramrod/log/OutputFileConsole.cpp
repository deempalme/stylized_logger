#include "ramrod/log/OutputFileConsole.hpp"

#include "ramrod/log/Constants.hpp"

namespace ramrod
{
OutputFileConsole::OutputFileConsole(const std::filesystem::path& filepath)
    : file_{filepath, std::ios_base::out | std::ios_base::app}, filepath_{filepath},
      is_open_{file_.is_open()}
{
}

OutputFileConsole::~OutputFileConsole()
{
    close();
}

void OutputFileConsole::clear()
{
    close();
    file_.open(filepath_, std::ios_base::out | std::ios_base::trunc);
    is_open_ = file_.is_open();
    std::cout << CLEAR_TERMINAL;
}

void OutputFileConsole::clear_format()
{
    std::cout << CLEAR_FORMAT;
}

void OutputFileConsole::end()
{
    // Nothing to do with ANSI format since files are not compatible with it, just
    // adding a new line to the end of the file
    file_ << ENDL;
    std::cout << CLEAR_FORMAT << std::endl;
}

OutputFileConsole& OutputFileConsole::file_info(const char* file, const int line)
{
    file_ << INFO_PREFIX << file << INFO_SEPARATOR << line << INFO_SUFFIX;
    std::cout << INFO_PREFIX << file << INFO_SEPARATOR << line << INFO_SUFFIX;
    return *this;
}

void OutputFileConsole::flush()
{
    file_.flush();
    std::cout.flush();
}

void OutputFileConsole::format(const char* ansi_format)
{
    std::cout << ansi_format;
}

void OutputFileConsole::header(const char* ansi_format, const char* date, const char* level_tag)
{
    // ansi_format is ignored since files are not compatible with ANSI format
    file_ << date << level_tag;
    std::cout << ansi_format << date << level_tag;
}

bool OutputFileConsole::verify_status()
{
    // If file was properly opened but then was deleted, reopen it.
    if (is_open_ && !std::filesystem::exists(filepath_))
    {
        close();
        file_.open(filepath_, std::ios_base::out | std::ios_base::app);
        is_open_ = file_.is_open();
    }
    return is_open_;
}

OutputFileConsole& OutputFileConsole::operator<<(const bool message)
{
    file_ << message;
    return *this;
}

OutputFileConsole& OutputFileConsole::operator<<(const char message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

OutputFileConsole& OutputFileConsole::operator<<(const std::int8_t message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

OutputFileConsole& OutputFileConsole::operator<<(const std::uint8_t message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

OutputFileConsole& OutputFileConsole::operator<<(const char* message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

OutputFileConsole& OutputFileConsole::operator<<(const std::int8_t* message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

OutputFileConsole& OutputFileConsole::operator<<(const std::uint8_t* message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

OutputFileConsole& OutputFileConsole::operator<<(const std::int16_t message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

OutputFileConsole& OutputFileConsole::operator<<(const std::uint16_t message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

OutputFileConsole& OutputFileConsole::operator<<(const std::int32_t message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

OutputFileConsole& OutputFileConsole::operator<<(const std::uint32_t message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

OutputFileConsole& OutputFileConsole::operator<<(const float message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

OutputFileConsole& OutputFileConsole::operator<<(const std::int64_t message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

OutputFileConsole& OutputFileConsole::operator<<(const std::uint64_t message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

OutputFileConsole& OutputFileConsole::operator<<(const double message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

OutputFileConsole& OutputFileConsole::operator<<(const long double message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

OutputFileConsole& OutputFileConsole::operator<<(const std::string& message)
{
    file_ << message.c_str();
    std::cout << message;
    return *this;
}

OutputFileConsole& OutputFileConsole::operator<<(const std::string_view& message)
{
    file_ << message.data();
    std::cout << message;
    return *this;
}

OutputFileConsole& OutputFileConsole::operator<<(const void* message)
{
    file_ << message;
    std::cout << message;
    return *this;
}

OutputFileConsole& OutputFileConsole::operator<<(const std::exception& message)
{
    file_ << message.what();
    std::cout << message;
    return *this;
}

OutputFileConsole& OutputFileConsole::operator<<(const std::error_code& message)
{
    // The full string should be: "(<error_code>) <error_message>"
    file_ << ERROR_PREFIX << message.value() << ERROR_SUFFIX << message.message().c_str();
    std::cout << ERROR_PREFIX << message.value() << ERROR_SUFFIX << message.message().c_str();
    return *this;
}

void OutputFileConsole::close()
{
    if (file_.is_open())
    {
        file_.close();
    }
    is_open_ = false;
}
} // namespace ramrod
