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

    void OutputFile::clear()
    {
        close();
        file_.open(filepath_, std::ios_base::out | std::ios_base::trunc);
        is_open_ = file_.is_open();
    }

    void OutputFile::end()
    {
        // Nothing to do with ANSI format since files are not compatible with it, just
        // adding a new line to the end of the file
        /// @brief String used to add a new line to the end of the file
        static constexpr char ENDL[]{"\n"};
        file_ << ENDL;
    }

    void OutputFile::format(const char *ansi_format)
    {
        // Nothing to do since files are not compatible with ANSI format
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

    void OutputFile::close()
    {
        if (file_.is_open())
        {
            file_.close();
        }
        is_open_ = false;
    }
} // namespace ramrod
