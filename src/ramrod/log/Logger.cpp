#include "ramrod/log/Logger.hpp"

#include "ramrod/log/OutputFile.hpp"
#include "ramrod/log/OutputFileConsole.hpp"

namespace ramrod
{
const std::filesystem::path Logger::TO_CONSOLE{""};

Logger::Logger()
{
    output(OutputType::CONSOLE, TO_CONSOLE);
}

Logger::Logger(const OutputType type, const std::filesystem::path& path)
{
    output(type, path);
}

Debug& Logger::debug()
{
    return debug_;
}

Error& Logger::error()
{
    return error_;
}

Info& Logger::info()
{
    return info_;
}

Verbose& Logger::verbose()
{
    return verbose_;
}

Warning& Logger::warning()
{
    return warning_;
}

void Logger::clear()
{
    output_.clear();
}

const char* Logger::date_format() const
{
    return output_.date_format();
}

bool Logger::date_format(const std::string& date_format, const size_t date_buffer_size)
{
    return output_.date_format(date_format, date_buffer_size);
}

void Logger::end()
{
    output_.end();
}

void Logger::flush()
{
    output_.flush();
}

size_t Logger::printf_buffer_size() const
{
    return output_.printf_buffer_size();
}

void Logger::printf_buffer_size(const size_t new_size)
{
    otuput_.printf_buffer_size(new_size);
}

const std::filesystem::path& Logger::output() const
{
    return output_.output();
}

bool Logger::output(const OutputType type, const std::filesystem::path& path)
{
    const bool success{change_output(type, path)};

    // Setting the new output to all the loggers
    debug_ = Debug{output_};
    error_ = Error{output_};
    info_ = Info{output_};
    verbose_ = Verbose{output_};
    warning_ = Warning{output_};

    return success;
}

bool Logger::verify_status() const
{
    return output_.verify_status();
}

bool Logger::change_output(const OutputType type, const std::filesystem::path& path)
{
    if ((type == OutputType::FILE_AND_CONSOLE) && !path.empty())
    {
        output_ = OutputFileConsole{path};
        return output_.verify_status();
    }
    else if ((type == OutputType::FILE) && !path.empty())
    {
        output_ = OutputFile{path};
        return output_.verify_status();
    }
    else if ((type != OutputType::CONSOLE) && path.empty())
    {
        output_ = Output{};
        return false;
    }
    else
    {
        output_ = Output{};
        return true;
    }
}

static Logger global_logger{};
} // namespace ramrod