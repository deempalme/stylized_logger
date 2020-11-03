#ifndef RAMROD_CONSOLE_H
#define RAMROD_CONSOLE_H

#include "ramrod/console/attention.h"
#include "ramrod/console/clean.h"
#include "ramrod/console/cout.h"
#include "ramrod/console/endl.h"
#include "ramrod/console/error.h"
#include "ramrod/console/flush.h"
#include "ramrod/console/regular.h"
#include "ramrod/console/types.h"
#include "ramrod/console/warning.h"

#include <cstdarg>

namespace ramrod {
  namespace console {
    /*
     * ### Displaying messages in Terminal/Console with std::printf style format
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
     * @parameters
     * {const char*} format = Pointer to a null-terminated multibyte string specifying how
     *                        to interpret the data.
     * {const int} type = Type of message to display.
     * {...} = variable argument list (multiple variables, multiple types)
     *
     */
    int formatted(const char *format, const message::type type, ...)
    __attribute__((format (printf, 1, 3)));
    int formatted(const char *format, ...)  __attribute__((format (printf, 1, 2)));

    int printf(const char *format, const message::type type, ...)
    __attribute__((format (printf, 1, 3)));
    int printf(const char *format, ...) __attribute__((format (printf, 1, 2)));

  } // namespace: console
} // namespace: ramrod

namespace rr = ramrod::console;

#endif // RAMROD_CONSOLE_H
