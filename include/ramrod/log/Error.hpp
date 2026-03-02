#ifndef RAMROD_LOG_ERROR_HPP
#define RAMROD_LOG_ERROR_HPP

#include <filesystem>

#include "ramrod/log/Base.hpp"

namespace ramrod
{
    /**
     * @brief Logger for error-level messages (red ANSI color, "[ERROR]" tag).
     */
    class Error : public Base
    {
    public:
        /** @brief Creates an error logger that writes to standard output. */
        Error();

        /**
         * @brief Creates an error logger that writes to a file.
         *
         * @param output_path The path to the file to save messages to.
         */
        Error(const std::filesystem::path &output_path);

        /** @brief Destructor. */
        virtual ~Error() = default;
    };
} // namespace ramrod

#endif // RAMROD_LOG_ERROR_HPP
