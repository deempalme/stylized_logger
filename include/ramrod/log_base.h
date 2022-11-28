#ifndef RAMROD_LOG_BASE_H
#define RAMROD_LOG_BASE_H

#include <cstdarg>
#include <string>


namespace ramrod {
  class endl_stream;
  class log_system;

  class base_stream
  {
  public:
    /**
     * @brief Getting the ANSI format of the current object
     *
     * @return ANSI format (this will change the output color when send to iostream)
     */
    const char *color();
    const char *color() const;
    /**
     * @brief Applies the current object's ANSI format
     *
     * @return Reference to current object
     */
    base_stream &colorize();
    /**
     * @brief Resets the output original color
     *
     * @return Reference to current object
     */
    base_stream &reset();
    /**
     * @brief Outputs the current debug header
     *
     * @return Reference to current object
     */
    base_stream &operator()();
    /**
     * @brief Outputs the current debug header and an additional text
     *
     * @param text  Output's additional string value
     *
     * @return Reference to current object
     */
    base_stream &operator()(const std::string &text);
    /**
     * @brief Outputs the current debug header and an additional text
     *
     * @param text Output's additional string value
     *
     * @return Reference to current object
     */
    base_stream &operator()(const char *text);
    /**
     * @brief Outputs the current debug header and an additional boolean
     *
     * @param boolean Output's additional boolean value
     *
     * @return Reference to current object
     */
    base_stream &operator()(const bool boolean);
    /**
     * @brief Outputs the current debug header and an additional character
     *
     * @param character Output's additional character value
     *
     * @return Reference to current object
     */
    base_stream &operator()(const char character);
    /**
     * @brief Outputs the current debug header and an additional character
     *
     * @param character Output's additional character value
     *
     * @return Reference to current object
     */
    base_stream &operator()(const unsigned char character);
    /**
     * @brief Outputs the current debug header and an additional character
     *
     * @param character Output's additional character value
     *
     * @return Reference to current object
     */
    base_stream &operator()(const signed char character);
    /**
     * @brief Outputs the current debug header and an additional integer number
     *
     * @param integer_number Output's additional integer number value
     *
     * @return Reference to current object
     */
    base_stream &operator()(const int integer_number);
    /**
     * @brief Outputs the current debug header and an additional unsigend integer number
     *
     * @param unsigend_integer_number Output's additional unsigend integer value
     *
     * @return Reference to current object
     */
    base_stream &operator()(const unsigned int unsigend_integer_number);
    /**
     * @brief Outputs the current debug header and an additional short integer number
     *
     * @param short_integer_number Output's additional short integer value
     *
     * @return Reference to current object
     */
    base_stream &operator()(const short int short_integer_number);
    /**
     * @brief Outputs the current debug header and an additional unsigned short integer number
     *
     * @param unsigned_short_integer_number Output's additional unsigned short integer value
     *
     * @return Reference to current object
     */
    base_stream &operator()(const unsigned short int unsigned_short_integer_number);
    /**
     * @brief Outputs the current debug header and an additional long integer number
     *
     * @param long_integer_number Output's additional long integer value
     *
     * @return Reference to current object
     */
    base_stream &operator()(const long int long_integer_number);
    /**
     * @brief Outputs the current debug header and an additional unsigned long integer number
     *
     * @param unsigned_long_integer_number Output's additional unsigned long integer value
     *
     * @return Reference to current object
     */
    base_stream &operator()(const unsigned long int unsigned_long_integer_number);
    /**
     * @brief Outputs the current debug header and an additional float number
     *
     * @param float_number Output's additional float value
     *
     * @return Reference to current object
     */
    base_stream &operator()(const float float_number);
    /**
     * @brief Outputs the current debug header and an additional double number
     *
     * @param double_number Output's additional double value
     *
     * @return Reference to current object
     */
    base_stream &operator()(const double double_number);
    /**
     * @brief Outputs the current debug header and an additional long double number
     *
     * @param long_double_number Output's additional long double value
     *
     * @return Reference to current object
     */
    base_stream &operator()(const long double long_double_number);
    /**
     * @brief Outputs text
     *
     * @param text  Output's string value
     *
     * @return Reference to current object
     */
    base_stream &operator<<(const std::string &text);
    /**
     * @brief Outputs text
     *
     * @param text Output's string value
     *
     * @return Reference to current object
     */
    base_stream &operator<<(const char *text);
    /**
     * @brief Outputs a boolean
     *
     * @param boolean Output's boolean value
     *
     * @return Reference to current object
     */
    base_stream &operator<<(const bool boolean);
    /**
     * @brief Outputs a character
     *
     * @param character Output's character value
     *
     * @return Reference to current object
     */
    base_stream &operator<<(const char character);
    /**
     * @brief Outputs a character
     *
     * @param character Output's character value
     *
     * @return Reference to current object
     */
    base_stream &operator<<(const unsigned char character);
    /**
     * @brief Outputs a character
     *
     * @param character Output's character value
     *
     * @return Reference to current object
     */
    base_stream &operator<<(const signed char character);
    /**
     * @brief Outputs a integer number
     *
     * @param integer_number Output's integer number value
     *
     * @return Reference to current object
     */
    base_stream &operator<<(const int integer_number);
    /**
     * @brief Outputs a unsigend integer number
     *
     * @param unsigend_integer_number Output's unsigend integer value
     *
     * @return Reference to current object
     */
    base_stream &operator<<(const unsigned int unsigend_integer_number);
    /**
     * @brief Outputs a short integer number
     *
     * @param short_integer_number Output's short integer value
     *
     * @return Reference to current object
     */
    base_stream &operator<<(const short int short_integer_number);
    /**
     * @brief Outputs a unsigned short integer number
     *
     * @param unsigned_short_integer_number Output's unsigned short integer value
     *
     * @return Reference to current object
     */
    base_stream &operator<<(const unsigned short int unsigned_short_integer_number);
    /**
     * @brief Outputs a long integer number
     *
     * @param long_integer_number Output's long integer value
     *
     * @return Reference to current object
     */
    base_stream &operator<<(const long int long_integer_number);
    /**
     * @brief Outputs a unsigned long integer number
     *
     * @param unsigned_long_integer_number Output's unsigned long integer value
     *
     * @return Reference to current object
     */
    base_stream &operator<<(const unsigned long int unsigned_long_integer_number);
    /**
     * @brief Outputs a float number
     *
     * @param float_number Output's float value
     *
     * @return Reference to current object
     */
    base_stream &operator<<(const float float_number);
    /**
     * @brief Outputs a double number
     *
     * @param double_number Output's double value
     *
     * @return Reference to current object
     */
    base_stream &operator<<(const double double_number);
    /**
     * @brief Outputs a long double number
     *
     * @param long_double_number Output's long double value
     *
     * @return Reference to current object
     */
    base_stream &operator<<(const long double long_double_number);
    /**
     * @brief Adds a new line to the ouput
     *
     * @return Reference to current object
     */
    base_stream &operator<<(const endl_stream &endls);
    /**
     * @brief Displaying messages in Terminal/Console with std::printf style format
     *
     * This function displays messages into the Ubuntu Terminal or Window's console. They
     * are colored depending on its type:
     *   - error: red
     *   - warning: yellow
     *   - attention: blue
     *   - message: green
     *
     * It works similar to `std::printf`; `const char *format` should contain how to interpret
     * the data, look at [https://en.cppreference.com/w/cpp/io/c/fprintf]
     * (https://en.cppreference.com/w/cpp/io/c/fprintf) to see all possible formats.
     *
     * @param format  Pointer to a null-terminated multibyte string specifying how
     *                to interpret the data.
     * @param ...     Variable argument list (multiple variables, multiple types)
     *
     * @return Number of characters written if successful or negative value if an error occurred.
     */
    int printf(const char *format, ...) __attribute__((format (printf, 2, 3)));

  protected:
    log_system &start();
    log_system &start_header();

    const char *_ansi_format = "";
  };
} // namespace ramrod

namespace rr = ramrod;

#endif // RAMROD_LOG_BASE_H
