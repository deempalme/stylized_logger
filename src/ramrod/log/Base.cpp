#include "ramrod/log/Base.hpp"

#include <ctime>
#include <cstdarg>
#include <cstdio>

namespace
{
    /// @brief String used to clear all ANSI format
    static constexpr char CLEAR_FORMAT[]{""};
} // Unnamed namespace

namespace ramrod
{
    Output Base::output_;

    BaseHeaderless &Base::operator()()
    {
        const std::time_t t{std::time(nullptr)};
        // output_ << style_ << std::put_time(std::localtime(&t), "[%Y-%m-%d %H:%M:%S]")
        //         << level_string(level_) << CLEAR_FORMAT;
        std::tm *tm = std::localtime(&t);
        char buf[32];
        std::strftime(buf, sizeof(buf), "[%Y-%m-%d %H:%M:%S]", tm);
        output_ << _ansi_format << buf << CLEAR_FORMAT;
        return *this;
    }

    BaseHeaderless &Base::operator()(const char *format, ...)
    {
        std::va_list args;
        va_start(args, format);
        char buf[1024];
        std::vsnprintf(buf, sizeof(buf), format, args);
        va_end(args);
        output_ << buf;
        return *this;
    }

    Base::Base()
        : BaseHeaderless(),
          _ansi_format{""}
    {
    }

    Base::Base(const std::filesystem::path &output_path)
        : BaseHeaderless(output_path),
          _ansi_format{""}
    {
    }

    int Base::printf(const char *format, ...)
    {
        std::va_list args;
        va_start(args, format);
        char buf[1024];
        int n = std::vsnprintf(buf, sizeof(buf), format, args);
        va_end(args);
        if (n > 0)
            output_ << buf;
        return n;
    }

    BaseHeaderless &Base::operator<<(const bool message)
    {
        BaseHeaderless::operator()(_ansi_format) << message;
        return *this;
    }

    BaseHeaderless &Base::operator<<(const std::int8_t message)
    {
        BaseHeaderless::operator()(_ansi_format) << message;
        return *this;
    }

    BaseHeaderless &Base::operator<<(const std::int8_t *message)
    {
        BaseHeaderless::operator()(_ansi_format) << message;
        return *this;
    }

    BaseHeaderless &Base::operator<<(const std::uint8_t message)
    {
        BaseHeaderless::operator()(_ansi_format) << message;
        return *this;
    }

    BaseHeaderless &Base::operator<<(const std::uint8_t *message)
    {
        BaseHeaderless::operator()(_ansi_format) << message;
        return *this;
    }

    BaseHeaderless &Base::operator<<(const std::int16_t message)
    {
        BaseHeaderless::operator()(_ansi_format) << message;
        return *this;
    }

    BaseHeaderless &Base::operator<<(const std::uint16_t message)
    {
        BaseHeaderless::operator()(_ansi_format) << message;
        return *this;
    }

    BaseHeaderless &Base::operator<<(const std::int32_t message)
    {
        BaseHeaderless::operator()(_ansi_format) << message;
        return *this;
    }

    BaseHeaderless &Base::operator<<(const std::uint32_t message)
    {
        BaseHeaderless::operator()(_ansi_format) << message;
        return *this;
    }

    BaseHeaderless &Base::operator<<(const float message)
    {
        BaseHeaderless::operator()(_ansi_format) << message;
        return *this;
    }

    BaseHeaderless &Base::operator<<(const std::int64_t message)
    {
        BaseHeaderless::operator()(_ansi_format) << message;
        return *this;
    }

    BaseHeaderless &Base::operator<<(const std::uint64_t message)
    {
        BaseHeaderless::operator()(_ansi_format) << message;
        return *this;
    }

    BaseHeaderless &Base::operator<<(const double message)
    {
        BaseHeaderless::operator()(_ansi_format) << message;
        return *this;
    }

    BaseHeaderless &Base::operator<<(const long double message)
    {
        BaseHeaderless::operator()(_ansi_format) << message;
        return *this;
    }

    BaseHeaderless &Base::operator<<(const std::string &message)
    {
        BaseHeaderless::operator()(_ansi_format) << message;
        return *this;
    }

    BaseHeaderless &Base::operator<<(const std::string_view &message)
    {
        BaseHeaderless::operator()(_ansi_format) << message;
        return *this;
    }

    BaseHeaderless &Base::operator<<(const void *message)
    {
        BaseHeaderless::operator()(_ansi_format) << message;
        return *this;
    }

    BaseHeaderless &Base::operator<<(const std::exception &message)
    {
        BaseHeaderless::operator()(_ansi_format) << message;
        return *this;
    }

    BaseHeaderless &Base::operator<<(const std::error_code &message)
    {
        BaseHeaderless::operator()(_ansi_format) << message;
        return *this;
    }
} // namespace ramrod
