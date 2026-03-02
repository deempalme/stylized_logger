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
    static constexpr char ERROR_FORMAT[]{""};
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
        case ramrod::BaseHeaderless::Level::WARNING:
            static constexpr char WARNING_STRING[]{"[WARNING]"};
            return WARNING_STRING;
        case ramrod::BaseHeaderless::Level::ERROR:
            static constexpr char ERROR_STRING[]{"[ERROR]"};
            return ERROR_STRING;
        default:
            static constexpr char VERBOSE_STRING[]{"[VERBOSE]"};
            return VERBOSE_STRING;
        }
    }
} // Unnamed namespace

namespace ramrod
{
    BaseHeaderless &BaseHeaderless::header()
    {
        // Adding date and time
        const std::time_t t{std::time(nullptr)};
        output_ << style_ << std::put_time(std::localtime(&t), "[%Y-%m-%d %H:%M:%S]")
                << level_string(level_) << CLEAR_FORMAT;
        return *this;
    }

    BaseHeaderless &BaseHeaderless::header(const char *filepath, const int line)
    {
        /// @brief Character that should be placed after file and line strings
        static constexpr char FILE_BEGIN[]{"["};
        /// @brief Character that should be placed after file and line strings
        static constexpr char FILE_END[]{"]"};
        /// @brief Separator character for filepath and line
        static constexpr char FILE_SEPARATOR[]{":"};
        header() << style_ << FILE_BEGIN << filepath << FILE_SEPARATOR << line
                 << FILE_END << CLEAR_FORMAT;
        return *this;
    }

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