#include "ramrod/log/Logger.hpp"

#include "ramrod/log/WriterCerr.hpp"
#include "ramrod/log/WriterFile.hpp"
#include "ramrod/log/WriterFileCerr.hpp"
#include "ramrod/log/WriterFileCout.hpp"

namespace ramrod
{
const std::filesystem::path Logger::TO_CONSOLE{""};

Logger::Logger()
    : writer_{std::make_unique<Writer>()},
      writer_cerr_{std::make_unique<WriterCerr>()},
      file_{},
      debug_{std::make_unique<Debug>(*writer_)},
      error_{std::make_unique<Error>(*writer_cerr_)},
      info_{std::make_unique<Info>(*writer_)},
      verbose_{std::make_unique<Verbose>(*writer_)},
      warning_{std::make_unique<Warning>(*writer_)}
{
}

Logger::Logger(const OutputType type, const std::filesystem::path& path)
    : writer_{std::make_unique<Writer>()},
      writer_cerr_{std::make_unique<WriterCerr>()},
      file_{},
      debug_{},
      error_{},
      info_{},
      verbose_{},
      warning_{}
{
    output(type, path);
}

Debug& Logger::debug()
{
    debug_->header();
    return *debug_;
}

Error& Logger::error()
{
    error_->header();
    return *error_;
}

Info& Logger::info()
{
    info_->header();
    return *info_;
}

Verbose& Logger::verbose()
{
    verbose_->header();
    return *verbose_;
}

Warning& Logger::warning()
{
    warning_->header();
    return *warning_;
}

void Logger::clear()
{
    writer_->clear();
}

const char* Logger::date_format() const
{
    return writer_->date_format();
}

bool Logger::date_format(const std::string& date_format, const size_t date_buffer_size)
{
    return writer_->date_format(date_format, date_buffer_size);
}

void Logger::end()
{
    writer_->end();
}

void Logger::flush()
{
    writer_->flush();
}

size_t Logger::printf_buffer_size() const
{
    return writer_->printf_buffer_size();
}

void Logger::printf_buffer_size(const size_t new_size)
{
    writer_->printf_buffer_size(new_size);
}

const std::filesystem::path& Logger::output() const
{
    if (file_)
        return file_->path();
    return TO_CONSOLE;
}

bool Logger::output(const OutputType type, const std::filesystem::path& path)
{
    const bool success{change_output(type, path)};

    // Setting the new output to all the loggers
    debug_.reset(new Debug{*writer_});
    error_.reset(new Error{*writer_cerr_});
    info_.reset(new Info{*writer_});
    verbose_.reset(new Verbose{*writer_});
    warning_.reset(new Warning{*writer_});

    return success;
}

bool Logger::change_output(const OutputType type, const std::filesystem::path& path)
{
    bool success{true};

    if ((type == OutputType::FILE_AND_CONSOLE) && !path.empty())
    {
        file_.reset(new File{path});
        if (file_->is_open())
        {
            writer_.reset(new WriterFileCout{*file_});
            writer_cerr_.reset(new WriterFileCerr{*file_});
            return true;
        }
        // Use regular standard output (stdout and stderr)
        success = false;
    }
    else if ((type == OutputType::FILE) && !path.empty())
    {
        file_.reset(new File{path});
        if (file_->is_open())
        {
            writer_.reset(new WriterFile{*file_});
            writer_cerr_.reset(new WriterFileCerr{*file_});
            return true;
        }
        // Use regular standard output (stdout and stderr)
        success = false;
    }
    else if ((type != OutputType::CONSOLE) && path.empty())
    {
        // Use regular standard output (stdout and stderr)
        success = false;
    }

    file_.reset();
    writer_.reset(new Writer());
    writer_cerr_.reset(new WriterCerr());
    return success;
}

Logger global_logger{};
} // namespace ramrod