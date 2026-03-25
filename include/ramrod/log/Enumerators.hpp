#ifndef RAMROD_LOG_ENUMERATORS_HPP
#define RAMROD_LOG_ENUMERATORS_HPP

#include <cstdint>

namespace ramrod
{
/**
 * @brief Log level enumerator
 */
enum class LogLevel : std::uint8_t
{
    /// @brief Verbose level
    VERBOSE = 0u,
    /// @brief Debug level
    DEBUG = 1u,
    /// @brief Info level
    INFO = 2u,
    /// @brief Warning level
    WARNING = 3u,
    /// @brief Error level
    ERROR = 4u,
};
} // namespace ramrod

#endif // RAMROD_LOG_ENUMERATORS_HPP
