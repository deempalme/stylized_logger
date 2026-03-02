#ifndef RAMROD_LOG_OUTPUT_FILE_HPP
#define RAMROD_LOG_OUTPUT_FILE_HPP

#include <filesystem>
#include <fstream>
#include <utility>

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
         * @brief Writes all forwarded arguments to the file (stream insertion).
         *
         * @param args Values to write; each is sent to the file stream with operator<<.
         */
        template <typename... Args>
        void operator()(Args&&... args)
        {
            (file_ << ... << std::forward<Args>(args));
        }

        /**
         * @brief Clears the file (truncates to zero size).
         */
        void clear() override;

        /**
         * @brief Ends the current line by adding a new line to the end of the file.
         */
        void end() override;

        /**
         * @brief Sets the ANSI format for subsequent output (stored; written when used).
         *
         * @param ansi_format Null-terminated string with ANSI escape codes.
         */
        void format(const char *ansi_format) override;

        /**
         * @brief Checks if the file is open and writable.
         *
         * If the file was deleted after being opened, it will be recreated on the next write
         * when verify_status() is called.
         *
         * @return True if the file is open, false otherwise.
         */
        bool verify_status() override;

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