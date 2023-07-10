#ifndef RAMROD_LOG_TYPES_H
#define RAMROD_LOG_TYPES_H

namespace ramrod {
  class log_types
  {
  public:
    enum code : int {
      black          = 0,
      red            = 1,
      green          = 2,
      yellow         = 3,
      blue           = 4,
      magenta        = 5,
      cyan           = 6,
      white          = 7,
      bright_black   = 8,
      bright_red     = 9,
      bright_green   = 10,
      bright_yellow  = 11,
      bright_blue    = 12,
      bright_magenta = 13,
      bright_cyan    = 14,
      bright_white   = 15
    };

    enum style : int {
      reset           = 0,
      bold            = 1,
      faint           = 2,
      italic          = 3,
      underline       = 4,
      slow_blink      = 5,
      rapid_blink     = 6,
      inverse         = 7, // Swap text and background color
      conceil         = 8,
      crossed_out     = 9,
      default_font    = 10,
      bold_off        = 21,
      normal          = 22,
      italic_off      = 23,
      underline_off   = 24,
      inverse_off     = 27,
      reveal          = 28,
      crossed_out_off = 29,
      foreground      = 38,
      background      = 48,
      overline        = 53,
      overline_off    = 55
    };

    enum type : unsigned int {
      attention = 0u,
      error     = 1u,
      good      = 2u,
      warning   = 3u
    };

    enum level : unsigned int {
      ignore          = 0u,
      print           = 1u,
      store           = 2u,
      print_and_store = 3u
    };
  };
} // namespace ramrod

#endif // RAMROD_LOG_TYPES_H
