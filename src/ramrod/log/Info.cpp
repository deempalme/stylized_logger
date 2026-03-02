#include "ramrod/log/Info.hpp"


/// @brief String used to print the info level tag; green color
static constexpr char INFO_FORMAT[]{"\e[38;5;118m"};
/// @brief String used to print the info level tag
static constexpr char INFO_TAG[]{"[INFO] "};

namespace ramrod
{
    Info::Info()
        : Base{}
    {
        _ansi_format = INFO_FORMAT;
        _level_tag = INFO_TAG;
    }

    Info::Info(const std::filesystem::path &output_path)
        : Base{output_path}
    {
        _ansi_format = INFO_FORMAT;
        _level_tag = INFO_TAG;
    }
} // namespace ramrod