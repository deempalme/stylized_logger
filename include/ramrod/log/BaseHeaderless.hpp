#ifndef RAMROD_LOG_BASE_HEADERLESS_HPP
#define RAMROD_LOG_BASE_HEADERLESS_HPP

#include <cstdint>
#include <exception>
#include <filesystem>
#include <string>
#include <string_view>
#include <system_error>

#include "ramrod/log/Output.hpp"

namespace ramrod
{
    class BaseHeaderless : public Output
    {
    public:
        /**
         * @brief Creates a logger that saves messages to the standard output.
         */
        BaseHeaderless();

        /**
         * @brief Creates a logger that saves messages to a file.
         *
         * @param output_path The path to the file to save messages to.
         */
        BaseHeaderless(const std::filesystem::path &output_path);

        /**
         * @brief Switches log output to a new file path.
         *
         * @param output_path The path to the file to write to.
         *
         * @return True if the new output was opened successfully, false otherwise.
         */
        bool change_log_output(const std::filesystem::path &output_path);

        /**
         * @brief Destructor.
         */
        virtual ~BaseHeaderless() = default;

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
        /// @brief Format in ANSI escape codes used to colorize output text
        const char *_ansi_format;
    };
} // namespace ramrod

#endif // RAMROD_LOG_BASE_HEADERLESS_HPP
