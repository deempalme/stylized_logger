#include "ramrod/console/format.h"

#include <regex>

namespace ramrod {
  namespace console {
    format_stream::format_stream() :
      current_format_("\033[0m")
    {}

    format_stream &format_stream::add_style(const int parameter){
      std::cout << "\033[" << parameter << "m";
      if(parameter != style::reset)
        add_format(parameter);
      else
        current_format_ = "\033[0m";
      return *this;
    }

    format_stream &format_stream::colorize(const message::type type){
      std::string settings("\033[38;5;");

      switch(type){
        case message::error:
          std::cout << (settings += "174m");
        break;
        case message::warning:
          std::cout << (settings += "229m");
        break;
        case message::attention:
          std::cout << (settings += "195m");
        break;
        default:
          std::cout << (settings += "193m");
        break;
      }

      add_format(style::foreground, settings);
      return *this;
    }

    format_stream &format_stream::colorize(const int color, const int usage){
      if(usage == style::background
         || usage == style::foreground){
        const std::string settings("\033[" + std::to_string(usage) + ";5;"
                                   + std::to_string(color) + "m");
        std::cout << settings;
        add_format(usage);
      }else
        add_style(usage);
      return *this;
    }

    format_stream &format_stream::colorize(
        const int red, const int green, const int blue, const int usage){
      if(usage == style::background
         || usage == style::foreground){
        const std::string settings("\033[" + std::to_string(usage) + ";2;"
                                   + std::to_string(red) + ";" + std::to_string(green)
                                   + ";" + std::to_string(blue) + "m");
        std::cout << settings;
        add_format(usage, settings);
      }else
        add_style(usage);
      return *this;
    }

    format_stream &format_stream::force_color(
        const message::type type, const bool restart){
      if(restart){
        std::cout << current_format_;
        return *this;
      }

      switch(type){
        case message::error:
          std::cout << "\033[0;1;38;5;174m";
        break;
        case message::warning:
          std::cout << "\033[0;1;38;5;229m";
        break;
        case message::attention:
          std::cout << "\033[0;1;38;5;195m";
        break;
        default:
          std::cout << "\033[0;1;38;5;193m";
        break;
      }
      return *this;
    }

    const std::string &format_stream::current(){
      return current_format_;
    }

    format_stream &format_stream::reset(){
      current_format_ = "\033[0m";
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

      current_format_ = std::regex_replace(current_format_,
                                           std::regex("\u001B\\[(" + parameter_string
                                                      + ")([0-9\\[;])+m"),
                                           "")
                        + settings;
    }
  } // namespace: console
} // namespace: ramrod
