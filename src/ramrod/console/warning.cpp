#include "ramrod/console/warning.h"

#include "ramrod/console/format.h"

#include <iostream>

#ifdef RAMROD_CONSOLE_H
  #define EXTERN_RAMROD_CONSOLE_FORMAT_H
#else
  #define EXTERN_RAMROD_CONSOLE_FORMAT_H extern
#endif

namespace ramrod {
  EXTERN_RAMROD_CONSOLE_FORMAT_H ramrod::console::format format;
}

ramrod::console::warning::warning() :
  message_("\033[1;30;48;5;11m Warning: \033[0;1;38;5;229m ")
{}

ramrod::console::warning &ramrod::console::warning::change_message(const std::string &new_message){
  message_ = "\033[1;30;48;5;11m" + new_message + "\033[0;1;38;5;229m ";
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const std::string &text){
  std::cout << message_ << text << ramrod::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const char *text){
  std::cout << message_ << text << ramrod::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const bool boolean){
  std::cout << message_ << boolean << ramrod::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const char character){
  std::cout << message_ << character << ramrod::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const unsigned char character){
  std::cout << message_ << character << ramrod::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const signed char character){
  std::cout << message_ << character << ramrod::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const int integer_number){
  std::cout << message_ << integer_number << ramrod::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const unsigned int unsigend_integer_number){
  std::cout << message_ << unsigend_integer_number << ramrod::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const short short_integer_number){
  std::cout << message_ << short_integer_number << ramrod::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const unsigned short unsigned_short_integer_number){
  std::cout << message_ << unsigned_short_integer_number << ramrod::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const long long_integer_number){
  std::cout << message_ << long_integer_number << ramrod::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const unsigned long unsigned_long_integer_number){
  std::cout << message_ << unsigned_long_integer_number << ramrod::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const float float_number){
  std::cout << message_ << float_number << ramrod::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const double double_number){
  std::cout << message_ << double_number << ramrod::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const long double long_double_number){
  std::cout << message_ << long_double_number << ramrod::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const std::string &text){
  std::cout << message_ << text << ramrod::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const char *text){
  std::cout << message_ << text << ramrod::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const bool boolean){
  std::cout << message_ << boolean << ramrod::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const char character){
  std::cout << message_ << character << ramrod::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const unsigned char character){
  std::cout << message_ << character << ramrod::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const signed char character){
  std::cout << message_ << character << ramrod::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const int integer_number){
  std::cout << message_ << integer_number << ramrod::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const unsigned int unsigend_integer_number){
  std::cout << message_ << unsigend_integer_number << ramrod::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const short short_integer_number){
  std::cout << message_ << short_integer_number << ramrod::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const unsigned short unsigned_short_integer_number){
  std::cout << message_ << unsigned_short_integer_number << ramrod::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const long long_integer_number){
  std::cout << message_ << long_integer_number << ramrod::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const unsigned long unsigned_long_integer_number){
  std::cout << message_ << unsigned_long_integer_number << ramrod::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const float float_number){
  std::cout << message_ << float_number << ramrod::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const double double_number){
  std::cout << message_ << double_number << ramrod::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const long double long_double_number){
  std::cout << message_ << long_double_number << ramrod::format;
  return *this;
}
