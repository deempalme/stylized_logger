#include "ramrod/log/Logger.hpp"

namespace ramrod
{
    Logger::Logger()
        : debug{},
          error{},
          info{},
          verbose{},
          warning{}
    {
    }

    Logger::Logger(const std::filesystem::path &output_path)
        : debug{output_path},
          error{output_path},
          info{output_path},
          verbose{output_path},
          warning{output_path}
    {
    }

    void Logger::change_date_format(const std::string &date_format, const size_t date_buffer_size)
    {
        debug.change_date_format(date_format, date_buffer_size);
        error.change_date_format(date_format, date_buffer_size);
        info.change_date_format(date_format, date_buffer_size);
        verbose.change_date_format(date_format, date_buffer_size);
        warning.change_date_format(date_format, date_buffer_size);
    }

    bool Logger::change_log_output(const std::filesystem::path &output_path)
    {
        return debug.change_log_output(output_path) &&
               error.change_log_output(output_path) &&
               info.change_log_output(output_path) &&
               verbose.change_log_output(output_path) &&
               warning.change_log_output(output_path);
    }

    size_t Logger::printf_buffer_size() const
    {
        return error.printf_buffer_size();
    }

    void Logger::printf_buffer_size(const size_t new_size)
    {
        debug.printf_buffer_size(new_size);
        error.printf_buffer_size(new_size);
        info.printf_buffer_size(new_size);
        verbose.printf_buffer_size(new_size);
        warning.printf_buffer_size(new_size);
    }
} // namespace ramrod