#include "ramrod/log/OutputFile.hpp"

#include "ramrod/log/Constants.hpp"

namespace ramrod
{
    OutputFile::OutputFile(const std::filesystem::path &filepath) :
        file_{filepath, std::ios_base::out | std::ios_base::app},
        filepath_{filepath},
        is_open_{file_.is_open()}
    {
    }

    OutputFile::~OutputFile()
    {
        close();
    }

    void OutputFile::clear()
    {
        close();
        file_.open(filepath_, std::ios_base::out | std::ios_base::trunc);
        is_open_ = file_.is_open();
    }

    void OutputFile::clear_format()
    {
        // Do nothing since files are not compatible with ANSI format
    }

    void OutputFile::end()
    {
        // Nothing to do with ANSI format since files are not compatible with it, just
        // adding a new line to the end of the file
        file_ << ENDL;
    }

    OutputFile& OutputFile::file_info(const char* file, const int line)
    {
        file_ << INFO_PREFIX << file << INFO_SEPARATOR << line << INFO_SUFFIX;
        return *this;
    }

    void OutputFile::flush()
    {
        file_.flush();
    }

    void OutputFile::format(const char*)
    {
        // Do nothing since files are not compatible with ANSI format
    }

    void OutputFile::header(const char *, const char *date, const char *level_tag)
    {
        // ansi_format is ignored since files are not compatible with ANSI format
        file_ << date << level_tag;
    }

    bool OutputFile::verify_status()
    {
        // If file was properly opened but then was deleted, reopen it.
        if (is_open_ && !std::filesystem::exists(filepath_))
        {
            close();
            file_.open(filepath_, std::ios_base::out | std::ios_base::app);
            is_open_ = file_.is_open();
        }
        return is_open_;
    }

    OutputFile &OutputFile::operator<<(const bool message)
    {
        file_ << message;
        return *this;
    }

    OutputFile &OutputFile::operator<<(const char message)
    {
        file_ << message;
        return *this;
    }

    OutputFile &OutputFile::operator<<(const std::int8_t message)
    {
        file_ << message;
        return *this;
    }

    OutputFile &OutputFile::operator<<(const std::uint8_t message)
    {
        file_ << message;
        return *this;
    }

    OutputFile &OutputFile::operator<<(const char *message)
    {
        file_ << message;
        return *this;
    }

    OutputFile &OutputFile::operator<<(const std::int8_t *message)
    {
        file_ << message;
        return *this;
    }

    OutputFile &OutputFile::operator<<(const std::uint8_t *message)
    {
        file_ << message;
        return *this;
    }

    OutputFile &OutputFile::operator<<(const std::int16_t message)
    {
        file_ << message;
        return *this;
    }

    OutputFile &OutputFile::operator<<(const std::uint16_t message)
    {
        file_ << message;
        return *this;
    }

    OutputFile &OutputFile::operator<<(const std::int32_t message)
    {
        file_ << message;
        return *this;
    }

    OutputFile &OutputFile::operator<<(const std::uint32_t message)
    {
        file_ << message;
        return *this;
    }

    OutputFile &OutputFile::operator<<(const float message)
    {
        file_ << message;
        return *this;
    }

    OutputFile &OutputFile::operator<<(const std::int64_t message)
    {
        file_ << message;
        return *this;
    }

    OutputFile &OutputFile::operator<<(const std::uint64_t message)
    {
        file_ << message;
        return *this;
    }

    OutputFile &OutputFile::operator<<(const double message)
    {
        file_ << message;
        return *this;
    }

    OutputFile &OutputFile::operator<<(const long double message)
    {
        file_ << message;
        return *this;
    }

    OutputFile &OutputFile::operator<<(const std::string &message)
    {
        file_ << message.c_str();
        return *this;
    }

    OutputFile &OutputFile::operator<<(const std::string_view &message)
    {
        file_ << message.data();
        return *this;
    }

    OutputFile &OutputFile::operator<<(const void *message)
    {
        file_ << message;
        return *this;
    }

    OutputFile &OutputFile::operator<<(const std::exception &message)
    {
        file_ << message.what();
        return *this;
    }

    OutputFile &OutputFile::operator<<(const std::error_code &message)
    {
        // The full string should be: "(<error_code>) <error_message>"
        file_ << ERROR_PREFIX << message.value() << ERROR_SUFFIX << message.message().c_str();
        return *this;
    }

    void OutputFile::close()
    {
        if (file_.is_open())
        {
            file_.close();
        }
        is_open_ = false;
    }
} // namespace ramrod
