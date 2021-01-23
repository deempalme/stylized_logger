#ifndef RAMROD_CONSOLE_REGULAR_H
#define RAMROD_CONSOLE_REGULAR_H

#include <string>

namespace ramrod {
  namespace console {
    class endl_stream;

    class regular_stream
    {
    public:
      regular_stream();

      regular_stream &change_message(const std::string &new_message = "");

      regular_stream &operator()();
      regular_stream &operator()(const std::string &text);
      regular_stream &operator()(const char *text);
      regular_stream &operator()(const bool boolean);
      regular_stream &operator()(const char character);
      regular_stream &operator()(const unsigned char character);
      regular_stream &operator()(const signed char character);
      regular_stream &operator()(const int integer_number);
      regular_stream &operator()(const unsigned int unsigend_integer_number);
      regular_stream &operator()(const short int short_integer_number);
      regular_stream &operator()(const unsigned short int unsigned_short_integer_number);
      regular_stream &operator()(const long int long_integer_number);
      regular_stream &operator()(const unsigned long int unsigned_long_integer_number);
      regular_stream &operator()(const float float_number);
      regular_stream &operator()(const double double_number);
      regular_stream &operator()(const long double long_double_number);

      regular_stream &operator<<(const std::string &text);
      regular_stream &operator<<(const char *text);
      regular_stream &operator<<(const bool boolean);
      regular_stream &operator<<(const char character);
      regular_stream &operator<<(const unsigned char character);
      regular_stream &operator<<(const signed char character);
      regular_stream &operator<<(const int integer_number);
      regular_stream &operator<<(const unsigned int unsigend_integer_number);
      regular_stream &operator<<(const short int short_integer_number);
      regular_stream &operator<<(const unsigned short int unsigned_short_integer_number);
      regular_stream &operator<<(const long int long_integer_number);
      regular_stream &operator<<(const unsigned long int unsigned_long_integer_number);
      regular_stream &operator<<(const float float_number);
      regular_stream &operator<<(const double double_number);
      regular_stream &operator<<(const long double long_double_number);

      regular_stream &operator<<(const endl_stream &/*endls*/);

    private:
      std::string message_;
      std::string format_;
    };

    inline regular_stream regular;
  }
}

namespace rr = ramrod::console;

#endif // RAMROD_CONSOLE_REGULAR_H
