#include "ramrod/log/Error.hpp"

namespace ramrod
{
    // Error &error{Error::instance()};

    Error &Error::instance()
    {
        static Error object{};
        return object;
    }

    Error::Error()
        : Base{}
    {
    }
} // namespace ramrod