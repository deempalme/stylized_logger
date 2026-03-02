#ifndef RAMROD_LOG_DEBUG_HPP
#define RAMROD_LOG_DEBUG_HPP

#include <filesystem>

#include "ramrod/log/Base.hpp"

namespace ramrod
{
    /**
     * @brief Logger for debug-level messages (blue ANSI color, "[DEBUG]" tag).
     */
    class Debug : public Base
    {
    public:
        /** @brief Creates a debug logger that writes to standard output. */
        Debug();

        /**
         * @brief Creates a debug logger that writes to a file.
         *
         * @param output_path The path to the file to save messages to.
         */
        Debug(const std::filesystem::path &output_path);

        /** @brief Destructor. */
        virtual ~Debug() = default;
    };
} // namespace ramrod

#endif // RAMROD_LOG_DEBUG_HPP
