#ifndef RAMROD_CONSOLE_ERROR_H
#define RAMROD_CONSOLE_ERROR_H

#include <string>

namespace ramrod {
  namespace console {
    class endl_stream;

    class error_stream
    {
    public:
      error_stream();

      error_stream &change_message(const std::string &new_message = " Error: ");

      error_stream &operator()();
      error_stream &operator()(const std::string &text);
      error_stream &operator()(const char *text);
      error_stream &operator()(const bool boolean);
      error_stream &operator()(const char character);
      error_stream &operator()(const unsigned char character);
      error_stream &operator()(const signed char character);
      error_stream &operator()(const int integer_number);
      error_stream &operator()(const unsigned int unsigend_integer_number);
      error_stream &operator()(const short int short_integer_number);
      error_stream &operator()(const unsigned short int unsigned_short_integer_number);
      error_stream &operator()(const long int long_integer_number);
      error_stream &operator()(const unsigned long int unsigned_long_integer_number);
      error_stream &operator()(const float float_number);
      error_stream &operator()(const double double_number);
      error_stream &operator()(const long double long_double_number);

      error_stream &operator<<(const std::string &text);
      error_stream &operator<<(const char *text);
      error_stream &operator<<(const bool boolean);
      error_stream &operator<<(const char character);
      error_stream &operator<<(const unsigned char character);
      error_stream &operator<<(const signed char character);
      error_stream &operator<<(const int integer_number);
      error_stream &operator<<(const unsigned int unsigend_integer_number);
      error_stream &operator<<(const short int short_integer_number);
      error_stream &operator<<(const unsigned short int unsigned_short_integer_number);
      error_stream &operator<<(const long int long_integer_number);
      error_stream &operator<<(const unsigned long int unsigned_long_integer_number);
      error_stream &operator<<(const float float_number);
      error_stream &operator<<(const double double_number);
      error_stream &operator<<(const long double long_double_number);

      error_stream &operator<<(const endl_stream &/*endls*/);

    private:
      std::string message_;
      std::string format_;
    };

    inline error_stream error;
  }
}

namespace rr = ramrod::console;

#endif // RAMROD_CONSOLE_ERROR_H
