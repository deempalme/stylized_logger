#include "ramrod/log/File.hpp"

namespace ramrod
{
File::File(const std::filesystem::path& filepath)
    : file_{filepath, std::ios_base::out | std::ios_base::app},
      filepath_{filepath},
      is_open_{file_.is_open()}
{
}

File::~File()
{
    close();
}

void File::clear()
{
    close();
    file_.open(filepath_, std::ios_base::out | std::ios_base::trunc);
    is_open_ = file_.is_open();
}

void File::close()
{
    if (file_.is_open())
    {
        file_.close();
    }
    is_open_ = false;
}

void File::flush()
{
    file_.flush();
}

bool File::open(const std::filesystem::path& filepath)
{
    close();
    file_.open(filepath, std::ios_base::out | std::ios_base::app);
    filepath_ = filepath;
    return is_open_ = file_.is_open();
}

bool File::is_open() const
{
    return is_open_;
}

const std::filesystem::path& File::path() const
{
    return filepath_;
}

File &File::operator<<(const bool message)
{
    file_ << message;
    return *this;
}

File &File::operator<<(const char message)
{
    file_ << message;
    return *this;
}

File &File::operator<<(const unsigned char message)
{
    file_ << message;
    return *this;
}

File &File::operator<<(const char *message)
{
    file_ << message;
    return *this;
}

File &File::operator<<(const unsigned char *message)
{
    file_ << message;
    return *this;
}

File &File::operator<<(const short message)
{
    file_ << message;
    return *this;
}

File &File::operator<<(const unsigned short message)
{
    file_ << message;
    return *this;
}

File &File::operator<<(const int message)
{
    file_ << message;
    return *this;
}

File &File::operator<<(const unsigned int message)
{
    file_ << message;
    return *this;
}

File &File::operator<<(const float message)
{
    file_ << message;
    return *this;
}

File &File::operator<<(const long message)
{
    file_ << message;
    return *this;
}

File &File::operator<<(const unsigned long message)
{
    file_ << message;
    return *this;
}

File &File::operator<<(const double message)
{
    file_ << message;
    return *this;
}

File &File::operator<<(const long double message)
{
    file_ << message;
    return *this;
}

File &File::operator<<(const long long message)
{
    file_ << message;
    return *this;
}

File &File::operator<<(const unsigned long long message)
{
    file_ << message;
    return *this;
}

File &File::operator<<(const void *message)
{
    file_ << message;
    return *this;
}
} // namespace ramrod
