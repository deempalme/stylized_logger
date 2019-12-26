#ifndef RAMROD_CONSOLE_REGULAR_H
#define RAMROD_CONSOLE_REGULAR_H

#include <string>

namespace ramrod {
  namespace console {
    class regular
    {
    public:
      regular();

      regular &change_message(const std::string &new_message = "");

      regular &operator()(const std::string &text);
      regular &operator()(const char *text);
      regular &operator()(const bool boolean);
      regular &operator()(const char character);
      regular &operator()(const unsigned char character);
      regular &operator()(const signed char character);
      regular &operator()(const int integer_number);
      regular &operator()(const unsigned int unsigend_integer_number);
      regular &operator()(const short int short_integer_number);
      regular &operator()(const unsigned short int unsigned_short_integer_number);
      regular &operator()(const long int long_integer_number);
      regular &operator()(const unsigned long int unsigned_long_integer_number);
      regular &operator()(const float float_number);
      regular &operator()(const double double_number);
      regular &operator()(const long double long_double_number);

      regular &operator<<(const std::string &text);
      regular &operator<<(const char *text);
      regular &operator<<(const bool boolean);
      regular &operator<<(const char character);
      regular &operator<<(const unsigned char character);
      regular &operator<<(const signed char character);
      regular &operator<<(const int integer_number);
      regular &operator<<(const unsigned int unsigend_integer_number);
      regular &operator<<(const short int short_integer_number);
      regular &operator<<(const unsigned short int unsigned_short_integer_number);
      regular &operator<<(const long int long_integer_number);
      regular &operator<<(const unsigned long int unsigned_long_integer_number);
      regular &operator<<(const float float_number);
      regular &operator<<(const double double_number);
      regular &operator<<(const long double long_double_number);

    private:
      std::string message_;
    };
  }
}

#endif // RAMROD_CONSOLE_REGULAR_H
