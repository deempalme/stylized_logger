#include "ramrod/log/Output.hpp"

#include <iostream>

/// @brief String used to clear all ANSI format: 0m - reset all styles
static constexpr char CLEAR_FORMAT[]{"\e[0m"};
/// @brief String used to clear the terminal:
///        2J - clear screen
///        H  - move cursor to home
///        3J - clear screen and scrollback buffer
static constexpr char CLEAR_TERMINAL[]{"\e[2J\e[H\e[3J"};

namespace ramrod
{

    void Output::clear()
    {
        std::cout << CLEAR_TERMINAL;
    }
    void Output::end()
    {
        std::cout << CLEAR_FORMAT << std::endl;
    }

    void Output::format(const char *ansi_format)
    {
        std::cout << ansi_format;
    }

    bool Output::verify_status()
    {
        return true;
    }
} // namespace ramrod
