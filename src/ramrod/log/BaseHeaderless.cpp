#include "ramrod/log/BaseHeaderless.hpp"

#include <ctime>
#include <iomanip>

namespace
{
    /// @brief String used to clear all ANSI format
    static constexpr char CLEAR_FORMAT[]{""};
    /// @brief
    static constexpr char DEBUG_FORMAT[]{""};
    /// @brief
    /// @brief
    static constexpr char INFO_FORMAT[]{""};
    /// @brief String used when no format is necessary
    static constexpr char NO_FORMAT[]{""};
    /// @brief
    static constexpr char WARNING_FORMAT[]{""};

    /**
     * @brief Get level's string used in log's headers.
     *
     * @return String used for headers
     */
    const char *level_string(const ramrod::BaseHeaderless::Level level)
    {
        switch (level)
        {
        case ramrod::BaseHeaderless::Level::INFO:
            static constexpr char INFO_STRING[]{"[INFO]"};
            return INFO_STRING;
        case ramrod::BaseHeaderless::Level::DEBUG:
            static constexpr char DEBUG_STRING[]{"[DEBUG]"};
            return DEBUG_STRING;
        default:
            static constexpr char VERBOSE_STRING[]{"[VERBOSE]"};
            return VERBOSE_STRING;
        }
    }
} // Unnamed namespace

namespace ramrod
{
    BaseHeaderless::BaseHeaderless()
        : level_{},
          output_{},
          style_{NO_FORMAT}
    {
    }

    BaseHeaderless &BaseHeaderless::operator<<(const bool message)
    {
        output_ << message;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::int8_t message)
    {
        output_ << message;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::uint8_t message)
    {
        output_ << message;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::int8_t *message)
    {
        output_ << message;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::uint8_t *message)
    {
        output_ << message;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::int16_t message)
    {
        output_ << message;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::uint16_t message)
    {
        output_ << message;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::int32_t message)
    {
        output_ << message;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::uint32_t message)
    {
        output_ << message;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const float message)
    {
        output_ << message;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::int64_t message)
    {
        output_ << message;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::uint64_t message)
    {
        output_ << message;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const double message)
    {
        output_ << message;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const long double message)
    {
        output_ << message;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::string &message)
    {
        output_ << message;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::string_view &message)
    {
        output_ << message;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const void *message)
    {
        output_ << message;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::exception &message)
    {
        output_ << message;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::operator<<(const std::error_code &message)
    {
        output_ << message;
        return *this;
    }
} // namespace ramrod