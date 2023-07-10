#ifndef RAMROD_LOG_PERROR_H
#define RAMROD_LOG_PERROR_H

#include <string>

#include "ramrod/log_base.h"


namespace ramrod {
  class perror_stream : public base_stream
  {
  public:
    perror_stream();
    /**
     * @brief Outputs the current debug header and latest error string
     *
     * @return Reference to current object
     */
    perror_stream &operator()();
    /**
     * @brief Outputs the current debug header, latest error string, and an additional text
     *
     * @param text  Output's additional string value
     *
     * @return Reference to current object
     */
    perror_stream &operator()(const std::string &text);
    /**
     * @brief Outputs the current debug header, latest error string, and an additional text
     *
     * @param text Output's additional string value
     *
     * @return Reference to current object
     */
    perror_stream &operator()(const char *text);
    /**
     * @brief Outputs the current debug header, latest error string, and an additional boolean
     *
     * @param boolean Output's additional boolean value
     *
     * @return Reference to current object
     */
    perror_stream &operator()(const bool boolean);
    /**
     * @brief Outputs the current debug header, latest error string, and an additional character
     *
     * @param character Output's additional character value
     *
     * @return Reference to current object
     */
    perror_stream &operator()(const char character);
    /**
     * @brief Outputs the current debug header, latest error string, and an additional character
     *
     * @param character Output's additional character value
     *
     * @return Reference to current object
     */
    perror_stream &operator()(const unsigned char character);
    /**
     * @brief Outputs the current debug header, latest error string, and an additional character
     *
     * @param character Output's additional character value
     *
     * @return Reference to current object
     */
    perror_stream &operator()(const signed char character);
    /**
     * @brief Outputs the current debug header, latest error string,
     *        and an additional integer number
     *
     * @param integer_number Output's additional integer number value
     *
     * @return Reference to current object
     */
    perror_stream &operator()(const int integer_number);
    /**
     * @brief Outputs the current debug header, latest error string, and an
     *        additional unsigend integer number
     *
     * @param unsigend_integer_number Output's additional unsigend integer value
     *
     * @return Reference to current object
     */
    perror_stream &operator()(const unsigned int unsigend_integer_number);
    /**
     * @brief Outputs the current debug header, latest error string, and an
     *        additional short integer number
     *
     * @param short_integer_number Output's additional short integer value
     *
     * @return Reference to current object
     */
    perror_stream &operator()(const short int short_integer_number);
    /**
     * @brief Outputs the current debug header, latest error string, and an
     *        additional unsigned short integer number
     *
     * @param unsigned_short_integer_number Output's additional unsigned short integer value
     *
     * @return Reference to current object
     */
    perror_stream &operator()(const unsigned short int unsigned_short_integer_number);
    /**
     * @brief Outputs the current debug header, latest error string, and an
     *        additional long integer number
     *
     * @param long_integer_number Output's additional long integer value
     *
     * @return Reference to current object
     */
    perror_stream &operator()(const long int long_integer_number);
    /**
     * @brief Outputs the current debug header, latest error string, and an
     *        additional unsigned long integer number
     *
     * @param unsigned_long_integer_number Output's additional unsigned long integer value
     *
     * @return Reference to current object
     */
    perror_stream &operator()(const unsigned long int unsigned_long_integer_number);
    /**
     * @brief Outputs the current debug header, latest error string, and an additional float number
     *
     * @param float_number Output's additional float value
     *
     * @return Reference to current object
     */
    perror_stream &operator()(const float float_number);
    /**
     * @brief Outputs the current debug header, latest error string, and an additional double number
     *
     * @param double_number Output's additional double value
     *
     * @return Reference to current object
     */
    perror_stream &operator()(const double double_number);
    /**
     * @brief Outputs the current debug header, latest error string, and an
     *        additional long double number
     *
     * @param long_double_number Output's additional long double value
     *
     * @return Reference to current object
     */
    perror_stream &operator()(const long double double_number);
  };

  inline static perror_stream log_perror;

} // namespace ramrod

namespace rr = ramrod;

#endif // RAMROD_CONSOLE_PERROR_H
