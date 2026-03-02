#ifndef RAMROD_LOG_VERBOSE_HPP
#define RAMROD_LOG_VERBOSE_HPP

#include <filesystem>

#include "ramrod/log/Base.hpp"

namespace ramrod
{
    /**
     * @brief Logger for verbose-level messages (default color, "[VERBOSE]" tag).
     */
    class Verbose : public Base
    {
    public:
        /** @brief Creates a verbose logger that writes to standard output. */
        Verbose();

        /**
         * @brief Creates a verbose logger that writes to a file.
         *
         * @param output_path The path to the file to save messages to.
         */
        Verbose(const std::filesystem::path &output_path);

        /** @brief Destructor. */
        virtual ~Verbose() = default;
    };
} // namespace ramrod

#endif // RAMROD_LOG_VERBOSE_HPP
