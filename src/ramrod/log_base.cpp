#include "ramrod/log_base.h"

#include <vector>

#include "ramrod/log.h"
#include "ramrod/log_format.h"


namespace ramrod {
  const char *base_stream::color(){
    return _ansi_format;
  }

  const char *base_stream::color() const {
    return _ansi_format;
  }

  base_stream &base_stream::colorize(){
    ramrod::log_format << *this;
    return *this;
  }

  base_stream &base_stream::reset(){
    ramrod::log_format.reset();
    return *this;
  }

  base_stream &base_stream::operator()(){
    ramrod::log << *this;
    return *this;
  }

  base_stream &base_stream::operator()(const std::string &text){
    start_header() << text << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator()(const char *text){
    start_header() << text << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator()(const bool boolean){
    start_header() << boolean << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator()(const char character){
    start_header() << character << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator()(const unsigned char character){
    start_header() << character << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator()(const signed char character){
    start_header() << character << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator()(const int integer_number){
    start_header() << integer_number << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator()(const unsigned int unsigend_integer_number){
    start_header() << unsigend_integer_number << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator()(const short short_integer_number){
    start_header() << short_integer_number << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator()(const unsigned short unsigned_short_integer_number){
    start_header() << unsigned_short_integer_number << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator()(const long long_integer_number){
    start_header() << long_integer_number << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator()(const unsigned long unsigned_long_integer_number){
    start_header() << unsigned_long_integer_number << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator()(const float float_number){
    start_header() << float_number << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator()(const double double_number){
    start_header() << double_number << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator()(const long double long_double_number){
    start_header() << long_double_number << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator<<(const std::string &text){
    start() << text << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator<<(const char *text){
    start() << text << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator<<(const bool boolean){
    start() << boolean << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator<<(const char character){
    start() << character << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator<<(const unsigned char character){
    start() << character << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator<<(const signed char character){
    start() << character << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator<<(const int integer_number){
    start() << integer_number << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator<<(const unsigned int unsigend_integer_number){
    start() << unsigend_integer_number << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator<<(const short short_integer_number){
    start() << short_integer_number << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator<<(const unsigned short unsigned_short_integer_number){
    start() << unsigned_short_integer_number << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator<<(const long long_integer_number){
    start() << long_integer_number << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator<<(const unsigned long unsigned_long_integer_number){
    start() << unsigned_long_integer_number << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator<<(const float float_number){
    start() << float_number << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator<<(const double double_number){
    start() << double_number << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator<<(const long double long_double_number){
    start() << long_double_number << ramrod::log_format;
    return *this;
  }

  base_stream &base_stream::operator<<(const endl_stream &endls){
    ramrod::log << endls;
    return *this;
  }

  int base_stream::printf(const char *format, ...){
    va_list args1;
    va_start(args1, format);
    va_list args2;
    va_copy(args2, args1);
    std::vector<char> buffer(1 + std::vsnprintf(nullptr, 0, format, args1));
    va_end(args1);
    std::vsnprintf(buffer.data(), buffer.size(), format, args2);
    va_end(args2);
    start_header() << buffer.data() << ramrod::log_format;
    return buffer.size();
  }

  // ::::::::::::::::::::::::::::::::::::: PRIVATE FUNCTIONS :::::::::::::::::::::::::::::::::::::

  log_system &base_stream::start(){
    ramrod::log << _ansi_format;
    return ramrod::log;
  }

  log_system &base_stream::start_header(){
    ramrod::log(_ansi_format);
    return ramrod::log;
  }
} // namespace ramrod
