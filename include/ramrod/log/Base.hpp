#ifndef RAMROD_LOG_BASE_HPP
#define RAMROD_LOG_BASE_HPP

#include <cstddef>
#include <filesystem>
#include <memory>
#include <string>
#include <utility>

#include "ramrod/log/Output.hpp"

namespace ramrod
{
    /**
     * @brief Logger that writes messages to standard output or a file with header
     *        and optional color.
     *
     * Each line is prefixed with a timestamp and a configurable head message.
     * Output can be switched at runtime via change_log_output().
     */
    class Base
    {
    public:
        /**
         * @brief Creates a logger that saves messages to the standard output.
         */
        Base();

        /**
         * @brief Creates a logger that saves messages to a file.
         *
         * @param output_path The path to the file to save messages to.
         */
        Base(const std::filesystem::path &output_path);

        /**
         * @brief Destructor.
         */
        virtual ~Base() = default;

        /**
         * @brief Writes a log line with header (format, date, head message), forwarded arguments,
         *        and reset ANSI format.
         *
         * Header is composed of:
         * - ANSI color format which depends on the inherited class;
         *   - Error messages are red,
         *   - Warning messages are yellow,
         *   - Debug messages are blue,
         *   - Info messages are green,
         *   - Verbose messages have default color.
         * - Date
         * - Level tag message which depends on the inherited class;
         *   - Error messages are "[ERROR]",
         *   - Warning messages are "[WARNING]",
         *   - Debug messages are "[DEBUG]",
         *   - Info messages are "[INFO]",
         *   - Verbose messages are "[VERBOSE]".
         * - Forwarded arguments which are printed as is
         * - ANSI format to reset the attributes
         *
         * Output to a file will not contain the ANSI format strings (color and reset formats)
         *
         * @param args Values to write (forwarded to the output).
         *
         * @return Reference to this logger.
         */
        template <typename... Args>
        Base &operator()(Args&&... args)
        {
            output_.format(_ansi_format);
            output_(date(), _level_tag, std::forward<Args>(args)...);
            output_.end();
            return *this;
        }

        /**
         * @brief Changes the date format and the size of the date buffer.
         *
         * @param date_format       The new date format, e.g. "[%Y-%m-%d %H:%M:%S %z]".
         * @param date_buffer_size  The new size of the date buffer, it must be able to contain
         *                          the longest date format, including the null terminator,
         *                          e.g. 28 for "[2026-03-01 12:00:00 +0100]".
         */
        void change_date_format(const std::string &date_format, const size_t date_buffer_size);

        /**
         * @brief Switches log output to a new file path.
         *
         * @param output_path The path to the file to write to.
         *
         * @return True if the new output was opened successfully, false otherwise.
         */
        bool change_log_output(const std::filesystem::path &output_path);

        /**
        * @brief Prints a message to the output with std::printf style format
        *
        * It works similar to `std::printf`; `const char *format` should contain how to interpret
        * the data, look at [https://en.cppreference.com/w/cpp/io/c/fprintf]
        * (https://en.cppreference.com/w/cpp/io/c/fprintf) to see all possible formats.
        *
        * @param format  Pointer to a null-terminated multibyte string specifying how
        *                to interpret the data.
        * @param ...     Variable argument list (multiple variables, multiple types)
        *
        * @return Number of characters written if successful or negative value if an error occurred.
        */
        int printf(const char *format, ...) __attribute__((format (printf, 2, 3)));

        /**
         * @brief Returns the size of the buffer used for printf formatting.
         *
         * @return Current printf buffer size in bytes.
         */
        size_t printf_buffer_size() const;

        /**
         * @brief Sets the size of the buffer used for printf formatting.
         *
         * The default size is 1024 bytes. It is recommended to change the size for one that can
         * contain the longest message that is expected to be printed.
         *
         * @param new_size New buffer size in bytes.
         */
        void printf_buffer_size(const size_t new_size);

    protected:
        /// @brief Format in ANSI escape codes used to colorize output text
        const char *_ansi_format;
        /// @brief Logging level tag message that is printed at the beginning of each line
        ///        after the date and time
        const char *_level_tag;

    private:
        /**
         * @brief Returns the current date/time string for the log header.
         *
         * The string is formatted as "[YYYY-MM-DD HH:MM:SS +0100]".
         * The +0100 is the timezone offset, e.g. "+0100" for UTC+1.
         *
         * @return Current date/time string for the log header.
         */
        const char *date();

        /// @brief Buffer that contains the date string.
        std::unique_ptr<char> date_buffer_;
        /// @brief Size of the date buffer in bytes, it must be able to contain the longest
        ///        date format, including the null terminator.
        size_t date_buffer_size_;
        /// @brief Date format used to print the date and time, e.g. "[%Y-%m-%d %H:%M:%S %z]".
        std::string date_format_;
        /// @brief Output stream (e.g. stdout or file).
        Output output_;
        /// @brief Buffer used for printf-style formatting.
        std::unique_ptr<char> printf_buffer_;
        /// @brief Size of the printf buffer in bytes.
        size_t printf_buffer_size_;
    };
} // namespace ramrod

#endif // RAMROD_LOG_BASE_HPP
