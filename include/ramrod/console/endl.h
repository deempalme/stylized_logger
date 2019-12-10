#ifndef RAMROD_CONSOLE_ENDL_H
#define RAMROD_CONSOLE_ENDL_H

#include <iostream>

namespace ramrod {
  namespace console {
    class endl
    {
    public:
      endl() = default;

      endl &operator ()();

      friend std::ostream &operator<<(std::ostream &output, endl &/*input*/) {
        output << std::endl;
        return output;
      }
    };
  }
  extern console::endl endl;
}
namespace rr = ramrod;

#endif // RAMROD_CONSOLE_ENDL_H
