#ifndef RAMROD_CONSOLE_COUT_H
#define RAMROD_CONSOLE_COUT_H

#include <iostream>

namespace ramrod {
  namespace console {
    class cout : public std::ostream
    {
    public:
      cout() = default;
    };
  }
}

namespace rr = ramrod;

#endif // RAMROD_CONSOLE_COUT_H
