#include "ramrod/log/Error.hpp"

/// @brief String used to print the error level tag; red color
static constexpr char ERROR_FORMAT[]{"\e[0;91m"};
/// @brief String used to print the error level tag
static constexpr char ERROR_TAG[]{"[ERROR] "};

namespace ramrod
{
Error::Error(Writer& writer)
    : Base{writer}
{
    _ansi_format = ERROR_FORMAT;
    _level_tag = ERROR_TAG;
}
} // namespace ramrod