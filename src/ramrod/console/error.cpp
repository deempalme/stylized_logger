#include "ramrod/console/error.h"

#include "ramrod/console/format.h"

#include <iostream>

ramrod::console::error::error() :
  message_("\033[1;41m Error: \033[0;1;38;5;174m ")
{}

ramrod::console::error &ramrod::console::error::change_message(const std::string &new_message){
  message_ = "\033[1;41m" + new_message + "\033[0;1;38;5;174m ";
  return *this;
}

ramrod::console::error &ramrod::console::error::operator()(const std::string &text){
  std::cout << message_ << text << rr::format << std::endl;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator()(const char *text){
  std::cout << message_ << text << rr::format << std::endl;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator()(const bool boolean){
  std::cout << message_ << boolean << rr::format << std::endl;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator()(const char character){
  std::cout << message_ << character << rr::format << std::endl;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator()(const unsigned char character){
  std::cout << message_ << character << rr::format << std::endl;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator()(const signed char character){
  std::cout << message_ << character << rr::format << std::endl;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator()(const int integer_number){
  std::cout << message_ << integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator()(const unsigned int unsigend_integer_number){
  std::cout << message_ << unsigend_integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator()(const short short_integer_number){
  std::cout << message_ << short_integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator()(const unsigned short unsigned_short_integer_number){
  std::cout << message_ << unsigned_short_integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator()(const long long_integer_number){
  std::cout << message_ << long_integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator()(const unsigned long unsigned_long_integer_number){
  std::cout << message_ << unsigned_long_integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator()(const float float_number){
  std::cout << message_ << float_number << rr::format << std::endl;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator()(const double double_number){
  std::cout << message_ << double_number << rr::format << std::endl;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator()(const long double long_double_number){
  std::cout << message_ << long_double_number << rr::format << std::endl;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator<<(const std::string &text){
  std::cout << message_ << text << rr::format;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator<<(const char *text){
  std::cout << message_ << text << rr::format;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator<<(const bool boolean){
  std::cout << message_ << boolean << rr::format;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator<<(const char character){
  std::cout << message_ << character << rr::format;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator<<(const unsigned char character){
  std::cout << message_ << character << rr::format;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator<<(const signed char character){
  std::cout << message_ << character << rr::format;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator<<(const int integer_number){
  std::cout << message_ << integer_number << rr::format;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator<<(const unsigned int unsigend_integer_number){
  std::cout << message_ << unsigend_integer_number << rr::format;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator<<(const short short_integer_number){
  std::cout << message_ << short_integer_number << rr::format;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator<<(const unsigned short unsigned_short_integer_number){
  std::cout << message_ << unsigned_short_integer_number << rr::format;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator<<(const long long_integer_number){
  std::cout << message_ << long_integer_number << rr::format;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator<<(const unsigned long unsigned_long_integer_number){
  std::cout << message_ << unsigned_long_integer_number << rr::format;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator<<(const float float_number){
  std::cout << message_ << float_number << rr::format;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator<<(const double double_number){
  std::cout << message_ << double_number << rr::format;
  return *this;
}

ramrod::console::error &ramrod::console::error::operator<<(const long double long_double_number){
  std::cout << message_ << long_double_number << rr::format;
  return *this;
}

ramrod::console::error error;
