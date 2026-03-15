#ifndef RAMROD_LOG_FILE_HPP
#define RAMROD_LOG_FILE_HPP

#include <filesystem>
#include <fstream>

namespace ramrod
{
class File
{
public:
    /**
     * @brief Constructor.
     *
     * The file is opened in append mode with the given path.
     *
     * @param filepath  The path to the file.
     */
    File(const std::filesystem::path& filepath);

    /** @brief Destructor
    *
    *  Closes the file and release the stream.
    */
    virtual ~File();

    /**
     * @brief Clear the file (truncates to zero size).
     */
    void clear();

    /**
     * @brief Close the file.
     */
    void close();

    /**
     * @brief Flush the file.
     */
    void flush();

    /**
     * @brief Open the file in append mode with the given path.
     *
     * If the file is already open, it is closed and reopened with the new path.
     *
     * @param filepath  The path to the file.
     *
     * @return True if the file was opened successfully, false otherwise.
     */
    bool open(const std::filesystem::path& filepath);

    /**
     * @brief Check if the file is open.
     *
     * @return True if the file is open, false otherwise.
     */
    bool is_open() const;

    /**
     * @brief Get the path to the file.
     *
     * @return The path to the file.
     */
    const std::filesystem::path& path() const;

    /**
     * @brief Write a boolean value to the file.
     *
     * @param message The boolean value to write.
     *
     * @return Reference to current object.
     */
    File& operator<<(const bool message);

    /**
     * @brief Write a character to the file.
     *
     * @param message The character to write.
     *
     * @return Reference to current object.
     */
    File& operator<<(const char message);

    /**
     * @brief Write an unsigned character to the file.
     *
     * @param message The unsigned character to write.
     *
     * @return Reference to current object.
     */
    File& operator<<(const unsigned char message);

    /**
     * @brief Write a null-terminated character string to the file.
     *
     * @param message The character string to write.
     *
     * @return Reference to current object.
     */
    File& operator<<(const char* message);

    /**
     * @brief Write a null-terminated unsigned character string to the file.
     *
     * @param message The unsigned character string to write.
     *
     * @return Reference to current object.
     */
    File& operator<<(const unsigned char* message);

    /**
     * @brief Write a short integer value to the file.
     *
     * @param message The short integer value to write.
     *
     * @return Reference to current object.
     */
    File& operator<<(const short message);

    /**
     * @brief Write an unsigned short integer value to the file.
     *
     * @param message The unsigned short integer value to write.
     *
     * @return Reference to current object.
     */
    File& operator<<(const unsigned short message);

    /**
     * @brief Write an integer value to the file.
     *
     * @param message The integer value to write.
     *
     * @return Reference to current object.
     */
    File& operator<<(const int message);

    /**
     * @brief Write an unsigned integer value to the file.
     *
     * @param message The unsigned integer value to write.
     *
     * @return Reference to current object.
     */
    File& operator<<(const unsigned int message);

    /**
     * @brief Write a float value to the file.
     *
     * @param message The float value to write.
     *
     * @return Reference to current object.
     */
    File& operator<<(const float message);

    /**
     * @brief Write a long integer value to the file.
     *
     * @param message The long integer value to write.
     *
     * @return Reference to current object.
     */
    File& operator<<(const long message);

    /**
     * @brief Write an unsigned long integer value to the file.
     *
     * @param message The unsigned long integer value to write.
     *
     * @return Reference to current object.
     */
    File& operator<<(const unsigned long message);

    /**
     * @brief Write a double value to the file.
     *
     * @param message The double value to write.
     *
     * @return Reference to current object.
     */
    File& operator<<(const double message);

    /**
     * @brief Write a long double value to the file.
     *
     * @param message The long double value to write.
     *
     * @return Reference to current object.
     */
    File& operator<<(const long double message);

    /**
     * @brief Write a long long integer value to the file.
     *
     * @param message The long long integer value to write.
     *
     * @return Reference to current object.
     */
    File& operator<<(const long long message);

    /**
     * @brief Write an unsigned long long integer value to the file.
     *
     * @param message The unsigned long long integer value to write.
     *
     * @return Reference to current object.
     */
    File& operator<<(const unsigned long long message);

    /**
     * @brief Write a pointer address to the file.
     *
     * @param message The pointer to write.
     *
     * @return Reference to current object.
     */
    File& operator<<(const void* message);

private:
    /// @brief The file stream.
    std::ofstream file_;
    /// @brief The path to the file.
    std::filesystem::path filepath_;
    /// @brief Whether the file is open.
    bool is_open_;
};
} // namespace ramrod

#endif // RAMROD_LOG_FILE_HPP
