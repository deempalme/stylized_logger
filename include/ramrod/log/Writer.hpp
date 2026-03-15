#ifndef RAMROD_LOG_WRITER_HPP
#define RAMROD_LOG_WRITER_HPP

#include "ramrod/log/Endl.hpp"

#include <filesystem>
#include <string>
#include <system_error>

namespace ramrod
{
/**
 * @brief Abstract base class for writing log messages.
 *
 * Defines the interface for writing formatted messages.
 */
class Writer
{
public:
    /** @brief Default constructor. */
    Writer();

    /**
     * @brief Virtual destructor.
     *
     * Deletes the date buffer, date format, and printf buffer.
     */
    virtual ~Writer();

    /**
     * @brief Clear the output (e.g. clears the console).
     */
    virtual void clear();

    /**
     * @brief Clear the ANSI format from the output.
     */
    virtual void clear_format();

    /**
     * @brief Returns the current date/time string for the log header.
     *
     * The string is formatted as "[YYYY-MM-DD HH:MM:SS +0100]" by default.
     * The +0100 is the timezone offset, e.g. "+0100" for UTC+1.
     * The date format can be changed with \p date_format().
     *
     * @return Current date/time string for the log header.
     */
    const char* date();

    /**
     * @brief Get the current date format.
     *
     * @return The current date format.
     */
    const char* date_format() const;

    /**
     * @brief Change the date format and the size of the date buffer.
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
    bool date_format(const std::string& date_format, const size_t date_buffer_size);

    /**
     * @brief End the current line or flushes the writer.
     */
    virtual void end();

    /**
     * @brief Write the file and line information.
     *
     * @param file The file name.
     * @param line The line number.
     *
     * @return Reference to current object.
     */
    virtual Writer& file_info(const char* file, const int line);

    /**
     * @brief Flush the writer (e.g. flushes the console).
     */
    virtual void flush();

    /**
     * @brief Apply ansi format to the writer.
     *
     * @param ansi_format Null-terminated string with ANSI escape codes (e.g. for color).
     */
    virtual void format(const char* ansi_format);

    /**
     * @brief Set the header of the writer (ANSI format, date, and level tag).
     *
     * @param ansi_format  Null-terminated string with ANSI escape codes (e.g. for color).
     * @param level_tag    Null-terminated string with the level tag.
     */
    virtual void header(const char* ansi_format, const char* level_tag);

    /**
     * @brief Get the buffer used for printf formatting.
     *
     * @return Pointer to the buffer used for printf formatting.
     */
    char* printf_buffer();

    /**
     * @brief Get the size of the buffer used for printf formatting.
     *
     * @return Size of the buffer used for printf formatting in bytes.
     */
    size_t printf_buffer_size() const;

    /**
     * @brief Set the size of the buffer used for printf formatting.
     *
     * The default size is 1024 bytes. It is recommended to change the size for one that can
     * contain the longest message that is expected to be printed.
     *
     * @param new_size New buffer size in bytes.
     */
    void printf_buffer_size(const size_t new_size);

    /**
     * @brief Write a boolean value.
     *
     * @param message The boolean value to write.
     *
     * @return Reference to current object.
     */
    virtual Writer& operator<<(const bool message);

    /**
     * @brief Write a character.
     *
     * @param message The character to write.
     *
     * @return Reference to current object.
     */
    virtual Writer& operator<<(const char message);

    /**
     * @brief Write an unsigned character.
     *
     * @param message The unsigned character to write.
     *
     * @return Reference to current object.
     */
    virtual Writer& operator<<(const unsigned char message);

    /**
     * @brief Write a null-terminated character string.
     *
     * @param message The character string to write.
     *
     * @return Reference to current object.
     */
    virtual Writer& operator<<(const char* message);

    /**
     * @brief Write a null-terminated unsigned character string.
     *
     * @param message The unsigned character string to write.
     *
     * @return Reference to current object.
     */
    virtual Writer& operator<<(const unsigned char* message);

    /**
     * @brief Write a short integer value.
     *
     * @param message The short integer value to write.
     *
     * @return Reference to current object.
     */
    virtual Writer& operator<<(const short message);

    /**
     * @brief Write an unsigned short integer value.
     *
     * @param message The unsigned short integer value to write.
     *
     * @return Reference to current object.
     */
    virtual Writer& operator<<(const unsigned short message);

    /**
     * @brief Write an integer value.
     *
     * @param message The integer value to write.
     *
     * @return Reference to current object.
     */
    virtual Writer& operator<<(const int message);

    /**
     * @brief Write an unsigned integer value.
     *
     * @param message The unsigned integer value to write.
     *
     * @return Reference to current object.
     */
    virtual Writer& operator<<(const unsigned int message);

    /**
     * @brief Write a float value.
     *
     * @param message The float value to write.
     *
     * @return Reference to current object.
     */
    virtual Writer& operator<<(const float message);

    /**
     * @brief Write a long integer value.
     *
     * @param message The long integer value to write.
     *
     * @return Reference to current object.
     */
    virtual Writer& operator<<(const long message);

    /**
     * @brief Write an unsigned long integer value.
     *
     * @param message The unsigned long integer value to write.
     *
     * @return Reference to current object.
     */
    virtual Writer& operator<<(const unsigned long message);

    /**
     * @brief Write a double value.
     *
     * @param message The double value to write.
     *
     * @return Reference to current object.
     */
    virtual Writer& operator<<(const double message);

    /**
     * @brief Write a long double value.
     *
     * @param message The long double value to write.
     *
     * @return Reference to current object.
     */
    virtual Writer& operator<<(const long double message);

    /**
     * @brief Write a long long integer value.
     *
     * @param message The long long integer value to write.
     *
     * @return Reference to current object.
     */
    virtual Writer& operator<<(const long long message);

    /**
     * @brief Write an unsigned long long integer value.
     *
     * @param message The unsigned long long integer value to write.
     *
     * @return Reference to current object.
     */
    virtual Writer& operator<<(const unsigned long long message);

    /**
     * @brief Write a pointer address.
     *
     * @param message The pointer to write.
     *
     * @return Reference to current object.
     */
    virtual Writer& operator<<(const void* message);

    /**
     * @brief Writes an error code.
     *
     * @param message The error code to write.
     *
     * @return Reference to current object.
     */
    virtual Writer& operator<<(const std::error_code& message);

    /**
     * @brief Write a newline.
     *
     * @param endl A newline object to write.
     *
     * @return Reference to current object.
     */
    virtual Writer& operator<<(const Endl& endl);

protected:
    std::filesystem::path get_filename(const char* file);

private:
    /// @brief Buffer that contains the date string.
    char* date_buffer_;
    /// @brief Size of the date buffer in bytes, it must be able to contain the longest
    ///        date format, including the null terminator.
    size_t date_buffer_size_;
    /// @brief Date format used to print the date and time, e.g. "[%Y-%m-%d %H:%M:%S %z]".
    char* date_format_;
    /// @brief Buffer used for printf-style formatting.
    char* printf_buffer_;
    /// @brief Size of the printf buffer in bytes.
    size_t printf_buffer_size_;
};
} // namespace ramrod

#endif // RAMROD_LOG_WRITER_HPP
