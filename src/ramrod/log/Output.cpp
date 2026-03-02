#include "ramrod/log/Output.hpp"

#include <iostream>

namespace ramrod
{
    bool Output::ok()
    {
        return true;
    }

    Output &Output::operator<<(const bool message)
    {
        std::cout << message;
        return *this;
    }

    Output &Output::operator<<(const std::int8_t message)
    {
        std::cout << message;
        return *this;
    }

    Output &Output::operator<<(const std::uint8_t message)
    {
        std::cout << message;
        return *this;
    }

    Output &Output::operator<<(const std::int8_t *message)
    {
        std::cout << message;
        return *this;
    }

    Output &Output::operator<<(const std::uint8_t *message)
    {
        std::cout << message;
        return *this;
    }

    Output &Output::operator<<(const std::int16_t message)
    {
        std::cout << message;
        return *this;
    }

    Output &Output::operator<<(const std::uint16_t message)
    {
        std::cout << message;
        return *this;
    }

    Output &Output::operator<<(const std::int32_t message)
    {
        std::cout << message;
        return *this;
    }

    Output &Output::operator<<(const std::uint32_t message)
    {
        std::cout << message;
        return *this;
    }

    Output &Output::operator<<(const float message)
    {
        std::cout << message;
        return *this;
    }

    Output &Output::operator<<(const std::int64_t message)
    {
        std::cout << message;
        return *this;
    }

    Output &Output::operator<<(const std::uint64_t message)
    {
        std::cout << message;
        return *this;
    }

    Output &Output::operator<<(const double message)
    {
        std::cout << message;
        return *this;
    }

    Output &Output::operator<<(const long double message)
    {
        std::cout << message;
        return *this;
    }

    Output &Output::operator<<(const std::string &message)
    {
        std::cout << message;
        return *this;
    }

    Output &Output::operator<<(const std::string_view &message)
    {
        std::cout << message;
        return *this;
    }

    Output &Output::operator<<(const void *message)
    {
        std::cout << message;
        return *this;
    }

    Output &Output::operator<<(const std::exception &message)
    {
        std::cout << message.what();
        return *this;
    }

    Output &Output::operator<<(const std::error_code &message)
    {
        std::cout << message.message();
        return *this;
    }
} // namespace ramrod
