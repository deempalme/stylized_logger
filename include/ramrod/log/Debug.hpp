#ifndef RAMROD_LOG_DEBUG_HPP
#define RAMROD_LOG_DEBUG_HPP

#include "ramrod/log/Base.hpp"

namespace ramrod
{
    /**
     * @brief Logger for debug-level messages (blue ANSI color, "[DEBUG]" tag).
     */
    class Debug : public Base
    {
    public:
        /**
         * @brief Creates a debug logger that writes to the given writer.
         *
         * @param writer The object used to write messages.
         */
        Debug(Writer& writer);

        /** @brief Destructor. */
        virtual ~Debug() = default;
    };
} // namespace ramrod

#endif // RAMROD_LOG_DEBUG_HPP
