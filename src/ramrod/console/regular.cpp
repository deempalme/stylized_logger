#include "ramrod/console/regular.h"

#include "ramrod/console/format.h"

#include <iostream>

ramrod::console::regular::regular() :
  message_("\033[0;1;38;5;193m ")
{}

ramrod::console::regular &ramrod::console::regular::change_message(const std::string &new_message){
  if(new_message.size() <= 0)
    message_ = "\033[0;1;38;5;174m ";
  else
    message_ = "\033[1;41m" + new_message + "\033[0;1;38;5;174m ";
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator()(const std::string &text){
  std::cout << message_ << text << rr::format << std::endl;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator()(const char *text){
  std::cout << message_ << text << rr::format << std::endl;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator()(const bool boolean){
  std::cout << message_ << boolean << rr::format << std::endl;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator()(const char character){
  std::cout << message_ << character << rr::format << std::endl;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator()(const unsigned char character){
  std::cout << message_ << character << rr::format << std::endl;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator()(const signed char character){
  std::cout << message_ << character << rr::format << std::endl;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator()(const int integer_number){
  std::cout << message_ << integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator()(const unsigned int unsigend_integer_number){
  std::cout << message_ << unsigend_integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator()(const short short_integer_number){
  std::cout << message_ << short_integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator()(const unsigned short unsigned_short_integer_number){
  std::cout << message_ << unsigned_short_integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator()(const long long_integer_number){
  std::cout << message_ << long_integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator()(const unsigned long unsigned_long_integer_number){
  std::cout << message_ << unsigned_long_integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator()(const float float_number){
  std::cout << message_ << float_number << rr::format << std::endl;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator()(const double double_number){
  std::cout << message_ << double_number << rr::format << std::endl;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator()(const long double long_double_number){
  std::cout << message_ << long_double_number << rr::format << std::endl;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator<<(const std::string &text){
  std::cout << message_ << text << rr::format;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator<<(const char *text){
  std::cout << message_ << text << rr::format;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator<<(const bool boolean){
  std::cout << message_ << boolean << rr::format;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator<<(const char character){
  std::cout << message_ << character << rr::format;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator<<(const unsigned char character){
  std::cout << message_ << character << rr::format;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator<<(const signed char character){
  std::cout << message_ << character << rr::format;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator<<(const int integer_number){
  std::cout << message_ << integer_number << rr::format;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator<<(const unsigned int unsigend_integer_number){
  std::cout << message_ << unsigend_integer_number << rr::format;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator<<(const short short_integer_number){
  std::cout << message_ << short_integer_number << rr::format;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator<<(const unsigned short unsigned_short_integer_number){
  std::cout << message_ << unsigned_short_integer_number << rr::format;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator<<(const long long_integer_number){
  std::cout << message_ << long_integer_number << rr::format;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator<<(const unsigned long unsigned_long_integer_number){
  std::cout << message_ << unsigned_long_integer_number << rr::format;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator<<(const float float_number){
  std::cout << message_ << float_number << rr::format;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator<<(const double double_number){
  std::cout << message_ << double_number << rr::format;
  return *this;
}

ramrod::console::regular &ramrod::console::regular::operator<<(const long double long_double_number){
  std::cout << message_ << long_double_number << rr::format;
  return *this;
}

ramrod::console::regular regular;
