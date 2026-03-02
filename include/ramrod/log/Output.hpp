#ifndef RAMROD_LOG_OUTPUT_HPP
#define RAMROD_LOG_OUTPUT_HPP

#include <iostream>
#include <utility>

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
         * @brief Writes all forwarded arguments to the output (stream insertion).
         *
         * @param args Values to write (e.g. strings, numbers); each is sent with operator<<.
         */
        template <typename... Args>
        void operator()(Args&&... args)
        {
            (std::cout << ... << std::forward<Args>(args));
        }

        /**
         * @brief Clears the output (e.g. clears the console).
         */
        virtual void clear();

        /**
         * @brief Ends the current line or flushes the output.
         */
        virtual void end();

        /**
         * @brief Sets the ANSI format used to colorize or style subsequent output.
         *
         * @param ansi_format Null-terminated string with ANSI escape codes (e.g. for color).
         */
        virtual void format(const char *ansi_format);

        /**
         * @brief Checks if the output is valid.
         *
         * @return True if the output is valid, false otherwise.
         */
        virtual bool verify_status();
    };
} // namespace ramrod

#endif // RAMROD_LOG_OUTPUT_HPP