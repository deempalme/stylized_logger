#ifndef RAMROD_LOG_OUTPUT_HPP
#define RAMROD_LOG_OUTPUT_HPP

#include <cstdint>
#include <exception>
#include <string>
#include <string_view>
#include <system_error>

namespace ramrod
{
/**
 * @brief Abstract base class for log output.
 *
 * Defines the interface for writing formatted messages to an output destination.
 * Concrete implementations may write to standard output, a file, or other sinks.
 */
class Output
{
  public:
    /** @brief Default constructor. */
    Output() = default;

    /** @brief Virtual destructor. */
    virtual ~Output() = default;

    /**
     * @brief Clear the output (e.g. clears the console).
     */
    virtual void clear();

    /**
     * @brief Clear the ANSI format from the output.
     */
    virtual void clear_format();

    /**
     * @brief End the current line or flushes the output.
     */
    virtual void end();

    /**
     * @brief Write the file and line information to the output.
     *
     * @param file The file name.
     * @param line The line number.
     *
     * @return Reference to current object.
     */
    virtual Output& file_info(const char* file, const int line);

    /**
     * @brief Flush the output (e.g. flushes the console).
     */
    virtual void flush();

    /**
     * @brief Apply ansi format to the output.
     *
     * @param ansi_format Null-terminated string with ANSI escape codes (e.g. for color).
     */
    virtual void format(const char* ansi_format);

    /**
     * @brief Set the header of the output (ANSI format, date, and level tag).
     *
     * @param ansi_format  Null-terminated string with ANSI escape codes (e.g. for color).
     * @param date         Null-terminated string with the date and time.
     * @param level_tag    Null-terminated string with the level tag.
     */
    virtual void header(const char* ansi_format, const char* date, const char* level_tag);

    /**
     * @brief Check if the output is valid.
     *
     * @return True if the output is valid, false otherwise.
     */
    virtual bool verify_status();

    /**
     * @brief Write a boolean value to the output.
     *
     * @param message The boolean value to write.
     *
     * @return Reference to current object.
     */
    virtual Output& operator<<(const bool message);

    /**
     * @brief Write a character to the output.
     *
     * @param message The character to write.
     *
     * @return Reference to current object.
     */
    virtual Output& operator<<(const char message);

    /**
     * @brief Write a character to the output.
     *
     * @param message The character to write.
     *
     * @return Reference to current object.
     */
    virtual Output& operator<<(const std::int8_t message);

    /**
     * @brief Write an unsigned character to the output.
     *
     * @param message The unsigned character to write.
     *
     * @return Reference to current object.
     */
    virtual Output& operator<<(const std::uint8_t message);

    /**
     * @brief Write a null-terminated character string to the output.
     *
     * @param message The character string to write.
     *
     * @return Reference to current object.
     */
    virtual Output& operator<<(const char* message);

    /**
     * @brief Write a null-terminated character string to the output.
     *
     * @param message The character string to write.
     *
     * @return Reference to current object.
     */
    virtual Output& operator<<(const std::int8_t* message);

    /**
     * @brief Write a null-terminated unsigned character string to the output.
     *
     * @param message The unsigned character string to write.
     *
     * @return Reference to current object.
     */
    virtual Output& operator<<(const std::uint8_t* message);

    /**
     * @brief Write a short integer value to the output.
     *
     * @param message The short integer value to write.
     *
     * @return Reference to current object.
     */
    virtual Output& operator<<(const std::int16_t message);

    /**
     * @brief Write an unsigned short integer value to the output.
     *
     * @param message The unsigned short integer value to write.
     *
     * @return Reference to current object.
     */
    virtual Output& operator<<(const std::uint16_t message);

    /**
     * @brief Write an integer value to the output.
     *
     * @param message The integer value to write.
     *
     * @return Reference to current object.
     */
    virtual Output& operator<<(const std::int32_t message);

    /**
     * @brief Write an unsigned integer value to the output.
     *
     * @param message The unsigned integer value to write.
     *
     * @return Reference to current object.
     */
    virtual Output& operator<<(const std::uint32_t message);

    /**
     * @brief Write a float value to the output.
     *
     * @param message The float value to write.
     *
     * @return Reference to current object.
     */
    virtual Output& operator<<(const float message);

    /**
     * @brief Write a long integer value to the output.
     *
     * @param message The long integer value to write.
     *
     * @return Reference to current object.
     */
    virtual Output& operator<<(const std::int64_t message);

    /**
     * @brief Write an unsigned long integer value to the output.
     *
     * @param message The unsigned long integer value to write.
     *
     * @return Reference to current object.
     */
    virtual Output& operator<<(const std::uint64_t message);

    /**
     * @brief Write a double value to the output.
     *
     * @param message The double value to write.
     *
     * @return Reference to current object.
     */
    virtual Output& operator<<(const double message);

    /**
     * @brief Write a long double value to the output.
     *
     * @param message The long double value to write.
     *
     * @return Reference to current object.
     */
    virtual Output& operator<<(const long double message);

    /**
     * @brief Write a string to the output.
     *
     * @param message The string to write.
     *
     * @return Reference to current object.
     */
    virtual Output& operator<<(const std::string& message);

    /**
     * @brief Write a string view to the output.
     *
     * @param message The string view to write.
     *
     * @return Reference to current object.
     */
    virtual Output& operator<<(const std::string_view& message);

    /**
     * @brief Write a pointer address to the output.
     *
     * @param message The pointer to write.
     *
     * @return Reference to current object.
     */
    virtual Output& operator<<(const void* message);

    /**
     * @brief Write an exception message to the output.
     *
     * @param message The exception to write (outputs what()).
     *
     * @return Reference to current object.
     */
    virtual Output& operator<<(const std::exception& message);

    /**
     * @brief Write an error code to the output.
     *
     * @param message The error code to write.
     *
     * @return Reference to current object.
     */
    virtual Output& operator<<(const std::error_code& message);
};
} // namespace ramrod

#endif // RAMROD_LOG_OUTPUT_HPP