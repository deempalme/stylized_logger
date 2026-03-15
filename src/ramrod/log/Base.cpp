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
      _writer{writer}
{
}

Base& Base::file_info(const char* file, const int line)
{
    _writer.format(_ansi_format);
    _writer.file_info(file, line);
    _writer.clear_format();
    return *this;
}

void Base::flush()
{
    _writer.flush();
}

Base& Base::header()
{
    _writer.header(_ansi_format, _level_tag);
    return *this;
}

int Base::printf(const char* format, ...)
{
    std::va_list args;
    va_start(args, format);
    int n{std::vsnprintf(_writer.printf_buffer(), _writer.printf_buffer_size(), format, args)};
    va_end(args);
    /// @brief Size of an empty string
    static constexpr int EMPTY_STRING_SIZE{};
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
    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const char message)
{
    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const unsigned char message)
{
    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const char* message)
{
    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const unsigned char* message)
{
    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const short message)
{
    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const unsigned short message)
{
    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const int message)
{
    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const unsigned int message)
{
    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const float message)
{
    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const long message)
{
    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const unsigned long message)
{
    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const double message)
{
    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const long double message)
{
    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const long long message)
{
    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const unsigned long long message)
{
    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const std::string& message)
{
    _writer.format(_ansi_format);
    _writer << message.c_str();
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const std::string_view& message)
{
    _writer.format(_ansi_format);
    _writer << message.data();
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const void* message)
{
    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const std::exception& message)
{
    _writer.format(_ansi_format);
    _writer << message.what();
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const std::error_code& message)
{
    _writer.format(_ansi_format);
    _writer << message;
    _writer.clear_format();
    return *this;
}

Base& Base::operator<<(const Endl& endl)
{
    _writer << endl;
    return *this;
}
} // namespace ramrod
