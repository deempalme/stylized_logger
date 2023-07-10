#ifndef RAMROD_LOG_ERROR_H
#define RAMROD_LOG_ERROR_H

#include "ramrod/log_base.h"


namespace ramrod {
  class error_stream : public base_stream
  {
  public:
    error_stream();
  };

  inline static error_stream log_error;

} // namespace ramrod

namespace rr = ramrod;

#endif // RAMROD_LOG_ERROR_H
