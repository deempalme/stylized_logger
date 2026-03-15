# RamRod Log

C++ library for stylized console and file logging with timestamps, level tags, and colors.

## Index

- [Features](#features)
- [Requirements](#requirements)
- [Building](#building)
  - [As a subdirectory](#as-a-subdirectory)
  - [Standalone (from the log directory)](#standalone-from-the-log-directory)
- [Testing](#testing)
- [How to use](#how-to-use)
  - [Include](#include)
  - [Log to standard output](#log-to-standard-output)
  - [Log to a file](#log-to-a-file)
  - [Switch output at runtime](#switch-output-at-runtime)
  - [printf-style formatting](#printf-style-formatting)
  - [Date format](#date-format)
  - [Global logger and macros](#global-logger-and-macros)
  - [Single-level loggers](#single-level-loggers)
- [Message format](#message-format)
- [API summary](#api-summary)
- [License](#license)

## Features

- **Log levels**: Debug, Error, Info, Verbose, Warning — each with a distinct tag and color (on terminal).
- **Output**: Console (stdout/stderr), file only, or file and console (`OutputType::CONSOLE`, `FILE`, `FILE_AND_CONSOLE`).
- **Format**: Each line is prefixed with `[YYYY-MM-DD HH:MM:SS +zzzz][LEVEL]` then your message.
- **API**: Stream-style `logger.info() << "message" << value` and `printf`-style formatting on level loggers.
- **Runtime**: Switch output via `output(OutputType, path)`; set date format and printf buffer size without recreating the logger.

## Requirements

- **C++17**
- **CMake** 3.22 or later
- **Dependencies**: none (uses only the C++ standard library)

## Building

The library is built as a static target `RamRodLog`. It is usually included as a subdirectory from a parent `CMakeLists.txt`.

### As a subdirectory

```cmake
add_subdirectory(path/to/lib/ramrod/log)

target_link_libraries(your_target PRIVATE ${RamRodLog_LIBRARIES})
target_include_directories(your_target PRIVATE ${RamRodLog_INCLUDE_DIRS})
```

(Adjust to match your project’s CMake variables for the log library.)

### Standalone (from the log directory)

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

Or run the `compile.sh` script from the project root; it configures and builds in the `build` directory.

## Testing

Unit tests use Google Test. Build with tests enabled, then run the test executable:

```bash
./tests/run_tests.sh
```

Run a subset of tests by passing a GTest filter:

```bash
./tests/run_tests.sh "LoggerTest.*"
./tests/run_tests.sh --gtest_filter=LoggerTest.DefaultConstruction
```

## How to use

### Include

```cpp
#include "ramrod/log/Logger.hpp"
```

### Log to standard output

Create a `Logger` (default constructor) and use the level accessors with the stream operator `<<`:

```cpp
ramrod::Logger log;

log.error() << "Connection failed";
log.info() << "User count: " << 42;
log.debug() << "State: " << state_name << " code: " << code;
log.warning() << "Low memory: " << free_mb << " MB";
log.verbose() << "Detail: " << detail_string;
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

Construct the logger with an output type and path. All levels write to the same file. File output has no ANSI color codes.

```cpp
ramrod::Logger log(ramrod::Logger::OutputType::FILE, "/var/log/myapp.log");

log.info() << "Application started";
log.error() << "Error: " << error_message;
```

### Switch output at runtime

Redirect all levels to a new file or back to console without creating a new logger:

```cpp
ramrod::Logger log;
log.info() << "This goes to stdout";

if (!log.output(ramrod::Logger::OutputType::FILE, "/var/log/myapp.log"))
    std::cerr << "Failed to open log file\n";
else
    log.info() << "This goes to the file";

// Back to console
log.output(ramrod::Logger::OutputType::CONSOLE);
```

### printf-style formatting

Use `.printf()` on any level logger. The default buffer size is 1024 bytes; increase it if you need longer lines.

```cpp
ramrod::Logger log;

log.error().printf("Error code %d: %s\n", errno, strerror(errno));
log.info().printf("Progress: %3d%%\n", percent);

log.printf_buffer_size(4096);
log.info().printf("Long message: %s ...\n", long_string);
```

### Date format

Set the date format and the size of the internal date buffer (must fit the formatted string including null terminator):

```cpp
ramrod::Logger log;

// Default is "[%Y-%m-%d %H:%M:%S %z]" (e.g. [2026-02-16 14:30:00 +0100])
// The number 23 includes the null terminator character
log.date_format("[%Y-%m-%d %H:%M:%S]", 23);
log.info() << "After format change";
// Prints: "[2026-02-16 14:30:00][INFO] After format change"
```

### Global logger and macros

A global logger and convenience macros are available :

```cpp
#include "ramrod/log/Logger.hpp"

// Changing output log file
RR_LOG.output("/log/new_log_file.log");

RR_LOGI << "info message" << RR_ENDL;
// Prints: [2026-02-16 14:30:00 +0100][INFO][file_name.cpp][258] info message\n
RR_LOGE << "error at " << __FILE__ << RR_ENDL;
// Prints: [2026-02-16 14:30:00 +0100][ERROR][another_file.cpp][18] error at /home/user/another_file.cpp\n
```

| Macro    | Expands to                                              |
| -------- | ------------------------------------------------------- |
| `RR_LOG` | `ramrod::global_logger`                                 |
| `RR_LOGD`| `global_logger.debug().file_info(__FILE__, __LINE__)`   |
| `RR_LOGE`| `global_logger.error().file_info(__FILE__, __LINE__)`   |
| `RR_LOGI`| `global_logger.info().file_info(__FILE__, __LINE__)`    |
| `RR_LOGV`| `global_logger.verbose().file_info(__FILE__, __LINE__)` |
| `RR_LOGW`| `global_logger.warning().file_info(__FILE__, __LINE__)` |
| `RR_ENDL`| `ramrod::endl`                                          |

### Single-level loggers

For a single level, use `ramrod::Debug`, `ramrod::Error`, `ramrod::Info`, `ramrod::Verbose`, or `ramrod::Warning` with a `Writer` (or `WriterCerr` for Error). See the headers and tests for examples.

## Message format

Each log line is:

```bash
# Without file_info(__FILE__, __LINE__)
[<date>][<LEVEL>] <your message>
# With file_info(__FILE__, __LINE__)
[<date>][<LEVEL>][<filename(__FILE__)>][<__LINE__>] <your message>
```

- **Date**: By default `[YYYY-MM-DD HH:MM:SS +zzzz]` (configurable via `date_format()`).
- **LEVEL**: One of `[DEBUG]`, `[ERROR]`, `[INFO]`, `[VERBOSE]`, `[WARNING]`.
- **File info**: if `file_info(__FILE__, __LINE__)` is used, then the filename and line are added, e.g. `[filename.cpp][648]`
- **Message**: Whatever you stream or pass to `printf`; file output is plain text (no ANSI codes).

## API summary

| Class / member                                                          | Description                                                                   |
| ----------------------------------------------------------------------- | ----------------------------------------------------------------------------- |
| `ramrod::Logger`                                                        | Holds `debug()`, `error()`, `info()`, `verbose()`, `warning()` level loggers. |
| `logger.debug()` / `.error()` / `.info()` / `.verbose()` / `.warning()` | Level logger; use `<<` or `.printf(format, ...)`.                             |
| `Logger::OutputType`                                                    | `CONSOLE`, `FILE`, `FILE_AND_CONSOLE`.                                        |
| `logger.output()`                                                       | Current output path (empty if console).                                       |
| `logger.output(type, path)`                                             | Switch output. Returns `true` on success.                                     |
| `logger.date_format()` / `logger.date_format(fmt, size)`                | Get or set date format and buffer size.                                       |
| `logger.printf_buffer_size()` / `logger.printf_buffer_size(n)`          | Get or set printf buffer size (default 1024).                                 |
| `logger.clear()`, `logger.end()`, `logger.flush()`                      | Clear output, end line, flush.                                                |
| `ramrod::global_logger`, `RR_LOG`, `RR_LOGD`, …                         | Global logger and macros.                                                     |

## License

See the project root for license information.
