#include "ramrod/log_warning.h"


namespace ramrod {
  warning_stream::warning_stream(){
    _ansi_format = "\033[0;1;38;5;229m";
  }
} // namespace ramrod
