#include "ramrod/log/Base.hpp"

#include <ctime>
#include <cstdarg>
#include <cstdio>

#include "ramrod/log/OutputFile.hpp"

/// @brief String used when the message is empty
static constexpr char EMPTY_MESSAGE[]{""};
/// @brief Size of the date buffer, string should contain "[2026-03-01 12:00:00 +0100]",
///        hence it is 28 characters long, including the null terminator
static constexpr size_t DATE_DEFAULT_BUFFER_SIZE{28ul};
/// @brief Format used to print the date and time, e.g. "[2026-03-01 12:00:00 +0100]"
static constexpr char DATE_DEFAULT_FORMAT[]{"[%Y-%m-%d %H:%M:%S %z]"};
/// @brief String used when no format is necessary
static constexpr char NO_FORMAT[]{""};
/// @brief Size of the printf buffer
static constexpr size_t PRINTF_BUFFER_DEFAULT_SIZE{1024ul};

namespace ramrod
{
    Base::Base()
        : _ansi_format{NO_FORMAT},
          _level_tag{EMPTY_MESSAGE},
          date_buffer_{std::make_unique<char>(DATE_DEFAULT_BUFFER_SIZE)},
          date_buffer_size_{DATE_DEFAULT_BUFFER_SIZE},
          date_format_{DATE_DEFAULT_FORMAT},
          output_{},
          printf_buffer_{std::make_unique<char>(PRINTF_BUFFER_DEFAULT_SIZE)},
          printf_buffer_size_{PRINTF_BUFFER_DEFAULT_SIZE}
    {
    }

    Base::Base(const std::filesystem::path &output_path)
        : _ansi_format{NO_FORMAT},
          _level_tag{EMPTY_MESSAGE},
          date_buffer_{std::make_unique<char>(DATE_DEFAULT_BUFFER_SIZE)},
          date_buffer_size_{DATE_DEFAULT_BUFFER_SIZE},
          date_format_{DATE_DEFAULT_FORMAT},
          output_{OutputFile(output_path)},
          printf_buffer_{std::make_unique<char>(PRINTF_BUFFER_DEFAULT_SIZE)},
          printf_buffer_size_{PRINTF_BUFFER_DEFAULT_SIZE}
    {
    }

    void Base::change_date_format(const std::string &date_format, const size_t date_buffer_size)
    {
        date_format_ = date_format;
        date_buffer_size_ = date_buffer_size;
        date_buffer_ = std::make_unique<char>(date_buffer_size_);
    }

    bool Base::change_log_output(const std::filesystem::path &output_path)
    {
        output_ = OutputFile{output_path};
        return output_.verify_status();
    }

    int Base::printf(const char *format, ...)
    {
        std::va_list args;
        va_start(args, format);
        int n{std::vsnprintf(printf_buffer_.get(), printf_buffer_size_, format, args)};
        va_end(args);
        /// @brief Size of an empty string
        static constexpr int EMPTY_STRING_SIZE{};
        if (n > EMPTY_STRING_SIZE){
            output_.format(_ansi_format);
            output_(date(), _level_tag, printf_buffer_.get());
            output_.end();
        }
        return n;
    }

    size_t Base::printf_buffer_size() const
    {
        return printf_buffer_size_;
    }

    void Base::printf_buffer_size(const size_t new_size)
    {
        printf_buffer_ = std::make_unique<char>(new_size);
        printf_buffer_size_ = new_size;
    }

    const char *Base::date()
    {
        const std::time_t t{std::time(nullptr)};
        std::strftime(date_buffer_.get(),
                      date_buffer_size_,
                      date_format_.c_str(),
                      std::localtime(&t));
        return date_buffer_.get();
    }
} // namespace ramrod
