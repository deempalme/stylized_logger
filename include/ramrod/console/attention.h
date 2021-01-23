#ifndef RAMROD_CONSOLE_ATTENTION_H
#define RAMROD_CONSOLE_ATTENTION_H

#include <string>

namespace ramrod {
  namespace console {
    class endl_stream;

    class attention_stream
    {
    public:
      attention_stream();

      attention_stream &change_message(const std::string &new_message = " Attention: ");

      attention_stream &operator()();
      attention_stream &operator()(const std::string &text);
      attention_stream &operator()(const char *text);
      attention_stream &operator()(const bool boolean);
      attention_stream &operator()(const char character);
      attention_stream &operator()(const unsigned char character);
      attention_stream &operator()(const signed char character);
      attention_stream &operator()(const int integer_number);
      attention_stream &operator()(const unsigned int unsigend_integer_number);
      attention_stream &operator()(const short int short_integer_number);
      attention_stream &operator()(const unsigned short int unsigned_short_integer_number);
      attention_stream &operator()(const long int long_integer_number);
      attention_stream &operator()(const unsigned long int unsigned_long_integer_number);
      attention_stream &operator()(const float float_number);
      attention_stream &operator()(const double double_number);
      attention_stream &operator()(const long double long_double_number);

      attention_stream &operator<<(const std::string &text);
      attention_stream &operator<<(const char *text);
      attention_stream &operator<<(const bool boolean);
      attention_stream &operator<<(const char character);
      attention_stream &operator<<(const unsigned char character);
      attention_stream &operator<<(const signed char character);
      attention_stream &operator<<(const int integer_number);
      attention_stream &operator<<(const unsigned int unsigend_integer_number);
      attention_stream &operator<<(const short int short_integer_number);
      attention_stream &operator<<(const unsigned short int unsigned_short_integer_number);
      attention_stream &operator<<(const long int long_integer_number);
      attention_stream &operator<<(const unsigned long int unsigned_long_integer_number);
      attention_stream &operator<<(const float float_number);
      attention_stream &operator<<(const double double_number);
      attention_stream &operator<<(const long double long_double_number);

      attention_stream &operator<<(const endl_stream &/*endls*/);

    private:
      std::string message_;
      std::string format_;
    };

    inline attention_stream attention;
  }
}

namespace rr = ramrod::console;

#endif // RAMROD_CONSOLE_ATTENTION_H
