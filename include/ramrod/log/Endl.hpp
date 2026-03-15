#ifndef RAMROD_LOG_ENDL_HPP
#define RAMROD_LOG_ENDL_HPP

namespace ramrod
{
/**
 * @brief Object that represents a newline.
 */
class Endl
{
public:
    /**
     * @brief Creates a newline object.
     */
    Endl() = default;

    /**
     * @brief Default destructor.
     */
    virtual ~Endl() = default;
};

/**
 * @brief Global newline object.
 */
extern const Endl endl;
} // namespace ramrod

#endif // RAMROD_LOG_ENDL_HPP
