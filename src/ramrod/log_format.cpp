#include "ramrod/log_format.h"

#include <regex>

#include "ramrod/log.h"
#include "ramrod/log_base.h"


namespace ramrod {
  format_stream::format_stream() :
    current_format_{},
    format_{current_format_.data()}
  {}

  format_stream &format_stream::add_style(const int parameter){
    ramrod::log << "\033[" << parameter << "m";
    if(parameter == log_types::style::reset){
      current_format_ = "\033[0m";
      format_ = current_format_.data();
    }else
      add_format(parameter);
    return *this;
  }

  format_stream &format_stream::colorize(const log_types::type log_type){
    std::string settings("\033[38;5;");

    switch(log_type){
      case log_types::error:
        ramrod::log << (settings += "174m");
      break;
      case log_types::warning:
        ramrod::log << (settings += "229m");
      break;
      case log_types::attention:
        ramrod::log << (settings += "195m");
      break;
      case log_types::good:
        ramrod::log << (settings += "193m");
      break;
      default: break;
    }

    add_format(log_types::style::foreground, settings);
    return *this;
  }

  format_stream &format_stream::colorize(const uint8_t color, const log_types::style usage){
    if(usage == log_types::style::background || usage == log_types::style::foreground){
      const std::string settings("\033[" + std::to_string(usage) + ";5;"
                                 + std::to_string(color) + "m");
      ramrod::log << settings;
      add_format(usage);
    }else
      add_style(usage);
    return *this;
  }

  format_stream &format_stream::colorize(const uint8_t red, const uint8_t green, const uint8_t blue,
                                         const log_types::style usage){
    if(usage == log_types::style::background || usage == log_types::style::foreground){
      const std::string settings("\033[" + std::to_string(usage) + ";2;"
                                 + std::to_string(red) + ";"
                                 + std::to_string(green) + ";"
                                 + std::to_string(blue) + "m");
      ramrod::log << settings;
      add_format(usage, settings);
    }else
      add_style(usage);
    return *this;
  }

  format_stream &format_stream::force_color(const log_types::type type, const bool restart){
    if(restart){
      switch(type){
        case log_types::error:
          current_format_ = "\033[0;1;38;5;174m";
        break;
        case log_types::warning:
          current_format_ = "\033[0;1;38;5;229m";
        break;
        case log_types::attention:
          current_format_ = "\033[0;1;38;5;195m";
        break;
        case log_types::good:
          current_format_ = "\033[0;1;38;5;193m";
        break;
        default:
          return *this;
        break;
      }
      ramrod::log << current_format_;
      format_ = current_format_.data();
    }else{
      switch(type){
        case log_types::error:
          ramrod::log << "\033[0;1;38;5;174m";
        break;
        case log_types::warning:
          ramrod::log << "\033[0;1;38;5;229m";
        break;
        case log_types::attention:
          ramrod::log << "\033[0;1;38;5;195m";
        break;
        case log_types::good:
          ramrod::log << "\033[0;1;38;5;193m";
        break;
        default: break;
      }
    }

    return *this;
  }

  const char *format_stream::current(){
    return format_;
  }

  const char *format_stream::current() const {
    return format_;
  }

  format_stream &format_stream::reset(){
    current_format_.clear();
    format_ = current_format_.data();
    return *this;
  }


  format_stream &format_stream::operator<<(const base_stream &base){
    current_format_ = base.color();
    format_= current_format_.data();
    return *this;
  }
  // ::::::::::::::::::::::::::::::::::::: PRIVATE FUNCTIONS ::::::::::::::::::::::::::::::::::::::

  void format_stream::add_format(const int parameter, const std::string &settings){
    std::string parameter_string(std::to_string(parameter));

    // Cleaning special cases where a certaing code represents the cancelation of others
    if(parameter == 5 || parameter == 6)
      // Blinking cancellation
      parameter_string += "5|6";
    else if(parameter == 53 || parameter == 55)
      // Overline cancellation
      parameter_string += "53|55";
    else if(parameter > 0 && parameter < 10)
      // General style cancellations
      parameter_string += '|' + std::to_string(parameter + 20);
    else if(parameter > 20 && parameter < 30)
      // Same general style cancellation but, inverted
      parameter_string += '|' + std::to_string(parameter - 20);
    else if(parameter > 9 && parameter < 21)
      // Font selection cancellation
      parameter_string = "1[0-9]|20";

    current_format_ = std::regex_replace(current_format_.data(),
                                         std::regex("\u001B\\[(" + parameter_string
                                                    + ")([0-9\\[;])+m"),
                                         "")
                      + settings;
    format_ = current_format_.data();
  }
} // namespace ramrod
