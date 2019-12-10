#ifndef RAMROD_CONSOLE_FLUSH_H
#define RAMROD_CONSOLE_FLUSH_H

#include <iostream>

namespace ramrod {
  namespace console {
    class flush
    {
    public:
      flush() = default;

      flush &operator ()();

      friend std::ostream &operator<<(std::ostream &output, flush &/*input*/) {
        output << std::flush;
        return output;
      }
    };
  }
  extern console::flush flush;
}
namespace rr = ramrod;

#endif // RAMROD_CONSOLE_FLUSH_H
