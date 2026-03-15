#ifndef RAMROD_LOG_WARNING_HPP
#define RAMROD_LOG_WARNING_HPP

#include "ramrod/log/Base.hpp"

namespace ramrod
{
    /**
     * @brief Logger for warning-level messages (yellow ANSI color, "[WARNING]" tag).
     */
    class Warning : public Base
    {
    public:
        /**
         * @brief Creates a warning logger that writes to the given writer.
         *
         * @param writer The object used to write messages.
         */
        Warning(Writer& writer);

        /** @brief Destructor. */
        virtual ~Warning() = default;
    };
} // namespace ramrod

#endif // RAMROD_LOG_WARNING_HPP
