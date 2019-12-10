#include "ramrod/console/attention.h"

#include "ramrod/console/format.h"

#include <iostream>

ramrod::console::attention::attention() :
  message_("\033[1;30;46m Attention: \033[0;1;38;5;195m ")
{}

ramrod::console::attention &ramrod::console::attention::change_message(const std::string &new_message){
  message_ = "\033[1;30;46m" + new_message + "\033[0;1;38;5;195m ";
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator()(const std::string &text){
  std::cout << message_ << text << rr::format << std::endl;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator()(const char *text){
  std::cout << message_ << text << rr::format << std::endl;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator()(const bool boolean){
  std::cout << message_ << boolean << rr::format << std::endl;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator()(const char character){
  std::cout << message_ << character << rr::format << std::endl;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator()(const unsigned char character){
  std::cout << message_ << character << rr::format << std::endl;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator()(const signed char character){
  std::cout << message_ << character << rr::format << std::endl;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator()(const int integer_number){
  std::cout << message_ << integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator()(const unsigned int unsigend_integer_number){
  std::cout << message_ << unsigend_integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator()(const short short_integer_number){
  std::cout << message_ << short_integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator()(const unsigned short unsigned_short_integer_number){
  std::cout << message_ << unsigned_short_integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator()(const long long_integer_number){
  std::cout << message_ << long_integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator()(const unsigned long unsigned_long_integer_number){
  std::cout << message_ << unsigned_long_integer_number << rr::format << std::endl;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator()(const float float_number){
  std::cout << message_ << float_number << rr::format << std::endl;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator()(const double double_number){
  std::cout << message_ << double_number << rr::format << std::endl;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator()(const long double long_double_number){
  std::cout << message_ << long_double_number << rr::format << std::endl;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator<<(const std::string &text){
  std::cout << message_ << text << rr::format;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator<<(const char *text){
  std::cout << message_ << text << rr::format;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator<<(const bool boolean){
  std::cout << message_ << boolean << rr::format;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator<<(const char character){
  std::cout << message_ << character << rr::format;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator<<(const unsigned char character){
  std::cout << message_ << character << rr::format;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator<<(const signed char character){
  std::cout << message_ << character << rr::format;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator<<(const int integer_number){
  std::cout << message_ << integer_number << rr::format;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator<<(const unsigned int unsigend_integer_number){
  std::cout << message_ << unsigend_integer_number << rr::format;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator<<(const short short_integer_number){
  std::cout << message_ << short_integer_number << rr::format;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator<<(const unsigned short unsigned_short_integer_number){
  std::cout << message_ << unsigned_short_integer_number << rr::format;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator<<(const long long_integer_number){
  std::cout << message_ << long_integer_number << rr::format;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator<<(const unsigned long unsigned_long_integer_number){
  std::cout << message_ << unsigned_long_integer_number << rr::format;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator<<(const float float_number){
  std::cout << message_ << float_number << rr::format;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator<<(const double double_number){
  std::cout << message_ << double_number << rr::format;
  return *this;
}

ramrod::console::attention &ramrod::console::attention::operator<<(const long double long_double_number){
  std::cout << message_ << long_double_number << rr::format;
  return *this;
}

ramrod::console::attention attention;
