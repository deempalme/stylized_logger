#ifndef RAMROD_CONSOLE_ENDL_H
#define RAMROD_CONSOLE_ENDL_H

#include <iostream>

namespace ramrod {
  namespace console {
    class endl_stream
    {
    public:
      endl_stream() = default;

      endl_stream &operator ()();

      friend std::ostream &operator<<(std::ostream &output, endl_stream &/*input*/) {
        output << std::endl;
        return output;
      }
    };
    inline endl_stream endl;
  }
}
namespace rr = ramrod::console;

#endif // RAMROD_CONSOLE_ENDL_H
