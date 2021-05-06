#include "ramrod/console.h"

#include "ramrod/console/format.h"

namespace ramrod {
  namespace console {
    int formatted(const char *format, const message::type type, ...){
      console::format.force_color(type);

      va_list arg;
      va_start(arg, type);
      const int result{std::vprintf(format, arg)};
      va_end(arg);
      console::format.force_color(message::type::regular, true);
      std::flush(std::cout);

      return result;
    }

    int formatted(const char *format, ...){
      va_list arg;
      va_start(arg, format);
      const int result{std::vprintf(format, arg)};
      va_end(arg);
      std::flush(std::cout);

      return result;
    }

    int printf(const char *format, const message::type type, ...){
      console::format.force_color(type);

      va_list arg;
      va_start(arg, type);
      const int result{std::vprintf(format, arg)};
      va_end(arg);
      console::format.force_color(message::type::regular, true);
      std::flush(std::cout);

      return result;
    }

    int printf(const char *format, ...){
      va_list arg;
      va_start(arg, format);
      const int result{std::vprintf(format, arg)};
      va_end(arg);
      std::flush(std::cout);

      return result;
    }
  } // namespace: console
} // namespace: ramrod



