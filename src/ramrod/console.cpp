#include "ramrod/console.h"

#include "ramrod/console/format.h"

namespace ramrod {
  console::attention attention;
  console::clean clean;
  console::cout cout;
  console::endl endl;
  console::error error;
  console::flush flush;
#ifndef EXTERN_RAMROD_CONSOLE_FORMAT_H
  console::format format;
#endif
  console::regular regular;
  console::warning warning;
}

int ramrod::formatted(const char *format, const ramrod::message::type type, ...){
  ramrod::format.force_color(type);

  va_list arg;
  va_start(arg, type);
  const int result{std::vprintf(format, arg)};
  va_end(arg);
  ramrod::format.force_color(ramrod::message::type::message, true);
  std::flush(std::cout);

  return result;
}

int ramrod::formatted(const char *format ...){
  va_list arg;
  va_start(arg, format);
  const int result{std::vprintf(format, arg)};
  va_end(arg);
  std::flush(std::cout);

  return result;
}

int ramrod::printf(const char *format, const ramrod::message::type type, ...){
  ramrod::format.force_color(type);

  va_list arg;
  va_start(arg, type);
  const int result{std::vprintf(format, arg)};
  va_end(arg);
  ramrod::format.force_color(ramrod::message::type::message, true);
  std::flush(std::cout);

  return result;
}

int ramrod::printf(const char *format, ...){
  va_list arg;
  va_start(arg, format);
  const int result{std::vprintf(format, arg)};
  va_end(arg);
  std::flush(std::cout);

  return result;
}


