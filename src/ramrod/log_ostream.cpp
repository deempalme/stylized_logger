#include "ramrod/log_ostream.h"

#include <ctime>
#include <iostream>

#include "ramrod/log.h"
#include "ramrod/log_base.h"
#include "ramrod/log_format.h"


namespace ramrod {
  base_ostream::base_ostream() :
    initialized_{false},
    file_{},
    file_path_{},
    level_{log_types::level::print},
    print_{true},
    store_{false},
    format_{"%Y-%m-%d %H:%M:%S %Z -> "},
    header_(1024, '\0'),
    header_size_{1024}
  {
    header(format_);
  }

  bool base_ostream::header(const std::string &new_format){
    format_ = new_format;

    if(new_format.size() == 0){
      header_size_ = 0;
      header_.resize(0);
      return true;
    }
    const time_t now = time(nullptr);
    header_.reserve(1024);
    // TODO: add option to change localtime to gmtime?
    header_size_ = std::strftime(header_.data(), 1024, format_.c_str(), std::localtime(&now));
    header_.resize(header_size_ + 8);
    return header_size_ != 0;
  }

  const std::string &base_ostream::header(){
    return format_;
  }

  void base_ostream::level(const log_types::level new_level){
    if(level_ == new_level)
      return;

    level_ = new_level;
    print_ = level_ & log_types::level::print;

    if((store_ = level_ & log_types::level::store))
      if(!initialized_)
        output_file(std::filesystem::current_path());
  }

  log_types::level base_ostream::level(){
    return level_;
  }

  bool base_ostream::output_file(const std::filesystem::path &folder_path,
                                 const std::string &filename){
    if(!std::filesystem::exists(folder_path) || filename.size() == 0){
      file_path_.clear();
      return initialized_ = false;
    }
    file_path_ = folder_path;
    return name_file(filename);
  }

  const std::filesystem::path &base_ostream::output_file(){
    return file_path_;
  }

  base_ostream &base_ostream::operator()(){
    if(print_)
      std::cout << get_header();
    if(store_)
      if(open()){
        file_ << get_header();
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator()(const std::string &text){
    if(print_)
      std::cout << get_header() << text;
    if(store_)
      if(open()){
        file_ << get_header() << text;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator()(const char *text){
    if(print_)
      std::cout << get_header() << text;
    if(store_)
      if(open()){
        file_ << get_header() << text;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator()(const bool boolean){
    if(print_)
      std::cout << get_header() << boolean;
    if(store_)
      if(open()){
        file_ << get_header() << boolean;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator()(const char character){
    if(print_)
      std::cout << get_header() << character;
    if(store_)
      if(open()){
        file_ << get_header() << character;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator()(const unsigned char character){
    if(print_)
      std::cout << get_header() << character;
    if(store_)
      if(open()){
        file_ << get_header() << character;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator()(const signed char character){
    if(print_)
      std::cout << get_header() << character;
    if(store_)
      if(open()){
        file_ << get_header() << character;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator()(const int integer_number){
    if(print_)
      std::cout << get_header() << integer_number;
    if(store_)
      if(open()){
        file_ << get_header() << integer_number;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator()(const unsigned int unsigend_integer_number){
    if(print_)
      std::cout << get_header() << unsigend_integer_number;
    if(store_)
      if(open()){
        file_ << get_header() << unsigend_integer_number;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator()(const short short_integer_number){
    if(print_)
      std::cout << get_header() << short_integer_number;
    if(store_)
      if(open()){
        file_ << get_header() << short_integer_number;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator()(const unsigned short unsigned_short_integer_number){
    if(print_)
      std::cout << get_header() << unsigned_short_integer_number;
    if(store_)
      if(open()){
        file_ << get_header() << unsigned_short_integer_number;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator()(const long long_integer_number){
    if(print_)
      std::cout << get_header() << long_integer_number;
    if(store_)
      if(open()){
        file_ << get_header() << long_integer_number;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator()(const unsigned long unsigned_long_integer_number){
    if(print_)
      std::cout << get_header() << unsigned_long_integer_number;
    if(store_)
      if(open()){
        file_ << get_header() << unsigned_long_integer_number;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator()(const float float_number){
    if(print_)
      std::cout << get_header() << float_number;
    if(store_)
      if(open()){
        file_ << get_header() << float_number;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator()(const double double_number){
    if(print_)
      std::cout << get_header() << double_number;
    if(store_)
      if(open()){
        file_ << get_header() << double_number;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator()(const long double long_double_number){
    if(print_)
      std::cout << get_header() << long_double_number;
    if(store_)
      if(open()){
        file_ << get_header() << long_double_number;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator<<(const std::string &text){
    if(print_)
      std::cout << text;
    if(store_)
      if(open()){
        file_ << text;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator<<(const char *text){
    if(print_)
      std::cout << text;
    if(store_)
      if(open()){
        file_ << text;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator<<(const bool boolean){
    if(print_)
      std::cout << boolean;
    if(store_)
      if(open()){
        file_ << boolean;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator<<(const char character){
    if(print_)
      std::cout << character;
    if(store_)
      if(open()){
        file_ << character;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator<<(const unsigned char character){
    if(print_)
      std::cout << character;
    if(store_)
      if(open()){
        file_ << character;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator<<(const signed char character){
    if(print_)
      std::cout << character;
    if(store_)
      if(open()){
        file_ << character;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator<<(const int integer_number){
    if(print_)
      std::cout << integer_number;
    if(store_)
      if(open()){
        file_ << integer_number;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator<<(const unsigned int unsigend_integer_number){
    if(print_)
      std::cout << unsigend_integer_number;
    if(store_)
      if(open()){
        file_ << unsigend_integer_number;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator<<(const short short_integer_number){
    if(print_)
      std::cout << short_integer_number;
    if(store_)
      if(open()){
        file_ << short_integer_number;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator<<(const unsigned short unsigned_short_integer_number){
    if(print_)
      std::cout << unsigned_short_integer_number;
    if(store_)
      if(open()){
        file_ << unsigned_short_integer_number;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator<<(const long long_integer_number){
    if(print_)
      std::cout << long_integer_number;
    if(store_)
      if(open()){
        file_ << long_integer_number;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator<<(const unsigned long unsigned_long_integer_number){
    if(print_)
      std::cout << unsigned_long_integer_number;
    if(store_)
      if(open()){
        file_ << unsigned_long_integer_number;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator<<(const float float_number){
    if(print_)
      std::cout << float_number;
    if(store_)
      if(open()){
        file_ << float_number;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator<<(const double double_number){
    if(print_)
      std::cout << double_number;
    if(store_)
      if(open()){
        file_ << double_number;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator<<(const long double long_double_number){
    if(print_)
      std::cout << long_double_number;
    if(store_)
      if(open()){
        file_ << long_double_number;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator<<(const base_stream &base){
    if(print_)
      std::cout << base.color() << get_header();
    if(store_)
      if(open()){
        file_ << base.color() << get_header();
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator<<(const clean_stream &cleaner){
    if(print_)
      std::cout << cleaner.ansi();
    if(store_ && open(true))
      close();

    return *this;
  }

  base_ostream &base_ostream::operator<<(const endl_stream &){
    if(print_)
      std::cout << std::endl;
    if(store_)
      if(open()){
        file_ << std::endl;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator<<(const flush_stream &){
    if(print_)
      std::cout << std::flush;
    if(store_)
      if(open()){
        file_ << std::flush;
        close();
      }
    return *this;
  }

  base_ostream &base_ostream::operator<<(const format_stream &formatter){
    if(print_)
      std::cout << formatter.current();
    if(store_)
      if(open()){
        file_ << formatter.current();
        close();
      }
    return *this;
  }

  // ::::::::::::::::::::::::::::::::::::: PRIVATE FUNCTIONS :::::::::::::::::::::::::::::::::::::

  void base_ostream::close(){
    file_.close();
  }

  char *base_ostream::get_header(){
    if(header_size_ == 0) return header_.data();

    const time_t now = time(nullptr);
    std::strftime(header_.data(), header_size_, format_.c_str(), std::localtime(&now));
    return header_.data();
  }

  bool base_ostream::name_file(const std::string &filename){
    std::string name_container(256, '\0');
    const time_t now = time(nullptr);

    if(std::strftime(name_container.data(), 256, filename.c_str(), std::localtime(&now)) == 0)
      return initialized_ = false;

    if(file_path_.has_filename())
      file_path_.replace_filename(name_container);
    else
      file_path_ /= name_container;

    return initialized_ =  true;
  }

  bool base_ostream::open(const bool truncate){
    //if(keep_open_ && file_.is_open()) return true;
    if(!initialized_) return false;

    if(truncate)
      file_.open(file_path_, std::ios_base::out | std::ios_base::trunc | std::ios_base::app);
    else
      file_.open(file_path_, std::ios_base::out | std::ios_base::app);
    return file_.is_open();
  }
} // namespace ramrod
