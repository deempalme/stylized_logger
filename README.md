# RamRod Log

C++ library for stylized console and file logging with timestamps, level tags, and colors.

## Index

- [RamRod Log](#ramrod-log)
  - [Index](#index)
  - [Features](#features)
  - [Requirements](#requirements)
  - [Building](#building)
    - [As a subdirectory](#as-a-subdirectory)
    - [Standalone (from the log directory)](#standalone-from-the-log-directory)
  - [Testing](#testing)
  - [How to use](#how-to-use)
    - [Include](#include)
    - [Log levels](#log-levels)
    - [Log to standard output](#log-to-standard-output)
    - [Log to a file](#log-to-a-file)
    - [Switch output at runtime](#switch-output-at-runtime)
    - [printf-style formatting](#printf-style-formatting)
    - [throw\_if](#throw_if)
    - [Date format](#date-format)
    - [Global logger and macros](#global-logger-and-macros)
    - [Single-level loggers](#single-level-loggers)
  - [Message format](#message-format)
  - [API summary](#api-summary)
  - [License](#license)

## Features

- **Log levels**: Verbose, Info, Debug, Warning, and Error — each with a distinct tag and color on the terminal, plus optional filtering via `Logger::log_level` ([details](#log-levels)).
- **Output**: Console (stdout/stderr), file only, or file and console (`OutputType::CONSOLE`, `FILE`, `FILE_AND_CONSOLE`).
- **Format**: Each line is prefixed with `[YYYY-MM-DD HH:MM:SS.uuuuuu][LEVEL]` then your message.
- **API**: Stream-style `logger.info() << "message" << value` and `printf`-style formatting on level loggers.
- **Runtime**: Switch output via `output(OutputType, path)`; set date format and printf buffer size without recreating the logger.

## Requirements

- **C++20** (compiler with C++20 support)
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

### Log levels

Levels are defined by `ramrod::LogLevel` in `ramrod/log/Enumerators.hpp` (the enum is also visible when you include `Logger.hpp`).

| `LogLevel`   | Line tag    | Role                                 |
| ------------ | ----------- | ------------------------------------ |
| `VERBOSE`    | `[VERBOSE]` | Fine-grained detail                  |
| `INFO`       | `[INFO]`    | General operational messages         |
| `DEBUG`      | `[DEBUG]`   | Development diagnostics              |
| `WARNING`    | `[WARNING]` | Recoverable or suspicious conditions |
| `ERROR`      | `[ERROR]`   | Failures and errors                  |

Enum order matches severity for filtering: verbose is lowest, error is highest. On a color terminal each level has its own color; file output uses the same tags without ANSI escape codes.

Call `logger.log_level(level)` to set a **minimum severity**: a channel writes only if its level is **greater than or equal to** that threshold. The default is `LogLevel::VERBOSE`, so every channel is enabled until you change it.

```cpp
ramrod::Logger log;
log.log_level(ramrod::LogLevel::WARNING);

log.verbose() << "skipped";
log.info() << "skipped";
log.debug() << "skipped";
log.warning() << "printed";
log.error() << "printed";
```

`ramrod::Debug`, `ramrod::Info`, and the other single-level types always represent one channel; use `ramrod::Logger` when you want one threshold applied to all of them together.

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
[2026-02-16 14:30:00.002316][ERROR] Connection failed
# Following line is printed with green letters
[2026-02-16 14:30:00.002316][INFO] User count: 42
# Following line is printed with blue letters
[2026-02-16 14:30:00.002316][DEBUG] State: idle code: 0
# Following line is printed with yellow letters
[2026-02-16 14:30:00.002316][WARNING] Low memory: 3 MB
# Following line is printed with default terminal's color
[2026-02-16 14:30:00.002316][VERBOSE] Detail: this is a detailed verbose message
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

### throw_if

`Logger::throw_if` is a template on `ramrod::Logger` only. If the first argument (`condition`) is **true**, it builds a message by streaming the remaining arguments into a string (same idea as chaining `<<`), writes that text through the **error** channel (with the usual timestamp and `[ERROR]` styling), then **throws** an exception of type **`E`**.

- **Template `E`** must derive from `std::exception`. The default is **`std::invalid_argument`**.
- **`E`** must be constructible from a **`const char*`** (the implementation passes the assembled buffer’s data pointer). Standard types such as `std::invalid_argument`, `std::runtime_error`, and `std::logic_error` work.
- If **`condition`** is **false**, nothing is logged and nothing is thrown.

```cpp
ramrod::Logger log;

// Default exception type: std::invalid_argument
log.throw_if(value < 0, "value must be >= 0, got ", value);

// Explicit exception type
log.throw_if<std::runtime_error>(ptr == nullptr, "null pointer");
```

Use this when you want a single check to both record the failure in the log and signal it to callers.

### Date format

Set the `strftime` pattern and the internal date buffer size with `date_format(format, buffer_size, add_microseconds)`. The writer always wraps the formatted time in `[` … `]`; the pattern you pass is what `strftime` receives (see `man strftime`).

**Microseconds (`add_microseconds`)** — The third argument defaults to **`true`**. When enabled, the fractional part of the current second is appended after the `strftime` text as a **six-digit** value, e.g. `[2026-02-16 14:30:00.002316]`. It is computed from the high-resolution clock (fractional second only, not a full timestamp). Pass **`false`** to omit the `.uuuuuu` suffix and shorten timestamps to `[2026-02-16 14:30:00]`.

Size the buffer for: opening `[`, the longest `strftime` output, optional `.000000`, closing `]`, and the null terminator. The library’s own default uses buffer size **32** when microseconds are on (see `Writer`).

**NOTE:** Set the date format and the size of the internal date buffer (must fit the formatted string including null terminator)

```cpp
ramrod::Logger log;

// Default construction: "%Y-%m-%d %H:%M:%S", microseconds on → [2026-02-16 14:30:00.002316]

// No fractional seconds; smaller buffer is enough
log.date_format("%Y-%m-%d %H:%M:%S", 24, false);
log.info() << "After format change";
// Example: "[2026-02-16 14:30:00][INFO] After format change"

// Explicit microseconds (same as omitting the third argument)
log.date_format("%Y-%m-%d %H:%M:%S", 32, true);
```

### Global logger and macros

A global logger and convenience macros are available :

```cpp
#include "ramrod/log/Logger.hpp"

// Changing output log file
RR_LOG.output("/log/new_log_file.log");

RR_LOGI << "info message" << RR_ENDL;
// Prints: [2026-02-16 14:30:00.002316][INFO][file_name.cpp][258] info message\n
RR_LOGE << "error at " << __FILE__ << RR_ENDL;
// Prints: [2026-02-16 14:30:00.002316][ERROR][another_file.cpp][18] error at /home/user/another_file.cpp\n
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

- **Date**: By default local time as `[YYYY-MM-DD HH:MM:SS.uuuuuu]` with six fractional digits unless you call `date_format(..., /*buffer*/, false)` to disable them ([details](#date-format)).
- **LEVEL**: One of `[DEBUG]`, `[ERROR]`, `[INFO]`, `[VERBOSE]`, `[WARNING]`.
- **File info**: if `file_info(__FILE__, __LINE__)` is used, then the filename and line are added, e.g. `[filename.cpp][648]`
- **Message**: Whatever you stream or pass to `printf`; file output is plain text (no ANSI codes).

## API summary

| Class / member                                                             | Description                                                                        |
| -------------------------------------------------------------------------- | ---------------------------------------------------------------------------------- |
| `ramrod::Logger`                                                           | Holds `debug()`, `error()`, `info()`, `verbose()`, `warning()` level loggers.      |
| `ramrod::LogLevel`                                                         | `VERBOSE`, `INFO`, `DEBUG`, `WARNING`, `ERROR` — used with `logger.log_level`.     |
| `logger.log_level(level)`                                                  | Minimum severity to print; default `VERBOSE` (all levels on).                      |
| `logger.debug()` / `.error()` / `.info()` / `.verbose()` / `.warning()`    | Level logger; use `<<` or `.printf(format, ...)`.                                  |
| `Logger::OutputType`                                                       | `CONSOLE`, `FILE`, `FILE_AND_CONSOLE`.                                             |
| `logger.output()`                                                          | Current output path (empty if console).                                            |
| `logger.output(type, path)`                                                | Switch output. Returns `true` on success.                                          |
| `logger.date_format()` / `logger.date_format(fmt, size, add_microseconds)` | Get or set `strftime` pattern, buffer size, and optional `.uuuuuu` suffix.         |
| `logger.printf_buffer_size()` / `logger.printf_buffer_size(n)`             | Get or set printf buffer size (default 1024).                                      |
| `logger.throw_if<E>(condition, args...)`                                   | If `condition`, log to `error()` then throw `E` (default `std::invalid_argument`). |
| `logger.clear()`, `logger.end()`, `logger.flush()`                         | Clear output, end line, flush.                                                     |
| `ramrod::global_logger`, `RR_LOG`, `RR_LOGD`, …                            | Global logger and macros.                                                          |

## License

See the project root for license information.
