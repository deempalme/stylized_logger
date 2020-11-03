#include "ramrod/console/flush.h"

ramrod::console::flush_stream &ramrod::console::flush_stream::operator ()(){
  std::flush(std::cout);
  return *this;
}
