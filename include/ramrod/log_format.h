#ifndef RAMROD_LOG_FORMAT_H
#define RAMROD_LOG_FORMAT_H

#include <string>

#include "ramrod/log_types.h"


namespace ramrod {
  class base_stream;

  class format_stream
  {
  public:
    format_stream();
    /**
     * @brief Sets quick ANSI parameters
     *
     * For more information look at this
     * [link](https://www.wikiwand.com/en/ANSI_escape_code#SGR_(Select_Graphic_Rendition)_parameters)
     *
     * @param parameter ANSI parameter's number
     *
     * @return Current object reference
     */
    format_stream &add_style(const int parameter);
    /**
     * @brief Colorize the text using predefined colors
     *
     * This function changes the color of all the next output messages into the Linux's Terminal
     * or Window's console. They are colored depending on its type:
     *   - error:     Red
     *   - warning:   Yellow
     *   - attention: Blue
     *   - good:      Green
     *
     * @param log_type  Log's predefined message type
     *
     * @return Current object reference
     */
    format_stream &colorize(const log_types::type log_type);
    /**
     * @brief Colorize the text or background using 8-bit colors
     *
     * For more information about the 8-bit color codes look at this
     * [link](https://www.wikiwand.com/en/ANSI_escape_code#8-bit)
     *
     * @param color  ANSI 8-bit color's code
     * @param usage  ANSI style
     *
     * @return Current object reference
     */
    format_stream &colorize(const uint8_t color,
                            const log_types::style usage = log_types::style::foreground);
    /**
     * @brief Colorize the text or background using 24-bit colors
     *
     * For more information about the 24-bit color codes look at this
     * [link](https://www.wikiwand.com/en/ANSI_escape_code#24-bit)
     *
     * @param red    ANSI 8-bit red's color value
     * @param green  ANSI 8-bit green's color value
     * @param blue   ANSI 8-bit blue's color value
     * @param usage  ANSI style
     *
     * @return Current object reference
     */
    format_stream &colorize(const uint8_t red, const uint8_t green, const uint8_t blue,
                            const log_types::style usage = log_types::style::foreground);
    /**
     * @brief Colorize the text using predefined colors and removes previous formatting color
     *
     * This function changes the color of all the next output messages into the Linux's Terminal
     * or Window's console. They are colored depending on its type:
     *   - error:     Red
     *   - warning:   Yellow
     *   - attention: Blue
     *   - good:      Green
     *
     * @param log_type  Log's predefined message type
     * @param restart   Forces removal of previous formatting
     *
     * @return Current object reference
     */
    format_stream &force_color(const log_types::type type, const bool restart = false);
    /**
     * @brief Getting the current formatting in a string
     *
     * @return Current formatting
     */
    const char *current();
    const char *current() const;
    /**
     * @brief Resets the text format in Terminal/Console
     *
     * Deletes all previous text formats and sets all defaults
     *
     * @return  Current object reference
     */
    format_stream &reset();

    format_stream &operator<<(const base_stream &base);
  private:
    void add_format(const int parameter, const std::string &settings = "");

    std::string current_format_;
    const char *format_;
  };

  inline static format_stream log_format;
}

namespace rr = ramrod;

#endif // RAMROD_LOG_FORMAT_H
