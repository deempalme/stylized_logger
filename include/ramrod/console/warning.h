#ifndef RAMROD_CONSOLE_WARNING_H
#define RAMROD_CONSOLE_WARNING_H

#include <string>

namespace ramrod {
  namespace console {
    class endl_stream;

    class warning_stream
    {
    public:
      warning_stream();

      warning_stream &change_message(const std::string &new_message = " Warning: ");

      warning_stream &operator()();
      warning_stream &operator()(const std::string &text);
      warning_stream &operator()(const char *text);
      warning_stream &operator()(const bool boolean);
      warning_stream &operator()(const char character);
      warning_stream &operator()(const unsigned char character);
      warning_stream &operator()(const signed char character);
      warning_stream &operator()(const int integer_number);
      warning_stream &operator()(const unsigned int unsigend_integer_number);
      warning_stream &operator()(const short int short_integer_number);
      warning_stream &operator()(const unsigned short int unsigned_short_integer_number);
      warning_stream &operator()(const long int long_integer_number);
      warning_stream &operator()(const unsigned long int unsigned_long_integer_number);
      warning_stream &operator()(const float float_number);
      warning_stream &operator()(const double double_number);
      warning_stream &operator()(const long double long_double_number);

      warning_stream &operator<<(const std::string &text);
      warning_stream &operator<<(const char *text);
      warning_stream &operator<<(const bool boolean);
      warning_stream &operator<<(const char character);
      warning_stream &operator<<(const unsigned char character);
      warning_stream &operator<<(const signed char character);
      warning_stream &operator<<(const int integer_number);
      warning_stream &operator<<(const unsigned int unsigend_integer_number);
      warning_stream &operator<<(const short int short_integer_number);
      warning_stream &operator<<(const unsigned short int unsigned_short_integer_number);
      warning_stream &operator<<(const long int long_integer_number);
      warning_stream &operator<<(const unsigned long int unsigned_long_integer_number);
      warning_stream &operator<<(const float float_number);
      warning_stream &operator<<(const double double_number);
      warning_stream &operator<<(const long double long_double_number);

      warning_stream &operator<<(const endl_stream &/*endls*/);

    private:
      std::string message_;
      std::string format_;
    };

    inline warning_stream warning;
  }
}

namespace rr = ramrod::console;

#endif // RAMROD_CONSOLE_WARNING_H
