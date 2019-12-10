#ifndef RAMROD_CONSOLE_ATTENTION_H
#define RAMROD_CONSOLE_ATTENTION_H

#include <string>

namespace ramrod {
  namespace console {
    class attention
    {
    public:
      attention();

      attention &change_message(const std::string &new_message = " Attention: ");

      attention &operator()(const std::string &text);
      attention &operator()(const char *text);
      attention &operator()(const bool boolean);
      attention &operator()(const char character);
      attention &operator()(const unsigned char character);
      attention &operator()(const signed char character);
      attention &operator()(const int integer_number);
      attention &operator()(const unsigned int unsigend_integer_number);
      attention &operator()(const short int short_integer_number);
      attention &operator()(const unsigned short int unsigned_short_integer_number);
      attention &operator()(const long int long_integer_number);
      attention &operator()(const unsigned long int unsigned_long_integer_number);
      attention &operator()(const float float_number);
      attention &operator()(const double double_number);
      attention &operator()(const long double long_double_number);

      attention &operator<<(const std::string &text);
      attention &operator<<(const char *text);
      attention &operator<<(const bool boolean);
      attention &operator<<(const char character);
      attention &operator<<(const unsigned char character);
      attention &operator<<(const signed char character);
      attention &operator<<(const int integer_number);
      attention &operator<<(const unsigned int unsigend_integer_number);
      attention &operator<<(const short int short_integer_number);
      attention &operator<<(const unsigned short int unsigned_short_integer_number);
      attention &operator<<(const long int long_integer_number);
      attention &operator<<(const unsigned long int unsigned_long_integer_number);
      attention &operator<<(const float float_number);
      attention &operator<<(const double double_number);
      attention &operator<<(const long double long_double_number);

    private:
      std::string message_;
    };

    class format;
  }
  extern console::attention attention;
  extern console::format format;
}

namespace rr = ramrod;

#endif // RAMROD_CONSOLE_ATTENTION_H
