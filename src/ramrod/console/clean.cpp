#include "ramrod/console/clean.h"

namespace ramrod {
  namespace console {
    void clean_stream::operator ()(const bool force){
      if(force)
        std::cout << "\033[2J\033[H\033[3J";
      else
        std::cout << "\033[2J\033[H";
    }
  } // namespace: console
} // namespace: ramrod

extern ramrod::console::clean_stream clean = ramrod::console::clean_stream();
