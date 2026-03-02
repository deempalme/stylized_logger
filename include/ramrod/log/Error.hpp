#ifndef RAMROD_LOG_ERROR_HPP
#define RAMROD_LOG_ERROR_HPP

#include "ramrod/log/Base.hpp"

namespace ramrod
{
    class Error : public Base
    {
    public:
        static Error& instance();

    private:
        Error();
        Error(Error &object) = delete;
        Error(const Error &object) = delete;
    };

    inline static Error& error{Error::instance()};
} // namespace ramrod

/**
 * @brief Print timestamp, file, and line.
 *
 * @return Reference to \p Error instance
 */
#define RR_LOGE error.header(__FILE__, __LINE__)

#endif // RAMROD_LOG_ERROR_HPP
