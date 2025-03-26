#include <iostream>

using namespace std;

class String
{
    char* data;
    size_t size;

public:
    /**
     * @brief Construct a new String object and it should have a default value of ""
     *
     */
    String() {
        data = new char[1];
        data[0] = '\0';
        size = 0;
    }

    /**
     * @brief Construct a new String object with the provided value
     *
     * @param str
     */
    String(const char* str) {
        size_t str_size = 0;
        for (int i = 0; str[i] != '/0'; i++) {
            str_size++;
        }
        this->data = new char[str_size + 1];
        for (int i = 0; i < str_size; i++) {
            this->data[i] = str[i];
        }
        this->data[str_size] = '\0';
        this->size = str_size;
    }

    /**
     * @brief Construct a new String object by copying another string
     *
     * @param other
     */
    String(const String& other) {
        this->size = other.size;
        this->data = new char[this->size + 1];
        for (int i = 0; i < this->size; i++) {
            this->data[i] = other.data[i];
        }
        this->data[this->size] = '\0';
    }

    /**
     * @brief Copies the values from the other string in this string
     *
     * @param other
     * @return String&
     */
    String& operator=(const String& other) {
        if (this != &other) {
            this->size = other.size;
            this->data = new char[this->size + 1];
            for (int i = 0; i < this->size; i++) {
                this->data[i] = other.data[i];
            }
            this->data[this->size] = '\0';
        }
    }

    /**
     * @brief Destroy the String object
     *
     */
    ~String() {
        delete[] this->data;
    }

    /**
     * @brief Returns the string as a C-style string - char*
     *
     * @return const char*
     */
    char* toCString() const {
        return this->data;
    }

    /**
     * @brief Returns the length of the string
     *
     * @return size_t
     */
    size_t length() const {
        return this->size;
    }
};