#ifndef RAMROD_LOG_OUTPUT_FILE_CONSOLE_HPP
#define RAMROD_LOG_OUTPUT_FILE_CONSOLE_HPP

#include "ramrod/log/Output.hpp"

#include <filesystem>
#include <fstream>

namespace ramrod
{
/**
 * @brief Log output that writes messages to a file and the standard output stream.
 *
 * Writes all streamed content to a file at the given path and the standard output stream.
 * The file is opened in append mode. If the file is deleted while in use, it is recreated
 * on the next write when verify_status() is checked.
 */
class OutputFileConsole final : public Output
{
  public:
    /**
     * @brief Constructor.
     *
     * @param filepath  The path to the file to write to.
     */
    OutputFileConsole(const std::filesystem::path& filepath);

    /**
     * @brief Destructor; closes the file and releases the stream.
     */
    ~OutputFileConsole() override;

    /**
     * @brief Clears the file and the standard output stream.
     */
    void clear() override;

    /**
     * @brief Clear the ANSI format from the standard output stream.
     *
     * Does nothing to file since it is not compatible with ANSI format.
     */
    void clear_format() override;

    /**
     * @brief Ends the current line by adding a new line to the end of the file and
     * the standard output stream.
     */
    void end() override;

    /**
     * @brief Writes the file and line information to the file and the standard output stream.
     *
     * @param file  The file name.
     * @param line  The line number.
     *
     * @return Reference to current object.
     */
    OutputFileConsole& file_info(const char* file, const int line) override;

    /**
     * @brief Flushes the file and the standard output stream.
     */
    void flush() override;

    /**
     * @brief Apply ansi format to the standard output stream.
     *
     * Does nothing to file since it is not compatible with ANSI format.
     *
     * @param ansi_format Null-terminated string with ANSI escape codes (e.g. for color).
     */
    void format(const char* ansi_format) override;

    /**
     * @brief Sets the header of the output (ANSI format, date, and level tag).
     *
     * @param ansi_format  Null-terminated string with ANSI escape codes (e.g. for color).
     * @param date         Null-terminated string with the date and time.
     * @param level_tag    Null-terminated string with the level tag.
     */
    void header(const char* ansi_format, const char* date, const char* level_tag) override;

    /**
     * @brief Writes a boolean value to the output.
     *
     * @param message The boolean value to write.
     *
     * @return Reference to current object.
     */
    OutputFileConsole& operator<<(const bool message) override;

    /**
     * @brief Writes a character to the output.
     *
     * @param message The character to write.
     *
     * @return Reference to current object.
     */
    OutputFileConsole& operator<<(const char message) override;

    /**
     * @brief Writes a character to the output.
     *
     * @param message The character to write.
     *
     * @return Reference to current object.
     */
    OutputFileConsole& operator<<(const std::int8_t message) override;

    /**
     * @brief Writes an unsigned character to the output.
     *
     * @param message The unsigned character to write.
     *
     * @return Reference to current object.
     */
    OutputFileConsole& operator<<(const std::uint8_t message) override;

    /**
     * @brief Writes a null-terminated character string to the output.
     *
     * @param message The character string to write.
     *
     * @return Reference to current object.
     */
    OutputFileConsole& operator<<(const char* message) override;

    /**
     * @brief Writes a null-terminated character string to the output.
     *
     * @param message The character string to write.
     *
     * @return Reference to current object.
     */
    OutputFileConsole& operator<<(const std::int8_t* message) override;

    /**
     * @brief Writes a null-terminated unsigned character string to the output.
     *
     * @param message The unsigned character string to write.
     *
     * @return Reference to current object.
     */
    OutputFileConsole& operator<<(const std::uint8_t* message) override;

    /**
     * @brief Writes a short integer value to the output.
     *
     * @param message The short integer value to write.
     *
     * @return Reference to current object.
     */
    OutputFileConsole& operator<<(const std::int16_t message) override;

    /**
     * @brief Writes an unsigned short integer value to the output.
     *
     * @param message The unsigned short integer value to write.
     *
     * @return Reference to current object.
     */
    OutputFileConsole& operator<<(const std::uint16_t message) override;

    /**
     * @brief Writes an integer value to the output.
     *
     * @param message The integer value to write.
     *
     * @return Reference to current object.
     */
    OutputFileConsole& operator<<(const std::int32_t message) override;

    /**
     * @brief Writes an unsigned integer value to the output.
     *
     * @param message The unsigned integer value to write.
     *
     * @return Reference to current object.
     */
    OutputFileConsole& operator<<(const std::uint32_t message) override;

    /**
     * @brief Writes a float value to the output.
     *
     * @param message The float value to write.
     *
     * @return Reference to current object.
     */
    OutputFileConsole& operator<<(const float message) override;

    /**
     * @brief Writes a long integer value to the output.
     *
     * @param message The long integer value to write.
     *
     * @return Reference to current object.
     */
    OutputFileConsole& operator<<(const std::int64_t message) override;

    /**
     * @brief Writes an unsigned long integer value to the output.
     *
     * @param message The unsigned long integer value to write.
     *
     * @return Reference to current object.
     */
    OutputFileConsole& operator<<(const std::uint64_t message) override;

    /**
     * @brief Writes a double value to the output.
     *
     * @param message The double value to write.
     *
     * @return Reference to current object.
     */
    OutputFileConsole& operator<<(const double message) override;

    /**
     * @brief Writes a long double value to the output.
     *
     * @param message The long double value to write.
     *
     * @return Reference to current object.
     */
    OutputFileConsole& operator<<(const long double message) override;

    /**
     * @brief Writes a string to the output.
     *
     * @param message The string to write.
     *
     * @return Reference to current object.
     */
    OutputFileConsole& operator<<(const std::string& message) override;

    /**
     * @brief Writes a string view to the output.
     *
     * @param message The string view to write.
     *
     * @return Reference to current object.
     */
    OutputFileConsole& operator<<(const std::string_view& message) override;

    /**
     * @brief Writes a pointer address to the output.
     *
     * @param message The pointer to write.
     *
     * @return Reference to current object.
     */
    OutputFileConsole& operator<<(const void* message) override;

    /**
     * @brief Writes an exception message to the output.
     *
     * @param message The exception to write (outputs what()).
     *
     * @return Reference to current object.
     */
    OutputFileConsole& operator<<(const std::exception& message) override;

    /**
     * @brief Writes an error code to the output.
     *
     * @param message The error code to write.
     *
     * @return Reference to current object.
     */
    OutputFileConsole& operator<<(const std::error_code& message) override;

  private:
    /**
     * @brief Closes the file.
     */
    void close();

    /// @brief The file stream.
    std::ofstream file_;
    /// @brief The path to the file.
    std::filesystem::path filepath_;
    /// @brief Whether the file is open.
    bool is_open_;
};
} // namespace ramrod

#endif // RAMROD_LOG_OUTPUT_FILE_CONSOLE_HPP