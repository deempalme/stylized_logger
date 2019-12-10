#include "ramrod/console/endl.h"

ramrod::console::endl &ramrod::console::endl::operator ()(){
  std::cout << std::endl;
  return *this;
}

ramrod::console::endl endl;
