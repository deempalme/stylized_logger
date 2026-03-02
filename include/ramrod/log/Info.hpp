#ifndef RAMROD_LOG_INFO_HPP
#define RAMROD_LOG_INFO_HPP

#include <filesystem>

#include "ramrod/log/Base.hpp"

namespace ramrod
{
    /**
     * @brief Logger for info-level messages (green ANSI color, "[INFO]" tag).
     */
    class Info : public Base
    {
    public:
        /** @brief Creates an info logger that writes to standard output. */
        Info();

        /**
         * @brief Creates an info logger that writes to a file.
         *
         * @param output_path The path to the file to save messages to.
         */
        Info(const std::filesystem::path &output_path);

        /** @brief Destructor. */
        virtual ~Info() = default;
    };
} // namespace ramrod

#endif // RAMROD_LOG_INFO_HPP
