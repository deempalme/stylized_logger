#include "ramrod/console/endl.h"

ramrod::console::endl_stream &ramrod::console::endl_stream::operator ()(){
  std::cout << std::endl;
  return *this;
}
