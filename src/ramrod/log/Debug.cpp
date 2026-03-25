#include "ramrod/log/Debug.hpp"

/// @brief String used to print the debug level tag; blue color
static constexpr char DEBUG_FORMAT[]{"\e[38;5;51m"};
/// @brief String used to print the debug level tag
static constexpr char DEBUG_TAG[]{"[DEBUG] "};

namespace ramrod
{
Debug::Debug(Writer& writer)
    : Base{writer}
{
    _ansi_format = DEBUG_FORMAT;
    _level_tag = DEBUG_TAG;
    _log_level = LogLevel::DEBUG;
}
} // namespace ramrod