#ifndef RAMROD_LOG_ATTENTION_H
#define RAMROD_LOG_ATTENTION_H

#include "ramrod/log_base.h"


namespace ramrod {
  class attention_stream : public base_stream
  {
  public:
    attention_stream();
  };

  inline static attention_stream log_attention;

} // namespace ramrod

namespace rr = ramrod;

#endif // RAMROD_LOG_ATTENTION_H
