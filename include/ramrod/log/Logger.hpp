#ifndef RAMROD_LOG_LOGGER_HPP
#define RAMROD_LOG_LOGGER_HPP

#include <cstddef>
#include <filesystem>
#include <string>

#include "ramrod/log/Debug.hpp"
#include "ramrod/log/Error.hpp"
#include "ramrod/log/Info.hpp"
#include "ramrod/log/Verbose.hpp"
#include "ramrod/log/Warning.hpp"

namespace ramrod
{
    /**
     * @brief Aggregates loggers for all levels (debug, error, info, verbose, warning).
     *
     * Use the member loggers to write at a specific level, e.g. logger.error(...).
     *
     * Each log message is prefixed with a timestamp and a level tag:
     * [YYYY-MM-DD HH:MM:SS +0100][LEVEL] <Message content>'\n'
     *
     * The timestamp is formatted as "[YYYY-MM-DD HH:MM:SS +0100]".
     * The +0100 is the timezone offset, e.g. "+0100" for UTC+1.
     *
     * The level tag is one of the following:
     * - [DEBUG]
     * - [ERROR]
     * - [INFO]
     * - [VERBOSE]
     * - [WARNING]
     */
    class Logger
    {
    public:
        /** @brief Creates a logger set that writes to standard output. */
        Logger();

        /**
         * @brief Creates a logger set that writes to a file.
         *
         * @param output_path The path to the file to save messages to.
         */
        Logger(const std::filesystem::path &output_path);

        /** @brief Destructor. */
        virtual ~Logger() = default;

        /// @brief Logger for debug-level messages. Messages are printed in blue and are
        ///        prefixed with "[DEBUG]".
        Debug debug;
        /// @brief Logger for error-level messages. Messages are printed in red and are
        ///        prefixed with "[ERROR]".
        Error error;
        /// @brief Logger for info-level messages. Messages are printed in green and are
        ///        prefixed with "[INFO]".
        Info info;
        /// @brief Logger for verbose-level messages. Messages are printed in default color
        ///        and are prefixed with "[VERBOSE]".
        Verbose verbose;
        /// @brief Logger for warning-level messages. Messages are printed in yellow and are
        ///        prefixed with "[WARNING]".
        Warning warning;

        /**
         * @brief Changes the date format and the size of the date buffer.
         *
         * @param date_format       The new date format, e.g. "[%Y-%m-%d %H:%M:%S %z]".
         * @param date_buffer_size  The new size of the date buffer, it must be able to contain
         *                          the longest date format, including the null terminator,
         *                          e.g. 28 for "[2026-03-01 12:00:00 +0100]".
         */
        void change_date_format(const std::string &date_format, const size_t date_buffer_size);

        /**
         * @brief Switches log output to a new file path.
         *
         * @param output_path The path to the file to write to.
         *
         * @return True if the new output was opened successfully, false otherwise.
         */
        bool change_log_output(const std::filesystem::path &output_path);

        /**
         * @brief Returns the size of the buffer used for printf formatting.
         *
         * @return Current printf buffer size in bytes.
         */
        size_t printf_buffer_size() const;

        /**
         * @brief Sets the size of the buffer used for printf formatting.
         *
         * The default size is 1024 bytes. It is recommended to change the size for one that can
         * contain the longest message that is expected to be printed.
         *
         * @param new_size New buffer size in bytes.
         */
        void printf_buffer_size(const size_t new_size);
    };
} // namespace ramrod

#endif // RAMROD_LOG_LOGGER_HPP
