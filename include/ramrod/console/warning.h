#ifndef RAMROD_CONSOLE_WARNING_H
#define RAMROD_CONSOLE_WARNING_H

#include <string>

namespace ramrod {
  namespace console {
    class warning
    {
    public:
      warning();

      warning &change_message(const std::string &new_message = " Warning: ");

      warning &operator()(const std::string &text);
      warning &operator()(const char *text);
      warning &operator()(const bool boolean);
      warning &operator()(const char character);
      warning &operator()(const unsigned char character);
      warning &operator()(const signed char character);
      warning &operator()(const int integer_number);
      warning &operator()(const unsigned int unsigend_integer_number);
      warning &operator()(const short int short_integer_number);
      warning &operator()(const unsigned short int unsigned_short_integer_number);
      warning &operator()(const long int long_integer_number);
      warning &operator()(const unsigned long int unsigned_long_integer_number);
      warning &operator()(const float float_number);
      warning &operator()(const double double_number);
      warning &operator()(const long double long_double_number);

      warning &operator<<(const std::string &text);
      warning &operator<<(const char *text);
      warning &operator<<(const bool boolean);
      warning &operator<<(const char character);
      warning &operator<<(const unsigned char character);
      warning &operator<<(const signed char character);
      warning &operator<<(const int integer_number);
      warning &operator<<(const unsigned int unsigend_integer_number);
      warning &operator<<(const short int short_integer_number);
      warning &operator<<(const unsigned short int unsigned_short_integer_number);
      warning &operator<<(const long int long_integer_number);
      warning &operator<<(const unsigned long int unsigned_long_integer_number);
      warning &operator<<(const float float_number);
      warning &operator<<(const double double_number);
      warning &operator<<(const long double long_double_number);

    private:
      std::string message_;
    };

    class format;
  }
  extern console::warning warning;
  extern console::format format;
}

namespace rr = ramrod;

#endif // RAMROD_CONSOLE_WARNING_H
