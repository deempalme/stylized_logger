#ifndef RAMROD_LOG_ERROR_HPP
#define RAMROD_LOG_ERROR_HPP

#include "ramrod/log/Base.hpp"

namespace ramrod
{
    /**
     * @brief Logger for error-level messages (red ANSI color, "[ERROR]" tag).
     */
    class Error : public Base
    {
    public:
        /**
         * @brief Creates an error logger that writes to the given writer.
         *
         * @param writer The object used to write messages.
         */
        Error(Writer& writer);

        /** @brief Destructor. */
        virtual ~Error() = default;
    };
} // namespace ramrod

#endif // RAMROD_LOG_ERROR_HPP
