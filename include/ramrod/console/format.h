#ifndef RAMROD_CONSOLE_FORMAT_H
#define RAMROD_CONSOLE_FORMAT_H

#include "ramrod/console/types.h"

#include <iostream>
#include <string>

namespace ramrod {
  namespace console {
    class format
    {
    public:
      format();

      /*
       * ### Sets quick ANSI parameters
       *
       * For more information look at this
       * [link](https://www.wikiwand.com/en/ANSI_escape_code#SGR_(Select_Graphic_Rendition)_parameters)
       *
       * @parameters
       * {const int} parameter = ANSI parameter's number
       *
       */
      format &add_style(const int parameter);
      /*
       * ### Colorize the text using predefined colors
       *
       * This function changes the color of all the next output messages into the Linux's Terminal
       * or Window's console. They are colored depending on its type:
       *   - error: Red
       *   - warning: yellow
       *   - attention: Blue
       *   - message: green
       *
       * @parameters
       * {const ramrod::message::type} color = predefined color
       *
       */
      format &colorize(const ramrod::message::type type);
      /*
       * ### Colorize the text or background using 8-bit colors
       *
       * For more information about the 8-bit color codes look at this
       * [link](https://www.wikiwand.com/en/ANSI_escape_code#8-bit)
       *
       * @parameters
       * {const int} color = ANSI 8-bit color's code
       * {const int} usage = Foreground or Background
       *
       */
      format &colorize(const int color, const int usage = ramrod::console::style::foreground);
      /*
       * ### Colorize the text or background using 24-bit colors
       *
       * For more information about the 24-bit color codes look at this
       * [link](https://www.wikiwand.com/en/ANSI_escape_code#24-bit)
       *
       * @parameters
       * {const int} color = ANSI 24-bit color's code
       * {const int} usage = Foreground or Background
       *
       */
      format &colorize(const int red, const int green, const int blue,
                    const int usage = ramrod::console::style::foreground);

      /*
       * ### Colorize the text using predefined colors and removes previous formatting
       *
       * This function changes the color of all the next output messages into the Linux's Terminal
       * or Window's console. They are colored depending on its type:
       *   - error: Red
       *   - warning: yellow
       *   - attention: Blue
       *   - message: green
       *
       * @parameters
       * {const ramrod::message::type} color = predefined color
       * {const bool} restart = `true` to restart format saved in `current();`
       *
       */
      format &force_color(const ramrod::message::type type, const bool restart = false);

      const std::string &current();
      /*
       * ### Resets the text format in Terminal/Console
       *
       * Deletes all previous text formats and sets all defaults
       *
       */
      format &reset();

      friend std::ostream &operator<<(std::ostream &output, format &input) {
        output << input.current();
        return output;
      }

    private:
      void add_format(const int parameter, const std::string &settings = "");

      std::string current_format_;
    };
  }

  extern console::format format;
}

#endif // RAMROD_CONSOLE_FORMAT_H
