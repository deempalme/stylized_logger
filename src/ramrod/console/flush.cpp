#include "ramrod/console/flush.h"

ramrod::console::flush &ramrod::console::flush::operator ()(){
  std::flush(std::cout);
  return *this;
}
