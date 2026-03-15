#ifndef RAMROD_LOG_VERBOSE_HPP
#define RAMROD_LOG_VERBOSE_HPP

#include "ramrod/log/Base.hpp"

namespace ramrod
{
    /**
     * @brief Logger for verbose-level messages (default color, "[VERBOSE]" tag).
     */
    class Verbose : public Base
    {
    public:
        /**
         * @brief Creates a verbose logger that writes to the given writer.
         *
         * @param writer The object used to write messages.
         */
        Verbose(Writer& writer);

        /** @brief Destructor. */
        virtual ~Verbose() = default;
    };
} // namespace ramrod

#endif // RAMROD_LOG_VERBOSE_HPP
