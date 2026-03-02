#include "ramrod/log/OutputFile.hpp"

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

    bool OutputFile::ok()
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
        file_ << message;
        return *this;
    }

    OutputFile &OutputFile::operator<<(const std::string_view &message)
    {
        file_ << message;
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
        file_ << message.message();
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
