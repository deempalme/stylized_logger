# RamRod Log

C++ library for stylized console and file logging with timestamps, level tags, and optional ANSI colors.

## Features

- **Log levels**: Debug, Error, Info, Verbose, Warning — each with a distinct tag and color (on terminal).
- **Output**: Standard output (colored when supported) or a file (no ANSI codes in file).
- **Format**: Each line is prefixed with `[YYYY-MM-DD HH:MM:SS +zzzz][LEVEL]` then your message.
- **API**: Call-style `logger.error("message")` or `logger.info("value: ", x)` with multiple arguments; optional `printf`-style formatting.
- **Runtime**: Switch output to another file or change date format and buffer sizes without recreating the logger.

## Requirements

- **C++17**
- **CMake** 3.15 or later
- **Dependencies**: none (uses only the C++ standard library)

## Building

The library is built as a static target `RamRodLog`. It is usually included as a subdirectory from a parent `CMakeLists.txt`.

### As a subdirectory

```cmake
add_subdirectory(path/to/lib/ramrod/log)

target_link_libraries(your_target PRIVATE ${RamRodLog_LIBRARIES})
target_include_directories(your_target PRIVATE ${RamRodLog_INCLUDE_DIRS})
```

### Standalone (from the log directory)

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

Or run `compile.sh` bash script (it should be compiled inside _build_ directory)

## How to use

### Include

```cpp
#include "ramrod/log/Logger.hpp"
```

### Log to standard output

Create a `Logger` and use the level members: `debug`, `error`, `info`, `verbose`, `warning`. Call them with `operator()` with one or more arguments (any type that can be streamed with `<<`).

```cpp
ramrod::Logger log;

log.error("Connection failed");
log.info("User count: ", 42);
log.debug("State: ", state_name, " code: ", code);
log.warning("Low memory: ", free_mb, " MB");
log.verbose("Detail: ", detail_string);
```

Output on terminal (with colors) looks like:

```bash
# Following line is printed with red letters
[2026-02-16 14:30:00 +0100][ERROR] Connection failed
# Following line is printed with green letters
[2026-02-16 14:30:00 +0100][INFO] User count: 42
# Following line is printed with blue letters
[2026-02-16 14:30:00 +0100][DEBUG] State: idle code: 0
# Following line is printed with yellow letters
[2026-02-16 14:30:00 +0100][WARNING] Low memory: 3 MB
# Following line is printed with default terminal's color
[2026-02-16 14:30:00 +0100][VERBOSE] Detail: this is a detailed verbose message
```

### Log to a file

Construct the logger with a path. All levels write to the same file. File output has no ANSI color codes.

```cpp
ramrod::Logger log("/var/log/myapp.log");

log.info("Application started");
log.error("Error: ", error_message);
```

If the log file can be **deleted while the application is running** (e.g. by log rotation or an external tool), you must call **`verify_status()`** so the file is recreated when missing. The library does not call it automatically. When using `OutputFile` directly, call `verify_status()` before writing (or periodically); it returns `true` if the file is open (or was successfully reopened), `false` otherwise.

### Switch output at runtime

You can redirect all levels to a new file without creating a new logger:

```cpp
ramrod::Logger log;
log.info("This goes to stdout");

if (!log.change_log_output("/var/log/myapp.log"))
    std::cerr << "Failed to open log file\n";
else
    log.info("This goes to the file");
```

### printf-style formatting

Use `printf` on any level logger for formatted messages. The default buffer size is 1024 bytes; increase it if you need longer lines.

```cpp
ramrod::Logger log;

log.error.printf("Error code %d: %s\n", errno, strerror(errno));
log.info.printf("Progress: %3d%%\n", percent);

// Optional: increase buffer for long lines
log.printf_buffer_size(4096);
log.info.printf("Long message: %s ...\n", long_string);
```

### Customize date format

Change the date format and the size of the internal date buffer (must fit the formatted string including null terminator):

```cpp
ramrod::Logger log;

// Default is "[%Y-%m-%d %H:%M:%S %z]" (e.g. [2026-02-16 14:30:00 +0100])
// The number 23 includes the null terminator character
log.change_date_format("[%Y-%m-%d %H:%M:%S]", 23);
```

### Use a single level (e.g. only Error)

If you only need one level, use `ramrod::Error`, `ramrod::Info`, etc. directly:

```cpp
#include "ramrod/log/Error.hpp"

ramrod::Error err("/var/log/errors.log");
err("Something went wrong: ", details);
err.printf("Code: %d\n", code);
```

Same pattern for `ramrod::Debug`, `ramrod::Info`, `ramrod::Verbose`, `ramrod::Warning`.

## Message format

Each log line is:

```bash
[<date>][<LEVEL>] <your message>\n
```

- **Date**: By default `[YYYY-MM-DD HH:MM:SS +zzzz]` (configurable via `change_date_format`).
- **LEVEL**: One of `[DEBUG]`, `[ERROR]`, `[INFO]`, `[VERBOSE]`, `[WARNING]`.
- **Message**: Whatever you pass to `operator()` or `printf`; multiple arguments are concatenated in order.

On a terminal, the level (and optionally the date) is colored; in a file, only plain text is written.

## API summary

| Class / member                                                 | Description                                                              |
| -------------------------------------------------------------- | ------------------------------------------------------------------------ |
| `ramrod::Logger`                                               | Holds `debug`, `error`, `info`, `verbose`, `warning` loggers.            |
| `logger.debug` / `.error` / `.info` / `.verbose` / `.warning`  | Level-specific logger; call with `(args...)` or `.printf(format, ...)`.  |
| `logger.change_log_output(path)`                               | Redirect all levels to a new file. Returns `true` on success.            |
| `logger.change_date_format(format, buffer_size)`               | Set date format string and date buffer size.                             |
| `logger.printf_buffer_size()` / `logger.printf_buffer_size(n)` | Get or set the printf buffer size (default 1024).                        |
| `ramrod::Debug`, `Error`, `Info`, `Verbose`, `Warning`         | Standalone loggers for a single level; same `operator()`, `printf`, etc. |
| `OutputFile::verify_status()`                                  | Call to ensure the file is open; recreates it if it was deleted while in use. |

## License

See the project root for license information.
