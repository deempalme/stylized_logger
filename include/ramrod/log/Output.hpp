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
         * @brief Checks if the output is valid.
         *
         * @return True if the output is valid, false otherwise.
         */
        virtual bool ok();

        /**
         * @brief Writes a boolean value to standard output stream.
         *
         * @param message The boolean value to write.
         *
         * @return Reference to current object.
         */
        virtual Output &operator<<(const bool message);

        /**
         * @brief Writes a character to standard output stream.
         *
         * @param message The character to write.
         *
         * @return Reference to current object.
         */
        virtual Output &operator<<(const std::int8_t message);

        /**
         * @brief Writes an unsigned character to standard output stream.
         *
         * @param message The unsigned character to write.
         *
         * @return Reference to current object.
         */
        virtual Output &operator<<(const std::uint8_t message);

        /**
         * @brief Writes a null-terminated character string to standard output stream.
         *
         * @param message The character string to write.
         *
         * @return Reference to current object.
         */
        virtual Output &operator<<(const std::int8_t *message);

        /**
         * @brief Writes a null-terminated unsigned character string to standard output stream.
         *
         * @param message The unsigned character string to write.
         *
         * @return Reference to current object.
         */
        virtual Output &operator<<(const std::uint8_t *message);

        /**
         * @brief Writes a short integer value to standard output stream.
         *
         * @param message The short integer value to write.
         *
         * @return Reference to current object.
         */
        virtual Output &operator<<(const std::int16_t message);

        /**
         * @brief Writes an unsigned short integer value to standard output stream.
         *
         * @param message The unsigned short integer value to write.
         *
         * @return Reference to current object.
         */
        virtual Output &operator<<(const std::uint16_t message);

        /**
         * @brief Writes an integer value to standard output stream.
         *
         * @param message The integer value to write.
         *
         * @return Reference to current object.
         */
        virtual Output &operator<<(const std::int32_t message);

        /**
         * @brief Writes an unsigned integer value to standard output stream.
         *
         * @param message The unsigned integer value to write.
         *
         * @return Reference to current object.
         */
        virtual Output &operator<<(const std::uint32_t message);

        /**
         * @brief Writes a float value to standard output stream.
         *
         * @param message The float value to write.
         *
         * @return Reference to current object.
         */
        virtual Output &operator<<(const float message);

        /**
         * @brief Writes a long integer value to standard output stream.
         *
         * @param message The long integer value to write.
         *
         * @return Reference to current object.
         */
        virtual Output &operator<<(const std::int64_t message);

        /**
         * @brief Writes an unsigned long integer value to standard output stream.
         *
         * @param message The unsigned long integer value to write.
         *
         * @return Reference to current object.
         */
        virtual Output &operator<<(const std::uint64_t message);

        /**
         * @brief Writes a double value to standard output stream.
         *
         * @param message The double value to write.
         *
         * @return Reference to current object.
         */
        virtual Output &operator<<(const double message);

        /**
         * @brief Writes a long double value to standard output stream.
         *
         * @param message The long double value to write.
         *
         * @return Reference to current object.
         */
        virtual Output &operator<<(const long double message);

        /**
         * @brief Writes a string to standard output stream.
         *
         * @param message The string to write.
         *
         * @return Reference to current object.
         */
        virtual Output &operator<<(const std::string &message);

        /**
         * @brief Writes a string view to standard output stream.
         *
         * @param message The string view to write.
         *
         * @return Reference to current object.
         */
        virtual Output &operator<<(const std::string_view &message);

        /**
         * @brief Writes a pointer address to standard output stream.
         *
         * @param message The pointer to write (output as implementation-defined representation, typically hex).
         *
         * @return Reference to current object.
         */
        virtual Output &operator<<(const void *message);

        /**
         * @brief Writes an exception message to standard output stream.
         *
         * @param message The exception to write (outputs what()).
         *
         * @return Reference to current object.
         */
        virtual Output &operator<<(const std::exception &message);

        /**
         * @brief Writes an error code to standard output stream.
         *
         * @param message The error code to write (outputs message string and category).
         *
         * @return Reference to current object.
         */
        virtual Output &operator<<(const std::error_code &message);

    };
} // namespace ramrod

#endif // RAMROD_LOG_OUTPUT_HPP