#include "ramrod/log_perror.h"

#include <cstring>
#include <iostream>

#include "ramrod/log.h"
#include "ramrod/log_format.h"


namespace ramrod {
  perror_stream::perror_stream(){
    _ansi_format = "\033[0;1;38;5;174m";
  }

  perror_stream &perror_stream::operator()(){
    start_header() << std::strerror(errno) << ramrod::log_format;
    return *this;
  }

  perror_stream &perror_stream::operator()(const std::string &text){
    start_header() << text << ": " << std::strerror(errno) << ramrod::log_format;
    return *this;
  }

  perror_stream &perror_stream::operator()(const char *text){
    start_header() << text << ": " << std::strerror(errno) << ramrod::log_format;
    return *this;
  }

  perror_stream &perror_stream::operator()(const bool boolean){
    start_header() << boolean << ": " << std::strerror(errno) << ramrod::log_format;
    return *this;
  }

  perror_stream &perror_stream::operator()(const char character){
    start_header() << character << ": " << std::strerror(errno) << ramrod::log_format;
    return *this;
  }

  perror_stream &perror_stream::operator()(const unsigned char character){
    start_header() << character << ": " << std::strerror(errno) << ramrod::log_format;
    return *this;
  }

  perror_stream &perror_stream::operator()(const signed char character){
    start_header() << character << ": " << std::strerror(errno) << ramrod::log_format;
    return *this;
  }

  perror_stream &perror_stream::operator()(const int integer_number){
    start_header() << integer_number << ": " << std::strerror(errno) << ramrod::log_format;
    return *this;
  }

  perror_stream &perror_stream::operator()(const unsigned int unsigend_integer_number){
    start_header() << unsigend_integer_number << ": " << std::strerror(errno) << ramrod::log_format;
    return *this;
  }

  perror_stream &perror_stream::operator()(const short short_integer_number){
    start_header() << short_integer_number << ": " << std::strerror(errno) << ramrod::log_format;
    return *this;
  }

  perror_stream &perror_stream::operator()(const unsigned short unsigned_short_integer_number){
    start_header() << unsigned_short_integer_number << ": " << std::strerror(errno)
                   << ramrod::log_format;
    return *this;
  }

  perror_stream &perror_stream::operator()(const long long_integer_number){
    start_header() << long_integer_number << ": " << std::strerror(errno) << ramrod::log_format;
    return *this;
  }

  perror_stream &perror_stream::operator()(const unsigned long unsigned_long_integer_number){
    start_header() << unsigned_long_integer_number << ": " << std::strerror(errno)
                   << ramrod::log_format;
    return *this;
  }

  perror_stream &perror_stream::operator()(const float float_number){
    start_header() << float_number << ": " << std::strerror(errno) << ramrod::log_format;
    return *this;
  }

  perror_stream &perror_stream::operator()(const double double_number){
    start_header() << double_number << ": " << std::strerror(errno) << ramrod::log_format;
    return *this;
  }

  perror_stream &perror_stream::operator()(const long double long_double_number){
    start_header() << long_double_number << ": " << std::strerror(errno) << ramrod::log_format;
    return *this;
  }
} // namespace ramrod
