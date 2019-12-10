#include "ramrod/console/warning.h"

#include "ramrod/console/format.h"

#include <iostream>

ramrod::console::warning::warning() :
  message_("\033[1;30;48;5;11m Warning: \033[0;1;38;5;229m ")
{}

ramrod::console::warning &ramrod::console::warning::change_message(const std::string &new_message){
  message_ = "\033[1;30;48;5;11m" + new_message + "\033[0;1;38;5;229m ";
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const std::string &text){
  std::cout << message_ << text << rr::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const char *text){
  std::cout << message_ << text << rr::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const bool boolean){
  std::cout << message_ << boolean << rr::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const char character){
  std::cout << message_ << character << rr::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const unsigned char character){
  std::cout << message_ << character << rr::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const signed char character){
  std::cout << message_ << character << rr::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const int integer_number){
  std::cout << message_ << integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const unsigned int unsigend_integer_number){
  std::cout << message_ << unsigend_integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const short short_integer_number){
  std::cout << message_ << short_integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const unsigned short unsigned_short_integer_number){
  std::cout << message_ << unsigned_short_integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const long long_integer_number){
  std::cout << message_ << long_integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const unsigned long unsigned_long_integer_number){
  std::cout << message_ << unsigned_long_integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const float float_number){
  std::cout << message_ << float_number << rr::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const double double_number){
  std::cout << message_ << double_number << rr::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator()(const long double long_double_number){
  std::cout << message_ << long_double_number << rr::format << std::endl;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const std::string &text){
  std::cout << message_ << text << rr::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const char *text){
  std::cout << message_ << text << rr::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const bool boolean){
  std::cout << message_ << boolean << rr::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const char character){
  std::cout << message_ << character << rr::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const unsigned char character){
  std::cout << message_ << character << rr::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const signed char character){
  std::cout << message_ << character << rr::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const int integer_number){
  std::cout << message_ << integer_number << rr::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const unsigned int unsigend_integer_number){
  std::cout << message_ << unsigend_integer_number << rr::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const short short_integer_number){
  std::cout << message_ << short_integer_number << rr::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const unsigned short unsigned_short_integer_number){
  std::cout << message_ << unsigned_short_integer_number << rr::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const long long_integer_number){
  std::cout << message_ << long_integer_number << rr::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const unsigned long unsigned_long_integer_number){
  std::cout << message_ << unsigned_long_integer_number << rr::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const float float_number){
  std::cout << message_ << float_number << rr::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const double double_number){
  std::cout << message_ << double_number << rr::format;
  return *this;
}

ramrod::console::warning &ramrod::console::warning::operator<<(const long double long_double_number){
  std::cout << message_ << long_double_number << rr::format;
  return *this;
}

ramrod::console::warning warning;
