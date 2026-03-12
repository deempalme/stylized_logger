#ifndef RAMROD_LOG_CONSTANTS_HPP
#define RAMROD_LOG_CONSTANTS_HPP

#include <cstdint>
#include <exception>
#include <string>
#include <string_view>
#include <system_error>

namespace ramrod
{
/// @brief String used to clear all ANSI format: 0m - reset all styles
static constexpr char CLEAR_FORMAT[]{"\e[0m"};
/// @brief String used to clear the terminal:
///        2J - clear screen
///        H  - move cursor to home
///        3J - clear screen and scrollback buffer
static constexpr char CLEAR_TERMINAL[]{"\e[2J\e[H\e[3J"};
/// @brief String used to add a new line to the end of the file
static constexpr char ENDL{'\n'};
/// @brief String used to prefix the error code: "("
static constexpr char ERROR_PREFIX{'('};
/// @brief String used to suffix the error code: ") "
static constexpr char ERROR_SUFFIX[]{") "};
/// @brief String used to prefix the file and line information: "["
static constexpr char INFO_PREFIX{'['};
/// @brief String used to separate the file and line information: "]["
static constexpr char INFO_SEPARATOR[]{"]["};
/// @brief String used to suffix the file and line information: "]"
static constexpr char INFO_SUFFIX[]{"] "};
} // namespace ramrod

#endif // RAMROD_LOG_CONSTANTS_HPP