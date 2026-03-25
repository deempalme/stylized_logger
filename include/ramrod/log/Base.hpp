#ifndef RAMROD_LOG_BASE_HPP
#define RAMROD_LOG_BASE_HPP

#include "ramrod/log/Endl.hpp"
#include "ramrod/log/Enumerators.hpp"
#include "ramrod/log/Writer.hpp"

#include <exception>
#include <filesystem>
#include <string>
#include <string_view>
#include <system_error>

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
     * @brief Create a logger that uses the given writer object.
     *
     * @param writer The object used to write messages.
     */
    Base(Writer& writer);

    /**
     * @brief Default destructor.
     */
    virtual ~Base() = default;

    /**
     * @brief Write the file and line information.
     *
     * @param file The file name.
     * @param line The line number.
     *
     * @return Reference to current object.
     */
    Base& file_info(const char* file, const int line);

    /**
     * @brief Flush the writer (e.g. flushes the console).
     *
     * Flushes the writer to ensure that the message is written.
     */
    void flush();

    /**
     * @brief Set the header of the writer (ANSI format, date, and level tag).
     */
    Base& header();

    /**
     * @brief Set the log level.
     *
     * @param level The log level.
     *
     * @return Reference to current object.
     */
    Base& log_level(const LogLevel level = LogLevel::VERBOSE);

    /**
     * @brief Print a message to the writer with std::printf style format
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
    int printf(const char* format, ...) __attribute__((format(printf, 2, 3)));

    /**
     * @brief Write a boolean value.
     *
     * @param message The boolean value to write.
     *
     * @return Reference to current object.
     */
    Base& operator<<(const bool message);

    /**
     * @brief Write a character.
     *
     * @param message The character to write.
     *
     * @return Reference to current object.
     */
    Base& operator<<(const char message);

    /**
     * @brief Write an unsigned character.
     *
     * @param message The unsigned character to write.
     *
     * @return Reference to current object.
     */
    Base& operator<<(const unsigned char message);

    /**
     * @brief Write a null-terminated character string.
     *
     * @param message The character string to write.
     *
     * @return Reference to current object.
     */
    Base& operator<<(const char* message);

    /**
     * @brief Write a null-terminated unsigned character string.
     *
     * @param message The unsigned character string to write.
     *
     * @return Reference to current object.
     */
    Base& operator<<(const unsigned char* message);

    /**
     * @brief Write a short integer value.
     *
     * @param message The short integer value to write.
     *
     * @return Reference to current object.
     */
    Base& operator<<(const short message);

    /**
     * @brief Write an unsigned short integer value.
     *
     * @param message The unsigned short integer value to write.
     *
     * @return Reference to current object.
     */
    Base& operator<<(const unsigned short message);

    /**
     * @brief Write an integer value.
     *
     * @param message The integer value to write.
     *
     * @return Reference to current object.
     */
    Base& operator<<(const int message);

    /**
     * @brief Write an unsigned integer value.
     *
     * @param message The unsigned integer value to write.
     *
     * @return Reference to current object.
     */
    Base& operator<<(const unsigned int message);

    /**
     * @brief Write a float value.
     *
     * @param message The float value to write.
     *
     * @return Reference to current object.
     */
    Base& operator<<(const float message);

    /**
     * @brief Write a long integer value.
     *
     * @param message The long integer value to write.
     *
     * @return Reference to current object.
     */
    Base& operator<<(const long message);

    /**
     * @brief Write an unsigned long integer value.
     *
     * @param message The unsigned long integer value to write.
     *
     * @return Reference to current object.
     */
    Base& operator<<(const unsigned long message);

    /**
     * @brief Write a double value.
     *
     * @param message The double value to write.
     *
     * @return Reference to current object.
     */
    Base& operator<<(const double message);

    /**
     * @brief Write a long double value.
     *
     * @param message The long double value to write.
     *
     * @return Reference to current object.
     */
    Base& operator<<(const long double message);

    /**
     * @brief Write a long long integer value.
     *
     * @param message The long long integer value to write.
     *
     * @return Reference to current object.
     */
    Base& operator<<(const long long message);

    /**
     * @brief Write an unsigned long long integer value.
     *
     * @param message The unsigned long long integer value to write.
     *
     * @return Reference to current object.
     */
    Base& operator<<(const unsigned long long message);

    /**
     * @brief Write a string.
     *
     * @param message The string to write.
     *
     * @return Reference to current object.
     */
    Base& operator<<(const std::string& message);

    /**
     * @brief Write a string view.
     *
     * @param message The string view to write.
     *
     * @return Reference to current object.
     */
    Base& operator<<(const std::string_view& message);

    /**
     * @brief Write a pointer address.
     *
     * @param message The pointer to write.
     *
     * @return Reference to current object.
     */
    Base& operator<<(const void* message);

    /**
     * @brief Write an exception message.
     *
     * @param message The exception to write (outputs what()).
     *
     * @return Reference to current object.
     */
    Base& operator<<(const std::exception& message);

    /**
     * @brief Write an error code.
     *
     * @param message The error code to write.
     *
     * @return Reference to current object.
     */
    Base& operator<<(const std::error_code& message);

    /**
     * @brief Write a filesystem path.
     *
     * @param message The filesystem path to write.
     *
     * @return Reference to current object.
     */
    Base& operator<<(const std::filesystem::path& message);

    /**
     * @brief Write a newline.
     *
     * @param endl A newline object to write.
     *
     * @return Reference to current object.
     */
    Base& operator<<(const Endl& endl);

protected:
    /// @brief Format in ANSI escape codes used to colorize text
    const char* _ansi_format;
    /// @brief Logging level tag message that is printed at the beginning of each line
    ///        after the date and time
    const char* _level_tag;
    /// @brief Log level
    LogLevel _log_level;
    /// @brief Object used to write messages
    Writer& _writer;

private:
    /// @brief Flag indicating if logging is enabled based on the logging level
    bool logging_enabled_;
};
} // namespace ramrod

#endif // RAMROD_LOG_BASE_HPP
