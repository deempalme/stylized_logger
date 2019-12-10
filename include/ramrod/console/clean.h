#ifndef RAMROD_CONSOLE_CLEAN_H
#define RAMROD_CONSOLE_CLEAN_H

#include <iostream>

namespace ramrod {
  namespace console {
    class clean
    {
    public:
      clean() = default;

      void operator ()(const bool force = false);

      friend std::ostream &operator<<(std::ostream &output, clean &/*input*/) {
        output << "\033[2J\033[H\033[3J";
        return output;
      }
    };
  }
  extern console::clean clean;
}
namespace rr = ramrod;

#endif // RAMROD_CONSOLE_CLEAN_H
