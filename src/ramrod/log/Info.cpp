#include "ramrod/log/Info.hpp"

/// @brief String used to print the info level tag; green color
static constexpr char INFO_FORMAT[]{"\e[38;5;118m"};
/// @brief String used to print the info level tag
static constexpr char INFO_TAG[]{"[INFO] "};

namespace ramrod
{
Info::Info(Writer& writer)
    : Base{writer}
{
    _ansi_format = INFO_FORMAT;
    _level_tag = INFO_TAG;
    _log_level = LogLevel::INFO;
}
} // namespace ramrod