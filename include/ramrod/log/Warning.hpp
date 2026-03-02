#ifndef RAMROD_LOG_WARNING_HPP
#define RAMROD_LOG_WARNING_HPP

#include <filesystem>

#include "ramrod/log/Base.hpp"

namespace ramrod
{
    /**
     * @brief Logger for warning-level messages (yellow ANSI color, "[WARNING]" tag).
     */
    class Warning : public Base
    {
    public:
        /** @brief Creates a warning logger that writes to standard output. */
        Warning();

        /**
         * @brief Creates a warning logger that writes to a file.
         *
         * @param output_path The path to the file to save messages to.
         */
        Warning(const std::filesystem::path &output_path);

        /** @brief Destructor. */
        virtual ~Warning() = default;
    };
} // namespace ramrod

#endif // RAMROD_LOG_WARNING_HPP
