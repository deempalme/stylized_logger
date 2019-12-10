#ifndef RAMROD_CONSOLE_ERROR_H
#define RAMROD_CONSOLE_ERROR_H

#include <string>

namespace ramrod {
  namespace console {
    class error
    {
    public:
      error();

      error &change_message(const std::string &new_message = " Error: ");

      error &operator()(const std::string &text);
      error &operator()(const char *text);
      error &operator()(const bool boolean);
      error &operator()(const char character);
      error &operator()(const unsigned char character);
      error &operator()(const signed char character);
      error &operator()(const int integer_number);
      error &operator()(const unsigned int unsigend_integer_number);
      error &operator()(const short int short_integer_number);
      error &operator()(const unsigned short int unsigned_short_integer_number);
      error &operator()(const long int long_integer_number);
      error &operator()(const unsigned long int unsigned_long_integer_number);
      error &operator()(const float float_number);
      error &operator()(const double double_number);
      error &operator()(const long double long_double_number);

      error &operator<<(const std::string &text);
      error &operator<<(const char *text);
      error &operator<<(const bool boolean);
      error &operator<<(const char character);
      error &operator<<(const unsigned char character);
      error &operator<<(const signed char character);
      error &operator<<(const int integer_number);
      error &operator<<(const unsigned int unsigend_integer_number);
      error &operator<<(const short int short_integer_number);
      error &operator<<(const unsigned short int unsigned_short_integer_number);
      error &operator<<(const long int long_integer_number);
      error &operator<<(const unsigned long int unsigned_long_integer_number);
      error &operator<<(const float float_number);
      error &operator<<(const double double_number);
      error &operator<<(const long double long_double_number);

    private:
      std::string message_;
    };

    class format;
  }
  extern console::error error;
  extern console::format format;
}

namespace rr = ramrod;

#endif // RAMROD_CONSOLE_ERROR_H
