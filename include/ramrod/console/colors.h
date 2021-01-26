#ifndef RAMROD_CONSOLE_COLORS_H
#define RAMROD_CONSOLE_COLORS_H

// https://www.wikiwand.com/en/ANSI_escape_code
namespace ramrod {
  namespace console {
    namespace background {
      constexpr const char black[]  = "\033[48;5;232;38;5;231m";
      constexpr const char blue[]   = "\033[48;5;123;38;5;232m";
      constexpr const char green[]  = "\033[48;5;154;38;5;232m";
      constexpr const char red[]    = "\033[48;5;196;38;5;231m";
      constexpr const char white[]  = "\033[48;5;231;38;5;232m";
      constexpr const char yellow[] = "\033[48:5;226;38;5;232m";
    } // namespace: background

    namespace bold {
      constexpr const char black[]  = "\033[1;38;5;232m";
      constexpr const char blue[]   = "\033[1;38;5;123m";
      constexpr const char green[]  = "\033[1;38;5;154m";
      constexpr const char red[]    = "\033[1;38;5;196m";
      constexpr const char white[]  = "\033[1;38;5;231m";
      constexpr const char yellow[] = "\033[1;38:5;226m";
    } // namespace: bold

    constexpr const char black[]  = "\033[22;38;5;232m";
    constexpr const char blue[]   = "\033[22;38;5;195m";
    constexpr const char green[]  = "\033[22;38;5;154m";
    constexpr const char red[]    = "\033[22;38;5;174m";
    constexpr const char white[]  = "\033[22;38;5;231m";
    constexpr const char yellow[] = "\033[22;38;5;229m";

    constexpr const char none[]   = "\033[0m";
  } // namespace: console
} // namespace: ramrod

namespace rr = ramrod::console;

#endif // RAMROD_CONSOLE_COLORS_H
