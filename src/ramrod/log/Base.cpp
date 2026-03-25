#include "ramrod/log/Base.hpp"

#include <cstdarg>
#include <cstdio>

namespace
{
/// @brief String used when the message is empty
static constexpr char EMPTY_MESSAGE[]{""};
} // Unnamed namespace

namespace ramrod
{
Base::Base(Writer& writer)
    : _ansi_format{EMPTY_MESSAGE},
      _level_tag{EMPTY_MESSAGE},
      _log_level{LogLevel::VERBOSE},
      _writer{writer},
      logging_enabled_{true}
{
}

Base& Base::file_info(const char* file, const int line)
{
    if (!logging_enabled_)
        return *this;

    _writer.format(_ansi_format);
    _writer.file_info(file, line);
    _writer.clear_format();
    return *this;
}

void Base::flush()
{
    if (!logging_enabled_)
        return;

    _writer.flush();
}

Base& Base::header()
{
    if (!logging_enabled_)
        return *this;

    _writer.header(_ansi_format, _level_tag);
    return *this;
}

Base& Base::log_level(const LogLevel level)
{
    logging_enabled_ = (_log_level >= level);
    return *this;
}

int Base::printf(const char* format, ...)
{
    /// @brief Size of an empty string
    static constexpr int EMPTY_STRING_SIZE{};

    if (!logging_enabled_)
        return EMPTY_STRING_SIZE;

    std::va_list args;
    va_start(args, format);
    int n{std::vsnprintf(_writer.printf_buffer(), _writer.printf_buffer_size(), format, args)};
    va_end(args);
    if (n > EMPTY_STRING_SIZE)
    {
        _writer.format(_ansi_format);
        _writer << _writer.printf_buffer();
        _writer.clear_format();
    }
    return n;
}

Base& Base::operator<<(const bool message)
{
    if (!logging_enabled_)
        return *this;

    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const char message)
{
    if (!logging_enabled_)
        return *this;

    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const unsigned char message)
{
    if (!logging_enabled_)
        return *this;

    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const char* message)
{
    if (!logging_enabled_)
        return *this;

    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const unsigned char* message)
{
    if (!logging_enabled_)
        return *this;

    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const short message)
{
    if (!logging_enabled_)
        return *this;

    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const unsigned short message)
{
    if (!logging_enabled_)
        return *this;

    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const int message)
{
    if (!logging_enabled_)
        return *this;

    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const unsigned int message)
{
    if (!logging_enabled_)
        return *this;

    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const float message)
{
    if (!logging_enabled_)
        return *this;

    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const long message)
{
    if (!logging_enabled_)
        return *this;

    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const unsigned long message)
{
    if (!logging_enabled_)
        return *this;

    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const double message)
{
    if (!logging_enabled_)
        return *this;

    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const long double message)
{
    if (!logging_enabled_)
        return *this;

    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const long long message)
{
    if (!logging_enabled_)
        return *this;

    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const unsigned long long message)
{
    if (!logging_enabled_)
        return *this;

    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const std::string& message)
{
    if (!logging_enabled_)
        return *this;

    _writer.format(_ansi_format);
    _writer << message.c_str();
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const std::string_view& message)
{
    if (!logging_enabled_)
        return *this;

    _writer.format(_ansi_format);
    _writer << message.data();
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const void* message)
{
    if (!logging_enabled_)
        return *this;

    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const std::exception& message)
{
    if (!logging_enabled_)
        return *this;

    _writer.format(_ansi_format);
    _writer << message.what();
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const std::error_code& message)
{
    if (!logging_enabled_)
        return *this;

    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const std::filesystem::path& message)
{
    if (!logging_enabled_)
        return *this;

    _writer.format(_ansi_format);
    _writer << message.c_str();
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const Endl& endl)
{
    if (!logging_enabled_)
        return *this;

    _writer << endl;
    return *this;
}
} // namespace ramrod
