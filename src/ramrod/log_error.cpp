#include "ramrod/log_error.h"


namespace ramrod {
  error_stream::error_stream(){
    _ansi_format = "\033[0;1;38;5;174m";
  }
} // namespace ramrod
