#pragma once

#include <cstddef>
#include <stdexcept>
template <typename T> class Array {
private:
  size_t _allocated_size;
  T *_memory_address;

public:
  Array(void) : _allocated_size(0), _memory_address(NULL) {}

  Array(const unsigned int &n)
      : _allocated_size(n), _memory_address(new T[n]) {}

  Array(const Array &other) {

    this->_allocated_size = other.size();
    this->_memory_address = new T[size()];

    for (size_t i = 0; i < size(); i++)
      _memory_address[i] = other._memory_address[i];
  }

  Array &operator=(const Array &other) {
    if (this == &other)
      return (*this);

    if (this->size() > 0)
      delete[] this->_memory_address;
    this->_allocated_size = other.size();
    this->_memory_address = new T[this->size()];

    for (size_t i = 0; i < size(); i++)
      _memory_address[i] = other._memory_address[i];

    return (*this);
  }

  ~Array(void) { delete[] _memory_address; };

  T &operator[](const size_t &id) {
    if (id >= size())
      throw std::invalid_argument("Array::operator[]: out of bound id.");

    return (_memory_address[id]);
  }
  const size_t &size(void) const { return (_allocated_size); }
};
