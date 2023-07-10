#include "ramrod/log.h"

#include <iostream>


namespace ramrod {
  endl_stream &endl_stream::operator ()(){
    ramrod::log << *this;
    return *this;
  }

  std::ostream &operator<<(std::ostream &output, endl_stream &) {
    output << std::endl;
    return output;
  }

  flush_stream &flush_stream::operator ()(){
    ramrod::log << *this;
    return *this;
  }

  std::ostream &operator<<(std::ostream &output, flush_stream &) {
    output << std::flush;
    return output;
  }

  const char *clean_stream::ansi(){
    return "\033[2J\033[H\033[3J";
  }

  const char *clean_stream::ansi() const{
    return "\033[2J\033[H\033[3J";
  }

  clean_stream &clean_stream::operator()(){
    ramrod::log << *this;
    return *this;
  }

  log_system &clean_stream::operator<<(log_system &output){
    output << *this;
    return output;
  }

  std::ostream &operator<<(std::ostream &output, clean_stream &) {
    output << "\033[2J\033[H\033[3J";
    return output;
  }
} // namespace ramrod
