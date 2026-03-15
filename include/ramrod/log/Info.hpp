#ifndef RAMROD_LOG_INFO_HPP
#define RAMROD_LOG_INFO_HPP

#include "ramrod/log/Base.hpp"

namespace ramrod
{
    /**
     * @brief Logger for info-level messages (green ANSI color, "[INFO]" tag).
     */
    class Info : public Base
    {
    public:
        /**
         * @brief Creates an info logger that writes to the given writer.
         *
         * @param writer The object used to write messages.
         */
        Info(Writer& writer);

        /** @brief Destructor. */
        virtual ~Info() = default;
    };
} // namespace ramrod

#endif // RAMROD_LOG_INFO_HPP
