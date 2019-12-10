#include "ramrod/console.h"

#include "ramrod/console/format.h"

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


