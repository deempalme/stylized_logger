#ifndef RAMROD_LOG_OUTPUT_ERROR_HPP
#define RAMROD_LOG_OUTPUT_ERROR_HPP

#include "ramrod/log/Output.hpp"

namespace ramrod
{
    /**
     * @brief Log output that writes messages to the standard error stream.
     *
     * Writes all streamed content to the standard error stream.
     */
    class OutputError final : public Output
    {
    public:
        /**
         * @brief Clears the standard error stream.
         */
        void clear() override;

        /**
         * @brief Clear the ANSI format from the output.
         */
        void clear_format() override;

        /**
         * @brief Ends the current line by adding a new line to the end of the standard error stream.
         */
        void end() override;

        /**
         * @brief Writes the file and line information to the output.
         *
         * @param file The file name.
         * @param line The line number.
         *
         * @return Reference to current object.
         */
        OutputError &file_info(const char *file, const int line) override;

        /**
         * @brief Flushes the standard error stream.
         */
        void flush() override;

        /**
         * @brief Apply ansi format to the output.
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
        void header(const char *ansi_format, const char *date, const char *level_tag) override;

        /**
         * @brief Writes a boolean value to the output.
         *
         * @param message The boolean value to write.
         *
         * @return Reference to current object.
         */
        OutputError &operator<<(const bool message) override;

        /**
        * @brief Writes a character to the output.
        *
        * @param message The character to write.
        *
        * @return Reference to current object.
        */
        OutputError &operator<<(const char message) override;

        /**
        * @brief Writes a character to the output.
        *
        * @param message The character to write.
        *
        * @return Reference to current object.
        */
        OutputError &operator<<(const std::int8_t message) override;

        /**
        * @brief Writes an unsigned character to the output.
        *
        * @param message The unsigned character to write.
        *
        * @return Reference to current object.
        */
        OutputError &operator<<(const std::uint8_t message) override;

        /**
        * @brief Writes a null-terminated character string to the output.
        *
        * @param message The character string to write.
        *
        * @return Reference to current object.
        */
        OutputError &operator<<(const char *message) override;

        /**
        * @brief Writes a null-terminated character string to the output.
        *
        * @param message The character string to write.
        *
        * @return Reference to current object.
        */
        OutputError &operator<<(const std::int8_t *message) override;

        /**
        * @brief Writes a null-terminated unsigned character string to the output.
        *
        * @param message The unsigned character string to write.
        *
        * @return Reference to current object.
        */
        OutputError &operator<<(const std::uint8_t *message) override;

        /**
        * @brief Writes a short integer value to the output.
        *
        * @param message The short integer value to write.
        *
        * @return Reference to current object.
        */
        OutputError &operator<<(const std::int16_t message) override;

        /**
        * @brief Writes an unsigned short integer value to the output.
        *
        * @param message The unsigned short integer value to write.
        *
        * @return Reference to current object.
        */
        OutputError &operator<<(const std::uint16_t message) override;

        /**
        * @brief Writes an integer value to the output.
        *
        * @param message The integer value to write.
        *
        * @return Reference to current object.
        */
        OutputError &operator<<(const std::int32_t message) override;

        /**
        * @brief Writes an unsigned integer value to the output.
        *
        * @param message The unsigned integer value to write.
        *
        * @return Reference to current object.
        */
        OutputError &operator<<(const std::uint32_t message) override;

        /**
        * @brief Writes a float value to the output.
        *
        * @param message The float value to write.
        *
        * @return Reference to current object.
        */
        OutputError &operator<<(const float message) override;

        /**
        * @brief Writes a long integer value to the output.
        *
        * @param message The long integer value to write.
        *
        * @return Reference to current object.
        */
        OutputError &operator<<(const std::int64_t message) override;

        /**
        * @brief Writes an unsigned long integer value to the output.
        *
        * @param message The unsigned long integer value to write.
        *
        * @return Reference to current object.
        */
        OutputError &operator<<(const std::uint64_t message) override;

        /**
        * @brief Writes a double value to the output.
        *
        * @param message The double value to write.
        *
        * @return Reference to current object.
        */
        OutputError &operator<<(const double message) override;

        /**
        * @brief Writes a long double value to the output.
        *
        * @param message The long double value to write.
        *
        * @return Reference to current object.
        */
        OutputError &operator<<(const long double message) override;

        /**
        * @brief Writes a string to the output.
        *
        * @param message The string to write.
        *
        * @return Reference to current object.
        */
        OutputError &operator<<(const std::string &message) override;

        /**
        * @brief Writes a string view to the output.
        *
        * @param message The string view to write.
        *
        * @return Reference to current object.
        */
        OutputError &operator<<(const std::string_view &message) override;

        /**
        * @brief Writes a pointer address to the output.
        *
        * @param message The pointer to write.
        *
        * @return Reference to current object.
        */
        OutputError &operator<<(const void *message) override;

        /**
        * @brief Writes an exception message to the output.
        *
        * @param message The exception to write (outputs what()).
        *
        * @return Reference to current object.
        */
        OutputError &operator<<(const std::exception &message) override;

        /**
        * @brief Writes an error code to the output.
        *
        * @param message The error code to write.
        *
        * @return Reference to current object.
        */
        OutputError &operator<<(const std::error_code &message) override;
    };
} // namespace ramrod

#endif // RAMROD_LOG_OUTPUT_FILE_HPP