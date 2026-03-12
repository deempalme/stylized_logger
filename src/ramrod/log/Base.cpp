#include "ramrod/log/Base.hpp"

#include <ctime>
#include <cstdarg>
#include <cstdio>
#include <cstring>

#include "ramrod/log/OutputFile.hpp"

/// @brief String used when the message is empty
static constexpr char EMPTY_MESSAGE[]{""};
/// @brief Size of the date buffer, string should contain "[2026-03-01 12:00:00 +0100]",
///        hence it is 28 characters long, including the null terminator
static constexpr size_t DATE_DEFAULT_BUFFER_SIZE{28ul};
/// @brief Format used to print the date and time, e.g. "[2026-03-01 12:00:00 +0100]"
static constexpr char DATE_DEFAULT_FORMAT[]{"[%Y-%m-%d %H:%M:%S %z]"};
/// @brief Size of the printf buffer
static constexpr size_t PRINTF_BUFFER_DEFAULT_SIZE{1024ul};

namespace ramrod
{
    Base::Base()
        : BaseHeaderless{},
          _level_tag{EMPTY_MESSAGE},
          date_buffer_{},
          date_buffer_size_{},
          date_format_{},
          printf_buffer_{new char[PRINTF_BUFFER_DEFAULT_SIZE]},
          printf_buffer_size_{PRINTF_BUFFER_DEFAULT_SIZE}
    {
        change_date_format(DATE_DEFAULT_FORMAT, DATE_DEFAULT_BUFFER_SIZE);
    }

    Base::Base(const std::filesystem::path &output_path)
        : BaseHeaderless{output_path},
          _level_tag{EMPTY_MESSAGE},
          date_buffer_{},
          date_buffer_size_{},
          date_format_{},
          printf_buffer_{new char[PRINTF_BUFFER_DEFAULT_SIZE]},
          printf_buffer_size_{PRINTF_BUFFER_DEFAULT_SIZE}
    {
        change_date_format(DATE_DEFAULT_FORMAT, DATE_DEFAULT_BUFFER_SIZE);
    }

    Base::~Base()
    {
        if (date_buffer_ != nullptr)
            delete[] date_buffer_;
        if (date_format_ != nullptr)
            delete[] date_format_;
        if (printf_buffer_ != nullptr)
            delete[] printf_buffer_;
    }

    bool Base::change_date_format(const std::string &date_format, const size_t date_buffer_size)
    {
        if (date_format.empty() || (date_buffer_size == 0))
            return false;

        if (date_format_ != nullptr)
            delete[] date_format_;
        /// @brief Padding to ensure the string is null-terminated
        static constexpr size_t STRING_PADDING{1ul};
        date_format_ = new char[date_format.size() + STRING_PADDING];
        std::strncpy(date_format_, date_format.c_str(), date_format.size());

        date_buffer_size_ = date_buffer_size;
        if (date_buffer_ != nullptr)
            delete[] date_buffer_;
        date_buffer_ = new char[date_buffer_size_];

        return (date_format_ != nullptr) && (date_buffer_ != nullptr);
    }

    bool Base::change_log_output(const std::filesystem::path &output_path)
    {
        BaseHeaderless::output = OutputFile{output_path};
        return verify_status();
    }

    int Base::printf(const char *format, ...)
    {
        std::va_list args;
        va_start(args, format);
        int n{std::vsnprintf(printf_buffer_, printf_buffer_size_, format, args)};
        va_end(args);
        /// @brief Size of an empty string
        static constexpr int EMPTY_STRING_SIZE{};
        if (n > EMPTY_STRING_SIZE){
            header(_ansi_format, date(), _level_tag);
            BaseHeaderless::operator<<(printf_buffer_);
            end();
        }
        return n;
    }

    size_t Base::printf_buffer_size() const
    {
        return printf_buffer_size_;
    }

    void Base::printf_buffer_size(const size_t new_size)
    {
        if (printf_buffer_ != nullptr)
            delete[] printf_buffer_;
        printf_buffer_ = new char[new_size];
        printf_buffer_size_ = new_size;
    }

    BaseHeaderless &Base::operator<<(const bool message)
    {
        header(_ansi_format, date(), _level_tag);
        return BaseHeaderless::operator<<(message);
    }

    BaseHeaderless &Base::operator<<(const char message)
    {
        header(_ansi_format, date(), _level_tag);
        return BaseHeaderless::operator<<(message);
    }

    BaseHeaderless &Base::operator<<(const std::int8_t message)
    {
        header(_ansi_format, date(), _level_tag);
        return BaseHeaderless::operator<<(message);
    }

    BaseHeaderless &Base::operator<<(const std::uint8_t message)
    {
        header(_ansi_format, date(), _level_tag);
        return BaseHeaderless::operator<<(message);
    }

    BaseHeaderless &Base::operator<<(const char *message)
    {
        header(_ansi_format, date(), _level_tag);
        return BaseHeaderless::operator<<(message);
    }

    BaseHeaderless &Base::operator<<(const std::int8_t *message)
    {
        header(_ansi_format, date(), _level_tag);
        return BaseHeaderless::operator<<(message);
    }

    BaseHeaderless &Base::operator<<(const std::uint8_t *message)
    {
        header(_ansi_format, date(), _level_tag);
        return BaseHeaderless::operator<<(message);
    }

    BaseHeaderless &Base::operator<<(const std::int16_t message)
    {
        header(_ansi_format, date(), _level_tag);
        return BaseHeaderless::operator<<(message);
    }

    BaseHeaderless &Base::operator<<(const std::uint16_t message)
    {
        header(_ansi_format, date(), _level_tag);
        return BaseHeaderless::operator<<(message);
    }

    BaseHeaderless &Base::operator<<(const std::int32_t message)
    {
        header(_ansi_format, date(), _level_tag);
        return BaseHeaderless::operator<<(message);
    }

    BaseHeaderless &Base::operator<<(const std::uint32_t message)
    {
        header(_ansi_format, date(), _level_tag);
        return BaseHeaderless::operator<<(message);
    }

    BaseHeaderless &Base::operator<<(const float message)
    {
        header(_ansi_format, date(), _level_tag);
        return BaseHeaderless::operator<<(message);
    }

    BaseHeaderless &Base::operator<<(const std::int64_t message)
    {
        header(_ansi_format, date(), _level_tag);
        return BaseHeaderless::operator<<(message);
    }

    BaseHeaderless &Base::operator<<(const std::uint64_t message)
    {
        header(_ansi_format, date(), _level_tag);
        return BaseHeaderless::operator<<(message);
    }

    BaseHeaderless &Base::operator<<(const double message)
    {
        header(_ansi_format, date(), _level_tag);
        return BaseHeaderless::operator<<(message);
    }

    BaseHeaderless &Base::operator<<(const long double message)
    {
        header(_ansi_format, date(), _level_tag);
        return BaseHeaderless::operator<<(message);
    }

    BaseHeaderless &Base::operator<<(const std::string &message)
    {
        header(_ansi_format, date(), _level_tag);
        return BaseHeaderless::operator<<(message);
    }

    BaseHeaderless &Base::operator<<(const std::string_view &message)
    {
        header(_ansi_format, date(), _level_tag);
        return BaseHeaderless::operator<<(message);
    }

    BaseHeaderless &Base::operator<<(const void *message)
    {
        header(_ansi_format, date(), _level_tag);
        return BaseHeaderless::operator<<(message);
    }

    BaseHeaderless &Base::operator<<(const std::exception &message)
    {
        header(_ansi_format, date(), _level_tag);
        return BaseHeaderless::operator<<(message);
    }

    BaseHeaderless &Base::operator<<(const std::error_code &message)
    {
        header(_ansi_format, date(), _level_tag);
        return BaseHeaderless::operator<<(message);
    }

    const char *Base::date()
    {
        const std::time_t t{std::time(nullptr)};
        std::strftime(date_buffer_,
                      date_buffer_size_,
                      date_format_,
                      std::localtime(&t));
        return date_buffer_;
    }
} // namespace ramrod
