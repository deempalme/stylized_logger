#ifndef RAMROD_LOG_OSTREAM_H
#define RAMROD_LOG_OSTREAM_H

#include <filesystem>
#include <fstream>
#include <string>

#include "ramrod/log_types.h"


namespace ramrod {
  class base_stream;
  class clean_stream;
  class endl_stream;
  class flush_stream;
  class format_stream;

  class base_ostream : public log_types
  {
  public:
    base_ostream();
    /**
     * @brief Changing the current logging header
     *
     * The header is usually printed at the beginning of each new line and in most cases
     * contains the timestamp, the default header is as follows:
     *
     *    "%Y-%m-%d %H:%M:%S %Z -> "
     *
     * Which should result in this:
     *
     *    "2022-01-12 16:45:56 PST -> "
     *
     * The header is ONLY printed when calling the "operator()" and not when "<<" is used
     *
     * @param new_format  Character string specifying the format of conversion (see std::strftime
     *                    format: https://en.cppreference.com/w/cpp/chrono/c/strftime for
     *                    more information about the specifiers), NOTE: an empty new_format
     *                    will discard the header
     *
     * @return `false` if format used in new_format is incorrect or cannot be translated
     */
    bool header(const std::string &new_format);
    /**
     * @brief Getting the current logging header's format
     *
     * @return Current logging header's format (see https://en.cppreference.com/w/cpp/chrono/c/strftime
     *         for more information about the specifiers)
     */
    const std::string &header();
    /**
     * @brief Changing the logging level
     *
     * There are four logging levels and indicate where is the data going to be shown or stored,
     * you may choose between:
     *    1. ignore          = Does not print in terminal nor stores into file
     *    2. print           = Only prints in terminal
     *    3. store           = Only stores into file
     *    4. print_and_store = Prints in terminal and also stores into file
     *
     * @param new_level  New logging level
     */
    void level(const log_types::level new_level);
    /**
     * @brief Getting the current logging level
     *
     * @return Current log level
     */
    log_types::level level();
    /**
     * @brief Changing the log's output file
     *
     * @param folder_path  Path to container folder
     * @param filename     Name of the file that may include the format of conversion (see
     *                     std::strftime format: https://en.cppreference.com/w/cpp/chrono/c/strftime
     *                     for more information about the specifiers)
     *
     * @return `false` if folder's path does not exist or if there is an error while converting
     *         format used inside filename
     */
    bool output_file(const std::filesystem::path &folder_path,
                     const std::string &filename = "log_%Y-%m-%d_%H:%M:%S.txt");
    /**
     * @brief Getting the current file's path where the log is saved
     *
     * @return Full file's path, or empty if parent folder's path does not exist, or no filename
     *         if format used in filename is incorrect
     */
    const std::filesystem::path &output_file();
    /**
     * @brief Outputs the header
     *
     * @return Reference to current object
     */
    base_ostream &operator()();
    /**
     * @brief Outputs the header and an additional text
     *
     * @param text  Output's additional string value
     *
     * @return Reference to current object
     */
    base_ostream &operator()(const std::string &text);
    /**
     * @brief Outputs the header and an additional text
     *
     * @param text Output's additional string value
     *
     * @return Reference to current object
     */
    base_ostream &operator()(const char *text);
    /**
     * @brief Outputs the header and an additional boolean
     *
     * @param boolean Output's additional boolean value
     *
     * @return Reference to current object
     */
    base_ostream &operator()(const bool boolean);
    /**
     * @brief Outputs the header and an additional character
     *
     * @param character Output's additional character value
     *
     * @return Reference to current object
     */
    base_ostream &operator()(const char character);
    /**
     * @brief Outputs the header and an additional character
     *
     * @param character Output's additional character value
     *
     * @return Reference to current object
     */
    base_ostream &operator()(const unsigned char character);
    /**
     * @brief Outputs the header and an additional character
     *
     * @param character Output's additional character value
     *
     * @return Reference to current object
     */
    base_ostream &operator()(const signed char character);
    /**
     * @brief Outputs the header and an additional integer number
     *
     * @param integer_number Output's additional integer number value
     *
     * @return Reference to current object
     */
    base_ostream &operator()(const int integer_number);
    /**
     * @brief Outputs the header and an additional unsigend integer number
     *
     * @param unsigend_integer_number Output's additional unsigend integer value
     *
     * @return Reference to current object
     */
    base_ostream &operator()(const unsigned int unsigend_integer_number);
    /**
     * @brief Outputs the header and an additional short integer number
     *
     * @param short_integer_number Output's additional short integer value
     *
     * @return Reference to current object
     */
    base_ostream &operator()(const short int short_integer_number);
    /**
     * @brief Outputs the header and an additional unsigned short integer number
     *
     * @param unsigned_short_integer_number Output's additional unsigned short integer value
     *
     * @return Reference to current object
     */
    base_ostream &operator()(const unsigned short int unsigned_short_integer_number);
    /**
     * @brief Outputs the header and an additional long integer number
     *
     * @param long_integer_number Output's additional long integer value
     *
     * @return Reference to current object
     */
    base_ostream &operator()(const long int long_integer_number);
    /**
     * @brief Outputs the header and an additional unsigned long integer number
     *
     * @param unsigned_long_integer_number Output's additional unsigned long integer value
     *
     * @return Reference to current object
     */
    base_ostream &operator()(const unsigned long int unsigned_long_integer_number);
    /**
     * @brief Outputs the header and an additional float number
     *
     * @param float_number Output's additional float value
     *
     * @return Reference to current object
     */
    base_ostream &operator()(const float float_number);
    /**
     * @brief Outputs the header and an additional double number
     *
     * @param double_number Output's additional double value
     *
     * @return Reference to current object
     */
    base_ostream &operator()(const double double_number);
    /**
     * @brief Outputs the header and an additional long double number
     *
     * @param long_double_number Output's additional long double value
     *
     * @return Reference to current object
     */
    base_ostream &operator()(const long double long_double_number);
    /**
     * @brief Outputs text
     *
     * @param text  Output's string value
     *
     * @return Reference to current object
     */
    base_ostream &operator<<(const std::string &text);
    /**
     * @brief Outputs text
     *
     * @param text Output's string value
     *
     * @return Reference to current object
     */
    base_ostream &operator<<(const char *text);
    /**
     * @brief Outputs a boolean
     *
     * @param boolean Output's boolean value
     *
     * @return Reference to current object
     */
    base_ostream &operator<<(const bool boolean);
    /**
     * @brief Outputs a character
     *
     * @param character Output's character value
     *
     * @return Reference to current object
     */
    base_ostream &operator<<(const char character);
    /**
     * @brief Outputs a character
     *
     * @param character Output's character value
     *
     * @return Reference to current object
     */
    base_ostream &operator<<(const unsigned char character);
    /**
     * @brief Outputs a character
     *
     * @param character Output's character value
     *
     * @return Reference to current object
     */
    base_ostream &operator<<(const signed char character);
    /**
     * @brief Outputs a integer number
     *
     * @param integer_number Output's integer number value
     *
     * @return Reference to current object
     */
    base_ostream &operator<<(const int integer_number);
    /**
     * @brief Outputs a unsigend integer number
     *
     * @param unsigend_integer_number Output's unsigend integer value
     *
     * @return Reference to current object
     */
    base_ostream &operator<<(const unsigned int unsigend_integer_number);
    /**
     * @brief Outputs a short integer number
     *
     * @param short_integer_number Output's short integer value
     *
     * @return Reference to current object
     */
    base_ostream &operator<<(const short int short_integer_number);
    /**
     * @brief Outputs a unsigned short integer number
     *
     * @param unsigned_short_integer_number Output's unsigned short integer value
     *
     * @return Reference to current object
     */
    base_ostream &operator<<(const unsigned short int unsigned_short_integer_number);
    /**
     * @brief Outputs a long integer number
     *
     * @param long_integer_number Output's long integer value
     *
     * @return Reference to current object
     */
    base_ostream &operator<<(const long int long_integer_number);
    /**
     * @brief Outputs a unsigned long integer number
     *
     * @param unsigned_long_integer_number Output's unsigned long integer value
     *
     * @return Reference to current object
     */
    base_ostream &operator<<(const unsigned long int unsigned_long_integer_number);
    /**
     * @brief Outputs a float number
     *
     * @param float_number Output's float value
     *
     * @return Reference to current object
     */
    base_ostream &operator<<(const float float_number);
    /**
     * @brief Outputs a double number
     *
     * @param double_number Output's double value
     *
     * @return Reference to current object
     */
    base_ostream &operator<<(const double double_number);
    /**
     * @brief Outputs a long double number
     *
     * @param long_double_number Output's long double value
     *
     * @return Reference to current object
     */
    base_ostream &operator<<(const long double long_double_number);
    /**
     * @brief Outputs the header in the same color as base
     *
     * @param base base_stream object
     *
     * @return Reference to current object
     */
    base_ostream &operator<<(const base_stream &base);
    /**
     * @brief Cleans the output
     *
     * It will also delete all contents of the file where the debug is being written, you may
     * call it as follows:
     *
     *    // Using short way
     *    rr::log << rr::clean
     *
     * @param cleaner  clean_stream object
     *
     * @return Reference to current object
     */
    base_ostream &operator<<(const clean_stream &cleaner);
    /**
     * @brief Adds a new line to the ouput
     *
     * You may call it as follows:
     *
     *    // Using short way
     *    rr::log << rr::endl
     *
     * @return Reference to current object
     */
    base_ostream &operator<<(const endl_stream &);
    /**
     * @brief Flushes the ouput
     *
     * @return Reference to current object
     */
    base_ostream &operator<<(const flush_stream &);
    /**
     * @brief Applies color to output
     *
     * @param formatter  format_stream object
     *
     * @return Reference to current object
     */
    base_ostream &operator<<(const format_stream &formatter);

  private:
    void close();
    char *get_header();
    bool name_file(const std::string &filename);
    bool open(const bool truncate = false);

    bool initialized_;
    std::ofstream file_;
    std::filesystem::path file_path_;

    log_types::level level_;
    bool print_, store_;
    std::string format_;
    std::string header_;
    std::size_t header_size_;
  };
} // namespace ramrod

namespace rr = ramrod;

#endif // RAMROD_LOG_OSTREAM_H
