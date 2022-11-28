#ifndef RAMROD_LOG_WARNING_H
#define RAMROD_LOG_WARNING_H

#include "ramrod/log_base.h"


namespace ramrod {
  class warning_stream : public base_stream
  {
  public:
    warning_stream();
  };

  inline static warning_stream log_warning;

} // namespace ramrod

namespace rr = ramrod;

#endif // RAMROD_LOG_WARNING_H
