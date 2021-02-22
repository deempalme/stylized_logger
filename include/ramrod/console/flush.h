#ifndef RAMROD_CONSOLE_FLUSH_H
#define RAMROD_CONSOLE_FLUSH_H

#include <iostream>

namespace ramrod {
  namespace console {
    class flush_stream
    {
    public:
      flush_stream() = default;

      flush_stream &operator ()();

      friend std::ostream &operator<<(std::ostream &output, flush_stream &/*input*/) {
        output << std::flush;
        return output;
      }
    };
    inline flush_stream flush;
  }
}
namespace rr = ramrod::console;

#endif // RAMROD_CONSOLE_FLUSH_H
