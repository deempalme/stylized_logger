#ifndef RAMROD_LOG_WRITER_FILE_CONSOLE_HPP
#define RAMROD_LOG_WRITER_FILE_CONSOLE_HPP

#include "ramrod/log/File.hpp"
#include "ramrod/log/Writer.hpp"

namespace ramrod
{
/**
 * @brief Log output that writes messages to a file and the standard output stream.
 *
 * Writes all streamed content to a file and the standard output stream.
 */
class WriterFileCout final : public Writer
{
public:
    /**
     * @brief Constructor.
     *
     * @param file  The file to write to.
     */
    WriterFileCout(File& file);

    /**
     * @brief Clears the file and the standard output stream.
     */
    void clear() override;

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
    WriterFileCout& file_info(const char* file, const int line) override;

    /**
     * @brief Flushes the file and the standard output stream.
     */
    void flush() override;

    /**
     * @brief Sets the header of the output (ANSI format, date, and level tag).
     *
     * @param ansi_format  Null-terminated string with ANSI escape codes (e.g. for color).
     * @param level_tag    Null-terminated string with the level tag.
     */
    void header(const char* ansi_format, const char* level_tag) override;

    /**
     * @brief Write a boolean value.
     *
     * @param message The boolean value to write.
     *
     * @return Reference to current object.
     */
    WriterFileCout& operator<<(const bool message) override;

    /**
     * @brief Write a character.
     *
     * @param message The character to write.
     *
     * @return Reference to current object.
     */
    WriterFileCout& operator<<(const char message) override;

    /**
     * @brief Write an unsigned character.
     *
     * @param message The unsigned character to write.
     *
     * @return Reference to current object.
     */
    WriterFileCout& operator<<(const unsigned char message) override;

    /**
     * @brief Write a null-terminated character string.
     *
     * @param message The character string to write.
     *
     * @return Reference to current object.
     */
    WriterFileCout& operator<<(const char* message) override;

    /**
     * @brief Write a null-terminated unsigned character string.
     *
     * @param message The unsigned character string to write.
     *
     * @return Reference to current object.
     */
    WriterFileCout& operator<<(const unsigned char* message) override;

    /**
     * @brief Write a short integer value.
     *
     * @param message The short integer value to write.
     *
     * @return Reference to current object.
     */
    WriterFileCout& operator<<(const short message) override;

    /**
     * @brief Write an unsigned short integer value.
     *
     * @param message The unsigned short integer value to write.
     *
     * @return Reference to current object.
     */
    WriterFileCout& operator<<(const unsigned short message) override;

    /**
     * @brief Write an integer value.
     *
     * @param message The integer value to write.
     *
     * @return Reference to current object.
     */
    WriterFileCout& operator<<(const int message) override;

    /**
     * @brief Write an unsigned integer value.
     *
     * @param message The unsigned integer value to write.
     *
     * @return Reference to current object.
     */
    WriterFileCout& operator<<(const unsigned int message) override;

    /**
     * @brief Write a float value.
     *
     * @param message The float value to write.
     *
     * @return Reference to current object.
     */
    WriterFileCout& operator<<(const float message) override;

    /**
     * @brief Write a long integer value.
     *
     * @param message The long integer value to write.
     *
     * @return Reference to current object.
     */
    WriterFileCout& operator<<(const long message) override;

    /**
     * @brief Write an unsigned long integer value.
     *
     * @param message The unsigned long integer value to write.
     *
     * @return Reference to current object.
     */
    WriterFileCout& operator<<(const unsigned long message) override;

    /**
     * @brief Write a double value.
     *
     * @param message The double value to write.
     *
     * @return Reference to current object.
     */
    WriterFileCout& operator<<(const double message) override;

    /**
     * @brief Write a long double value.
     *
     * @param message The long double value to write.
     *
     * @return Reference to current object.
     */
    WriterFileCout& operator<<(const long double message) override;

    /**
     * @brief Write a long long integer value.
     *
     * @param message The long long integer value to write.
     *
     * @return Reference to current object.
     */
    WriterFileCout& operator<<(const long long message) override;

    /**
     * @brief Write an unsigned long long integer value.
     *
     * @param message The unsigned long long integer value to write.
     *
     * @return Reference to current object.
     */
    WriterFileCout& operator<<(const unsigned long long message) override;

    /**
     * @brief Write a pointer address.
     *
     * @param message The pointer to write.
     *
     * @return Reference to current object.
     */
    WriterFileCout& operator<<(const void* message) override;

    /**
     * @brief Writes an error code.
     *
     * @param message The error code to write.
     *
     * @return Reference to current object.
     */
    WriterFileCout& operator<<(const std::error_code& message) override;

    /**
     * @brief Write a newline.
     *
     * @param endl A newline object to write.
     *
     * @return Reference to current object.
     */
    WriterFileCout& operator<<(const Endl& endl) override;

private:
    /// @brief The file to write to.
    File& file_;
};
} // namespace ramrod

#endif // RAMROD_LOG_WRITER_FILE_CONSOLE_HPP