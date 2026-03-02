#include "ramrod/log/Warning.hpp"


/// @brief String used to print the warning level tag; yellow color
static constexpr char WARNING_FORMAT[]{"\e[0;93m"};
/// @brief String used to print the warning level tag
static constexpr char WARNING_TAG[]{"[WARNING] "};

namespace ramrod
{
    Warning::Warning()
        : Base{}
    {
        _ansi_format = WARNING_FORMAT;
        _level_tag = WARNING_TAG;
    }

    Warning::Warning(const std::filesystem::path &output_path)
        : Base{output_path}
    {
        _ansi_format = WARNING_FORMAT;
        _level_tag = WARNING_TAG;
    }
} // namespace ramrod