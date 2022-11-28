#ifndef RAMROD_LOG_GOOD_H
#define RAMROD_LOG_GOOD_H

#include "ramrod/log_base.h"


namespace ramrod {
  class good_stream : public base_stream
  {
  public:
    good_stream();
  };

  inline static good_stream log_good;

} // namespace ramrod

namespace rr = ramrod;

#endif // RAMROD_LOG_GOOD_H
