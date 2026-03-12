#ifndef RAMROD_LOG_LOGGER_HPP
#define RAMROD_LOG_LOGGER_HPP

#include "ramrod/log/Debug.hpp"
#include "ramrod/log/Error.hpp"
#include "ramrod/log/Info.hpp"
#include "ramrod/log/Output.hpp"
#include "ramrod/log/Verbose.hpp"
#include "ramrod/log/Warning.hpp"

#include <cstddef>
#include <filesystem>
#include <string>

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
 *
 * Header is composed of:
 * - ANSI color format which depends on the inherited class;
 *   - Error messages are red,
 *   - Warning messages are yellow,
 *   - Debug messages are blue,
 *   - Info messages are green,
 *   - Verbose messages have default color.
 * - Date
 * - Level tag message which depends on the inherited class;
 *   - Error messages are "[ERROR]",
 *   - Warning messages are "[WARNING]",
 *   - Debug messages are "[DEBUG]",
 *   - Info messages are "[INFO]",
 *   - Verbose messages are "[VERBOSE]".
 */
class Logger
{
  public:
    /** @brief Create a logger set that writes to standard output. */
    Logger();

    enum class OutputType
    {
        /// @brief Output to standard output (stdout and stderr).
        CONSOLE,
        /// @brief Output to a file.
        FILE,
        /// @brief Output to a file and standard output (stdout and stderr).
        FILE_AND_CONSOLE
    };

    /// @brief Path to standard output (stdout and stderr) no matter which type is used.
    static const std::filesystem::path TO_CONSOLE;

    /**
     * @brief Create a logger set that writes to a file.
     *
     * @param type  The type of output to switch to.
     * @param path  If \p type is \p FILE or \p FILE_AND_CONSOLE, this path is used for the
     *              output log file. If \p type is \p CONSOLE then this path is ignored. If
     *              \p path is empty then output to \p CONSOLE is used.
     */
    Logger(const OutputType type, const std::filesystem::path& path = TO_CONSOLE);

    /** @brief Destructor. */
    virtual ~Logger() = default;

    /// @brief Logger for debug-level messages. Messages are printed in blue and are
    ///        prefixed with "[DEBUG]".
    Debug& debug();
    /// @brief Logger for error-level messages. Messages are printed in red and are
    ///        prefixed with "[ERROR]".
    Error& error();
    /// @brief Logger for info-level messages. Messages are printed in green and are
    ///        prefixed with "[INFO]".
    Info& info();
    /// @brief Logger for verbose-level messages. Messages are printed in default color
    ///        and are prefixed with "[VERBOSE]".
    Verbose& verbose();
    /// @brief Logger for warning-level messages. Messages are printed in yellow and are
    ///        prefixed with "[WARNING]".
    Warning& warning();

    /**
     * @brief Clear the output (e.g. clears the console or file).
     */
    void clear();

    /**
     * @brief Get the current date format.
     *
     * @return The current date format.
     */
    const char* date_format() const;

    /**
     * @brief Change the date format and the size of the date buffer.
     *
     * @param date_format       The new date format, e.g. "[%Y-%m-%d %H:%M:%S %z]".
     * @param date_buffer_size  The new size of the date buffer, it must be able to contain
     *                          the longest date format, including the null terminator,
     *                          e.g. 28 for "[2026-03-01 12:00:00 +0100]".
     *
     * @return True if the date format and buffer size were changed successfully.
     *         If \p date_format is empty or \p date_buffer_size is 0, false is returned.
     *         Also it will return false if the date format or buffer size cannot be allocated.
     */
    bool date_format(const std::string& date_format, const size_t date_buffer_size);

    /**
     * @brief End the current line or flushes the output.
     */
    void end();

    /**
     * @brief Flush the output (e.g. flushes the console).
     */
    void flush();

    /**
     * @brief Return the size of the buffer used for printf formatting.
     *
     * @return Current printf buffer size in bytes.
     */
    size_t printf_buffer_size() const;

    /**
     * @brief Set the size of the buffer used for printf formatting.
     *
     * The default size is 1024 bytes. It is recommended to change the size for one that can
     * contain the longest message that is expected to be printed.
     *
     * @param new_size New buffer size in bytes.
     */
    void printf_buffer_size(const size_t new_size);

    /**
     * @brief Get the current output path.
     *
     * @return The current output path, empty if is to standard output (stdout and stderr).
     */
    const std::filesystem::path& output() const;

    /**
     * @brief Switch log output to a new file path or type.
     *
     * @param type  The type of output to switch to.
     * @param path  If \p type is \p FILE or \p FILE_AND_CONSOLE, this path is used for the
     *              output log file. If \p type is \p CONSOLE then this path is ignored. If
     *              \p path is empty then output to \p CONSOLE is used.
     *
     * @return True if the new output \p path was opened successfully, false otherwise.
     *         If \p type is not \p CONSOLE and \p path is empty, false is returned.
     *         True is returned if \p type is \p CONSOLE no matter what \p path is.
     */
    bool output(const OutputType type, const std::filesystem::path& path = TO_CONSOLE);

    /**
     * @brief Check if the output is still open when logger is writting to a file.
     *
     * If the file is deleted while the logger is writting to it, it will reopen the file.
     *
     * @return True if the output is still open, or when writting to standard output
     *         (stdout and stderr), false if it was not possible to reopen the file.
     */
    bool verify_status() const;

  private:
    bool change_output(const OutputType type, const std::filesystem::path& path);

    Output output_;

    Debug debug_;
    Error error_;
    Info info_;
    Verbose verbose_;
    Warning warning_;
};

static Logger global_logger;
} // namespace ramrod

#ifndef RR_LOG
#define RR_LOG global_logger
#define RR_LOGD global_logger.debug().file_info(__FILE__, __LINE__)
#define RR_LOGE global_logger.error().file_info(__FILE__, __LINE__)
#define RR_LOGI global_logger.info().file_info(__FILE__, __LINE__)
#define RR_LOGV global_logger.verbose().file_info(__FILE__, __LINE__)
#define RR_LOGW global_logger.warning().file_info(__FILE__, __LINE__)
#endif

#endif // RAMROD_LOG_LOGGER_HPP
