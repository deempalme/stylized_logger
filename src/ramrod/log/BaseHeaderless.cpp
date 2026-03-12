#include "ramrod/log/BaseHeaderless.hpp"

#include "ramrod/log/OutputFile.hpp"

/// @brief String used to clear all ANSI format: 0m - reset all styles
static constexpr char CLEAR_FORMAT[]{"\e[0m"};
/// @brief String used when no format is necessary
static constexpr char NO_FORMAT[]{""};

namespace ramrod
{
    BaseHeaderless::BaseHeaderless()
        : Output{},
         _ansi_format{NO_FORMAT}
    {
    }

    BaseHeaderless::BaseHeaderless(const std::filesystem::path &output_path)
        : Output{OutputFile{output_path}},
          _ansi_format{NO_FORMAT}
    {
    }

    BaseHeaderless &BaseHeaderless::operator<<(const bool message)
    {
        Output::operator<<(_ansi_format) << message << CLEAR_FORMAT;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const char message)
    {
        Output::operator<<(_ansi_format) << message << CLEAR_FORMAT;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::int8_t message)
    {
        Output::operator<<(_ansi_format) << message << CLEAR_FORMAT;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::uint8_t message)
    {
        Output::operator<<(_ansi_format) << message << CLEAR_FORMAT;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const char *message)
    {
        Output::operator<<(_ansi_format) << message << CLEAR_FORMAT;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::int8_t *message)
    {
        Output::operator<<(_ansi_format) << message << CLEAR_FORMAT;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::uint8_t *message)
    {
        Output::operator<<(_ansi_format) << message << CLEAR_FORMAT;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::int16_t message)
    {
        Output::operator<<(_ansi_format) << message << CLEAR_FORMAT;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::uint16_t message)
    {
        Output::operator<<(_ansi_format) << message << CLEAR_FORMAT;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::int32_t message)
    {
        Output::operator<<(_ansi_format) << message << CLEAR_FORMAT;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::uint32_t message)
    {
        Output::operator<<(_ansi_format) << message << CLEAR_FORMAT;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const float message)
    {
        Output::operator<<(_ansi_format) << message << CLEAR_FORMAT;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::int64_t message)
    {
        Output::operator<<(_ansi_format) << message << CLEAR_FORMAT;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::uint64_t message)
    {
        Output::operator<<(_ansi_format) << message << CLEAR_FORMAT;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const double message)
    {
        Output::operator<<(_ansi_format) << message << CLEAR_FORMAT;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const long double message)
    {
        Output::operator<<(_ansi_format) << message << CLEAR_FORMAT;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::string &message)
    {
        Output::operator<<(_ansi_format) << message << CLEAR_FORMAT;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::string_view &message)
    {
        Output::operator<<(_ansi_format) << message << CLEAR_FORMAT;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const void *message)
    {
        Output::operator<<(_ansi_format) << message << CLEAR_FORMAT;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::exception &message)
    {
        Output::operator<<(_ansi_format) << message << CLEAR_FORMAT;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::error_code &message)
    {
        Output::operator<<(_ansi_format) << message << CLEAR_FORMAT;
        return *this;
    }
} // namespace ramrod