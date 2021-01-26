#ifndef RAMROD_CONSOLE_CLEAN_H
#define RAMROD_CONSOLE_CLEAN_H

#include <iostream>

namespace ramrod {
  namespace console {
    class clean_stream
    {
    public:
      clean_stream() = default;

      void operator ()(const bool force = false);

      friend std::ostream &operator<<(std::ostream &output, clean_stream &/*input*/) {
        output << "\033[2J\033[H\033[3J";
        return output;
      }
    };

    inline clean_stream clean;

  } // namespace: console
} // namespace: ramrod

namespace rr = ramrod::console;

#endif // RAMROD_CONSOLE_CLEAN_H
