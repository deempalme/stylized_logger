#ifndef RAMROD_LOG_BASE_HPP
#define RAMROD_LOG_BASE_HPP

#include <cstddef>
#include <cstdint>
#include <exception>
#include <filesystem>
#include <string>
#include <string_view>
#include <system_error>

#include "ramrod/log/BaseHeaderless.hpp"

namespace ramrod
{
    /**
     * @brief Logger that writes messages to standard output or a file with header
     *        and optional color.
     *
     * Each line is prefixed with a timestamp and a configurable head message.
     * Output can be switched at runtime via change_log_output().
     */
    class Base : public BaseHeaderless
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
         *
         * Deletes the date buffer, date format, and printf buffer.
         */
        virtual ~Base();

        /**
         * @brief Changes the date format and the size of the date buffer.
         *
         * @param date_format       The new date format, e.g. "[%Y-%m-%d %H:%M:%S %z]".
         * @param date_buffer_size  The new size of the date buffer, it must be able to contain
         *                          the longest date format, including the null terminator,
         *                          e.g. 28 for "[2026-03-01 12:00:00 +0100]".
         *
         * @return True if the date format and buffer size were changed successfully.
         *         If \p date_format is empty or \p date_buffer_size is 0, false is returned.
         *         Also it will return false if the date format or buffer size cannot be allocated.
         */
        bool change_date_format(const std::string &date_format, const size_t date_buffer_size);

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
            (*this << ... << std::forward<Args>(args));
            end();
            return *this;
        }

        /**
         * @brief Writes a boolean value to the output.
         *
         * @param message The boolean value to write.
         *
         * @return Reference to current object.
         */
        BaseHeaderless &operator<<(const bool message);

        /**
         * @brief Writes a character to the output.
         *
         * @param message The character to write.
         *
         * @return Reference to current object.
         */
        BaseHeaderless &operator<<(const char message);

        /**
         * @brief Writes a character to the output.
         *
         * @param message The character to write.
         *
         * @return Reference to current object.
         */
        BaseHeaderless &operator<<(const std::int8_t message);

        /**
         * @brief Writes an unsigned character to the output.
         *
         * @param message The unsigned character to write.
         *
         * @return Reference to current object.
         */
        BaseHeaderless &operator<<(const std::uint8_t message);

        /**
         * @brief Writes a null-terminated character string to the output.
         *
         * @param message The character string to write.
         *
         * @return Reference to current object.
         */
        BaseHeaderless &operator<<(const char *message);

        /**
         * @brief Writes a null-terminated character string to the output.
         *
         * @param message The character string to write.
         *
         * @return Reference to current object.
         */
        BaseHeaderless &operator<<(const std::int8_t *message);

        /**
         * @brief Writes a null-terminated unsigned character string to the output.
         *
         * @param message The unsigned character string to write.
         *
         * @return Reference to current object.
         */
        BaseHeaderless &operator<<(const std::uint8_t *message);

        /**
         * @brief Writes a short integer value to the output.
         *
         * @param message The short integer value to write.
         *
         * @return Reference to current object.
         */
        BaseHeaderless &operator<<(const std::int16_t message);

        /**
         * @brief Writes an unsigned short integer value to the output.
         *
         * @param message The unsigned short integer value to write.
         *
         * @return Reference to current object.
         */
        BaseHeaderless &operator<<(const std::uint16_t message);

        /**
         * @brief Writes an integer value to the output.
         *
         * @param message The integer value to write.
         *
         * @return Reference to current object.
         */
        BaseHeaderless &operator<<(const std::int32_t message);

        /**
         * @brief Writes an unsigned integer value to the output.
         *
         * @param message The unsigned integer value to write.
         *
         * @return Reference to current object.
         */
        BaseHeaderless &operator<<(const std::uint32_t message);

        /**
         * @brief Writes a float value to the output.
         *
         * @param message The float value to write.
         *
         * @return Reference to current object.
         */
        BaseHeaderless &operator<<(const float message);

        /**
         * @brief Writes a long integer value to the output.
         *
         * @param message The long integer value to write.
         *
         * @return Reference to current object.
         */
        BaseHeaderless &operator<<(const std::int64_t message);

        /**
         * @brief Writes an unsigned long integer value to the output.
         *
         * @param message The unsigned long integer value to write.
         *
         * @return Reference to current object.
         */
        BaseHeaderless &operator<<(const std::uint64_t message);

        /**
         * @brief Writes a double value to the output.
         *
         * @param message The double value to write.
         *
         * @return Reference to current object.
         */
        BaseHeaderless &operator<<(const double message);

        /**
         * @brief Writes a long double value to the output.
         *
         * @param message The long double value to write.
         *
         * @return Reference to current object.
         */
        BaseHeaderless &operator<<(const long double message);

        /**
         * @brief Writes a string to the output.
         *
         * @param message The string to write.
         *
         * @return Reference to current object.
         */
        BaseHeaderless &operator<<(const std::string &message);

        /**
         * @brief Writes a string view to the output.
         *
         * @param message The string view to write.
         *
         * @return Reference to current object.
         */
        BaseHeaderless &operator<<(const std::string_view &message);

        /**
         * @brief Writes a pointer address to the output.
         *
         * @param message The pointer to write.
         *
         * @return Reference to current object.
         */
        BaseHeaderless &operator<<(const void *message);

        /**
         * @brief Writes an exception message to the output.
         *
         * @param message The exception to write (outputs what()).
         *
         * @return Reference to current object.
         */
        BaseHeaderless &operator<<(const std::exception &message);

        /**
         * @brief Writes an error code to the output.
         *
         * @param message The error code to write.
         *
         * @return Reference to current object.
         */
        BaseHeaderless &operator<<(const std::error_code &message);

    protected:
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
        char *date_buffer_;
        /// @brief Size of the date buffer in bytes, it must be able to contain the longest
        ///        date format, including the null terminator.
        size_t date_buffer_size_;
        /// @brief Date format used to print the date and time, e.g. "[%Y-%m-%d %H:%M:%S %z]".
        char *date_format_;
        /// @brief Buffer used for printf-style formatting.
        char *printf_buffer_;
        /// @brief Size of the printf buffer in bytes.
        size_t printf_buffer_size_;
    };
} // namespace ramrod

#endif // RAMROD_LOG_BASE_HPP
