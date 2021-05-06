#ifndef RAMROD_CONSOLE_PERROR_H
#define RAMROD_CONSOLE_PERROR_H

#include <string>

namespace ramrod {
  namespace console {
    class endl_stream;

    class perror_stream
    {
    public:
      perror_stream();

      perror_stream &change_message(const std::string &new_message = " Error: ");

      perror_stream &operator()();
      perror_stream &operator()(const std::string &text);
      perror_stream &operator()(const char *text);
      perror_stream &operator()(const bool boolean);
      perror_stream &operator()(const char character);
      perror_stream &operator()(const unsigned char character);
      perror_stream &operator()(const signed char character);
      perror_stream &operator()(const int integer_number);
      perror_stream &operator()(const unsigned int unsigend_integer_number);
      perror_stream &operator()(const short int short_integer_number);
      perror_stream &operator()(const unsigned short int unsigned_short_integer_number);
      perror_stream &operator()(const long int long_integer_number);
      perror_stream &operator()(const unsigned long int unsigned_long_integer_number);
      perror_stream &operator()(const float float_number);
      perror_stream &operator()(const double double_number);
      perror_stream &operator()(const long double long_double_number);

      perror_stream &operator<<(const std::string &text);
      perror_stream &operator<<(const char *text);
      perror_stream &operator<<(const bool boolean);
      perror_stream &operator<<(const char character);
      perror_stream &operator<<(const unsigned char character);
      perror_stream &operator<<(const signed char character);
      perror_stream &operator<<(const int integer_number);
      perror_stream &operator<<(const unsigned int unsigend_integer_number);
      perror_stream &operator<<(const short int short_integer_number);
      perror_stream &operator<<(const unsigned short int unsigned_short_integer_number);
      perror_stream &operator<<(const long int long_integer_number);
      perror_stream &operator<<(const unsigned long int unsigned_long_integer_number);
      perror_stream &operator<<(const float float_number);
      perror_stream &operator<<(const double double_number);
      perror_stream &operator<<(const long double long_double_number);

      perror_stream &operator<<(const endl_stream &/*endls*/);

    private:
      std::string message_;
      std::string format_;
    };

    inline perror_stream perror;
  }
}

namespace rr = ramrod::console;

#endif // RAMROD_CONSOLE_PERROR_H
