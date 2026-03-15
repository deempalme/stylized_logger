#ifndef RAMROD_LOG_WRITER_FILE_HPP
#define RAMROD_LOG_WRITER_FILE_HPP

#include "ramrod/log/File.hpp"
#include "ramrod/log/Writer.hpp"

namespace ramrod
{
/**
 * @brief Log output that writes messages to a file.
 *
 * Write all streamed content to a file.
 */
class WriterFile final : public Writer
{
public:
    /**
     * @brief Constructor.
     *
     * @param file  The file to write to.
     */
    WriterFile(File& file);

    /**
     * @brief Clear the file (truncates to zero size).
     */
    void clear() override;

    /**
     * @brief Do nothing since files are not compatible with ANSI format.
     */
    void clear_format() override;

    /**
     * @brief End the current line by adding a new line to the end of the file.
     */
    void end() override;

    /**
     * @brief Write the file and line information to the output.
     *
     * @param file  The file name.
     * @param line  The line number.
     *
     * @return Reference to current object.
     */
    WriterFile& file_info(const char* file, const int line) override;

    /**
     * @brief Flush the file stream to the file.
     */
    void flush() override;

    /**
     * @brief Do nothing since files are not compatible with ANSI format.
     */
    void format(const char* ansi_format) override;

    /**
     * @brief Set the header of the output (ANSI format, date, and level tag).
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
    WriterFile& operator<<(const bool message) override;

    /**
     * @brief Write a character.
     *
     * @param message The character to write.
     *
     * @return Reference to current object.
     */
    WriterFile& operator<<(const char message) override;

    /**
     * @brief Write an unsigned character.
     *
     * @param message The unsigned character to write.
     *
     * @return Reference to current object.
     */
    WriterFile& operator<<(const unsigned char message) override;

    /**
     * @brief Write a null-terminated character string.
     *
     * @param message The character string to write.
     *
     * @return Reference to current object.
     */
    WriterFile& operator<<(const char* message) override;

    /**
     * @brief Write a null-terminated unsigned character string.
     *
     * @param message The unsigned character string to write.
     *
     * @return Reference to current object.
     */
    WriterFile& operator<<(const unsigned char* message) override;

    /**
     * @brief Write a short integer value.
     *
     * @param message The short integer value to write.
     *
     * @return Reference to current object.
     */
    WriterFile& operator<<(const short message) override;

    /**
     * @brief Write an unsigned short integer value.
     *
     * @param message The unsigned short integer value to write.
     *
     * @return Reference to current object.
     */
    WriterFile& operator<<(const unsigned short message) override;

    /**
     * @brief Write an integer value.
     *
     * @param message The integer value to write.
     *
     * @return Reference to current object.
     */
    WriterFile& operator<<(const int message) override;

    /**
     * @brief Write an unsigned integer value.
     *
     * @param message The unsigned integer value to write.
     *
     * @return Reference to current object.
     */
    WriterFile& operator<<(const unsigned int message) override;

    /**
     * @brief Write a float value.
     *
     * @param message The float value to write.
     *
     * @return Reference to current object.
     */
    WriterFile& operator<<(const float message) override;

    /**
     * @brief Write a long integer value.
     *
     * @param message The long integer value to write.
     *
     * @return Reference to current object.
     */
    WriterFile& operator<<(const long message) override;

    /**
     * @brief Write an unsigned long integer value.
     *
     * @param message The unsigned long integer value to write.
     *
     * @return Reference to current object.
     */
    WriterFile& operator<<(const unsigned long message) override;

    /**
     * @brief Write a double value.
     *
     * @param message The double value to write.
     *
     * @return Reference to current object.
     */
    WriterFile& operator<<(const double message) override;

    /**
     * @brief Write a long double value.
     *
     * @param message The long double value to write.
     *
     * @return Reference to current object.
     */
    WriterFile& operator<<(const long double message) override;

    /**
     * @brief Write a long long integer value.
     *
     * @param message The long long integer value to write.
     *
     * @return Reference to current object.
     */
    WriterFile& operator<<(const long long message) override;

    /**
     * @brief Write an unsigned long long integer value.
     *
     * @param message The unsigned long long integer value to write.
     *
     * @return Reference to current object.
     */
    WriterFile& operator<<(const unsigned long long message) override;

    /**
     * @brief Write a pointer address.
     *
     * @param message The pointer to write.
     *
     * @return Reference to current object.
     */
    WriterFile& operator<<(const void* message) override;

    /**
     * @brief Writes an error code.
     *
     * @param message The error code to write.
     *
     * @return Reference to current object.
     */
    WriterFile& operator<<(const std::error_code& message) override;

    /**
     * @brief Write a newline.
     *
     * @param endl A newline object to write.
     *
     * @return Reference to current object.
     */
    WriterFile& operator<<(const Endl& endl) override;

private:
    /// @brief The file to write to.
    File& file_;
};
} // namespace ramrod

#endif // RAMROD_LOG_WRITER_FILE_HPP