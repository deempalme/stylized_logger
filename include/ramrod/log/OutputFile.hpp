#ifndef RAMROD_LOG_OUTPUT_FILE_HPP
#define RAMROD_LOG_OUTPUT_FILE_HPP

#include <cstdint>
#include <exception>
#include <filesystem>
#include <fstream>
#include <string>
#include <string_view>
#include <system_error>

#include "ramrod/log/Output.hpp"

namespace ramrod
{
    /**
     * @brief Log output that writes messages to a file.
     *
     * Writes all streamed content to a file at the given path. The file is opened
     * in append mode. If the file is deleted while in use, it is recreated on the
     * next write when ok() is checked.
     */
    class OutputFile final : public Output
    {
    public:
        /**
         * @brief Constructor.
         *
         * @param filepath The path to the file to write to.
         */
        OutputFile(const std::filesystem::path &filepath);

        /**
         * @brief Destructor; closes the file and releases the stream.
         */
        ~OutputFile() override;

        /**
         * @brief Checks if the file is open.
         *
         * If the file was deleted after being opened, it will be created again and reopen.
         *
         * @return True if the file is open, false otherwise.
         */
        bool ok() override;

        /**
         * @brief Writes a boolean value to file.
         *
         * @param message The boolean value to write.
         *
         * @return Reference to current object.
         */
        OutputFile &operator<<(const bool message) override;

        /**
         * @brief Writes a character to file.
         *
         * @param message The character to write.
         *
         * @return Reference to current object.
         */
        OutputFile &operator<<(const std::int8_t message) override;

        /**
         * @brief Writes an unsigned character to file.
         *
         * @param message The unsigned character to write.
         *
         * @return Reference to current object.
         */
        OutputFile &operator<<(const std::uint8_t message) override;

        /**
         * @brief Writes a null-terminated character string to file.
         *
         * @param message The character string to write.
         *
         * @return Reference to current object.
         */
        OutputFile &operator<<(const std::int8_t *message) override;

        /**
         * @brief Writes a null-terminated unsigned character string to file.
         *
         * @param message The unsigned character string to write.
         *
         * @return Reference to current object.
         */
        OutputFile &operator<<(const std::uint8_t *message) override;

        /**
         * @brief Writes a short integer value to file.
         *
         * @param message The short integer value to write.
         *
         * @return Reference to current object.
         */
        OutputFile &operator<<(const std::int16_t message) override;

        /**
         * @brief Writes an unsigned short integer value to file.
         *
         * @param message The unsigned short integer value to write.
         *
         * @return Reference to current object.
         */
        OutputFile &operator<<(const std::uint16_t message) override;

        /**
         * @brief Writes an integer value to file.
         *
         * @param message The integer value to write.
         *
         * @return Reference to current object.
         */
        OutputFile &operator<<(const std::int32_t message) override;

        /**
         * @brief Writes an unsigned integer value to file.
         *
         * @param message The unsigned integer value to write.
         *
         * @return Reference to current object.
         */
        OutputFile &operator<<(const std::uint32_t message) override;

        /**
         * @brief Writes a float value to file.
         *
         * @param message The float value to write.
         *
         * @return Reference to current object.
         */
        OutputFile &operator<<(const float message) override;

        /**
         * @brief Writes a long integer value to file.
         *
         * @param message The long integer value to write.
         *
         * @return Reference to current object.
         */
        OutputFile &operator<<(const std::int64_t message) override;

        /**
         * @brief Writes an unsigned long integer value to file.
         *
         * @param message The unsigned long integer value to write.
         *
         * @return Reference to current object.
         */
        OutputFile &operator<<(const std::uint64_t message) override;

        /**
         * @brief Writes a double value to file.
         *
         * @param message The double value to write.
         *
         * @return Reference to current object.
         */
        OutputFile &operator<<(const double message) override;

        /**
         * @brief Writes a long double value to file.
         *
         * @param message The long double value to write.
         *
         * @return Reference to current object.
         */
        OutputFile &operator<<(const long double message) override;

        /**
         * @brief Writes a string to file.
         *
         * @param message The string to write.
         *
         * @return Reference to current object.
         */
        OutputFile &operator<<(const std::string &message) override;

        /**
         * @brief Writes a string view to file.
         *
         * @param message The string view to write.
         *
         * @return Reference to current object.
         */
        OutputFile &operator<<(const std::string_view &message) override;

        /**
         * @brief Writes a pointer address to file.
         *
         * @param message The pointer to write.
         *
         * @return Reference to current object.
         */
        OutputFile &operator<<(const void *message) override;

        /**
         * @brief Writes an exception message to file.
         *
         * @param message The exception to write (outputs what()).
         *
         * @return Reference to current object.
         */
        OutputFile &operator<<(const std::exception &message) override;

        /**
         * @brief Writes an error code to file.
         *
         * @param message The error code to write.
         *
         * @return Reference to current object.
         */
        OutputFile &operator<<(const std::error_code &message) override;

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

#endif // RAMROD_LOG_OUTPUT_FILE_HPP