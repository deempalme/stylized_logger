#ifndef RAMROD_CONSOLE_COUT_H
#define RAMROD_CONSOLE_COUT_H

#include <iostream>

namespace ramrod {
  namespace console {
    class cout_stream : public std::ostream
    {
    public:
      cout_stream() = default;
    };

    inline cout_stream cout;
  }
}

namespace rr = ramrod::console;

#endif // RAMROD_CONSOLE_COUT_H
