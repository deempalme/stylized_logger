#include "ramrod/console/clean.h"

void ramrod::console::clean::operator ()(const bool force){
  if(force)
    std::cout << "\033[2J\033[H\033[3J";
  else
    std::cout << "\033[2J\033[H";
}
