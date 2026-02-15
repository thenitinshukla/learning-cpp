#include <iostream>
#include <cstddef>
#include <utility>

struct vector {
private:
    int* m_data;
    std::size_t m_size;
    std::size_t m_capacity;

public:
    // Default constructor
    vector() : m_data(nullptr), m_size(0), m_capacity(0) {}

    // Constructor with initial size
    vector(std::size_t size)
        : m_data(new int[size]), m_size(size), m_capacity(size) {}

    // Destructor
    ~vector() {
        delete[] m_data;
    }

    // Copy constructor
    vector(const vector& other)
        : m_data(new int[other.m_capacity]),
          m_size(other.m_size),
          m_capacity(other.m_capacity)
    {
        for (std::size_t i = 0; i < m_size; ++i)
            m_data[i] = other.m_data[i];
    }

    // Move constructor
    vector(vector&& other) noexcept
        : m_data(other.m_data),
          m_size(other.m_size),
          m_capacity(other.m_capacity)
    {
        other.m_data = nullptr;
        other.m_size = 0;
        other.m_capacity = 0;
    }

    // Copy assignment
    vector& operator=(const vector& other) {
        if (this == &other) return *this;

        delete[] m_data;

        m_capacity = other.m_capacity;
        m_size = other.m_size;
        m_data = new int[m_capacity];

        for (std::size_t i = 0; i < m_size; ++i)
            m_data[i] = other.m_data[i];

        return *this;
    }

    // Move assignment
    vector& operator=(vector&& other) noexcept {
        if (this == &other) return *this;

        delete[] m_data;

        m_data = other.m_data;
        m_size = other.m_size;
        m_capacity = other.m_capacity;

        other.m_data = nullptr;
        other.m_size = 0;
        other.m_capacity = 0;

        return *this;
    }

    // Element access
    int& operator[](std::size_t i) {
        return m_data[i];
    }

    const int& operator[](std::size_t i) const {
        return m_data[i];
    }

    // Add element
    void push_back(int value) {
        if (m_size >= m_capacity)
            reserve(m_capacity == 0 ? 1 : m_capacity * 2);

        m_data[m_size++] = value;
    }

    // Reserve capacity
    void reserve(std::size_t new_capacity) {
        if (new_capacity <= m_capacity)
            return;

        int* new_data = new int[new_capacity];

        for (std::size_t i = 0; i < m_size; ++i)
            new_data[i] = m_data[i];

        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }

    std::size_t size() const { return m_size; }
    std::size_t capacity() const { return m_capacity; }
};

int main() {
    vector v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (std::size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << '\n';
}


