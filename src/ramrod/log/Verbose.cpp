#include "ramrod/log/Verbose.hpp"


/// @brief String used to print the verbose level tag; default colo (white in most terminals)
static constexpr char VERBOSE_FORMAT[]{""};
/// @brief String used to print the verbose level tag
static constexpr char VERBOSE_TAG[]{"[VERBOSE] "};

namespace ramrod
{
    Verbose::Verbose()
        : Base{}
    {
        _ansi_format = VERBOSE_FORMAT;
        _level_tag = VERBOSE_TAG;
    }

    Verbose::Verbose(const std::filesystem::path &output_path)
        : Base{output_path}
    {
        _ansi_format = VERBOSE_FORMAT;
        _level_tag = VERBOSE_TAG;
    }
} // namespace ramrod