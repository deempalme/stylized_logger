#include "ramrod/console/regular.h"

#include "ramrod/console/endl.h"
#include "ramrod/console/format.h"

#include <iostream>

namespace ramrod {
  namespace console {
    regular_stream::regular_stream() :
      message_("\033[0;1;38;5;193m "),
      format_("\033[0;1;38;5;193m")
    {}

    regular_stream &regular_stream::change_message(const std::string &new_message){
      if(new_message.size() <= 0)
        message_ = "\033[0;1;38;5;174m ";
      else
        message_ = "\033[1;41m" + new_message + "\033[0;1;38;5;174m ";
      return *this;
    }

    regular_stream &regular_stream::operator()(){
      std::cout << message_ << rr::format;
      return *this;
    }

    regular_stream &regular_stream::operator()(const std::string &text){
      std::cout << message_ << text << rr::format << std::endl;
      return *this;
    }

    regular_stream &regular_stream::operator()(const char *text){
      std::cout << message_ << text << rr::format << std::endl;
      return *this;
    }

    regular_stream &regular_stream::operator()(const bool boolean){
      std::cout << message_ << boolean << rr::format << std::endl;
      return *this;
    }

    regular_stream &regular_stream::operator()(const char character){
      std::cout << message_ << character << rr::format << std::endl;
      return *this;
    }

    regular_stream &regular_stream::operator()(const unsigned char character){
      std::cout << message_ << character << rr::format << std::endl;
      return *this;
    }

    regular_stream &regular_stream::operator()(const signed char character){
      std::cout << message_ << character << rr::format << std::endl;
      return *this;
    }

    regular_stream &regular_stream::operator()(const int integer_number){
      std::cout << message_ << integer_number << rr::format << std::endl;
      return *this;
    }

    regular_stream &regular_stream::operator()(const unsigned int unsigend_integer_number){
      std::cout << message_ << unsigend_integer_number << rr::format << std::endl;
      return *this;
    }

    regular_stream &regular_stream::operator()(const short short_integer_number){
      std::cout << message_ << short_integer_number << rr::format << std::endl;
      return *this;
    }

    regular_stream &regular_stream::operator()(const unsigned short unsigned_short_integer_number){
      std::cout << message_ << unsigned_short_integer_number << rr::format << std::endl;
      return *this;
    }

    regular_stream &regular_stream::operator()(const long long_integer_number){
      std::cout << message_ << long_integer_number << rr::format << std::endl;
      return *this;
    }

    regular_stream &regular_stream::operator()(const unsigned long unsigned_long_integer_number){
      std::cout << message_ << unsigned_long_integer_number << rr::format << std::endl;
      return *this;
    }

    regular_stream &regular_stream::operator()(const float float_number){
      std::cout << message_ << float_number << rr::format << std::endl;
      return *this;
    }

    regular_stream &regular_stream::operator()(const double double_number){
      std::cout << message_ << double_number << rr::format << std::endl;
      return *this;
    }

    regular_stream &regular_stream::operator()(const long double long_double_number){
      std::cout << message_ << long_double_number << rr::format << std::endl;
      return *this;
    }

    regular_stream &regular_stream::operator<<(const std::string &text){
      std::cout << format_ << text << rr::format;
      return *this;
    }

    regular_stream &regular_stream::operator<<(const char *text){
      std::cout << format_ << text << rr::format;
      return *this;
    }

    regular_stream &regular_stream::operator<<(const bool boolean){
      std::cout << format_ << boolean << rr::format;
      return *this;
    }

    regular_stream &regular_stream::operator<<(const char character){
      std::cout << format_ << character << rr::format;
      return *this;
    }

    regular_stream &regular_stream::operator<<(const unsigned char character){
      std::cout << format_ << character << rr::format;
      return *this;
    }

    regular_stream &regular_stream::operator<<(const signed char character){
      std::cout << format_ << character << rr::format;
      return *this;
    }

    regular_stream &regular_stream::operator<<(const int integer_number){
      std::cout << format_ << integer_number << rr::format;
      return *this;
    }

    regular_stream &regular_stream::operator<<(const unsigned int unsigend_integer_number){
      std::cout << format_ << unsigend_integer_number << rr::format;
      return *this;
    }

    regular_stream &regular_stream::operator<<(const short short_integer_number){
      std::cout << format_ << short_integer_number << rr::format;
      return *this;
    }

    regular_stream &regular_stream::operator<<(const unsigned short unsigned_short_integer_number){
      std::cout << format_ << unsigned_short_integer_number << rr::format;
      return *this;
    }

    regular_stream &regular_stream::operator<<(const long long_integer_number){
      std::cout << format_ << long_integer_number << rr::format;
      return *this;
    }

    regular_stream &regular_stream::operator<<(const unsigned long unsigned_long_integer_number){
      std::cout << format_ << unsigned_long_integer_number << rr::format;
      return *this;
    }

    regular_stream &regular_stream::operator<<(const float float_number){
      std::cout << format_ << float_number << rr::format;
      return *this;
    }

    regular_stream &regular_stream::operator<<(const double double_number){
      std::cout << format_ << double_number << rr::format;
      return *this;
    }

    regular_stream &regular_stream::operator<<(const long double long_double_number){
      std::cout << format_ << long_double_number << rr::format;
      return *this;
    }

    regular_stream &regular_stream::operator<<(const endl_stream &/*endls*/){
      std::cout << std::endl;
      return *this;
    }
  } // namespace: console
} // namespace: ramrod
