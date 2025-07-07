#include "Span.hpp"
#include "colors.h"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>

Span::Span(void) : _reserved_size(0), _elem_count(0), _storage() {}

Span::Span(const unsigned int &span_size)
    : _reserved_size(span_size), _elem_count(0), _storage() {
  _storage.reserve(span_size);
}

Span::Span(const Span &other)
    : _reserved_size(other._GetReservedSize()),
      _elem_count(other._GetElementCount()), _storage(other._GetStorage()) {}

Span &Span::operator=(const Span &other) {
  if (this == &other)
    return (*this);

  this->_storage = other._GetStorage();
  this->_reserved_size = other._GetReservedSize();
  this->_elem_count = other._GetElementCount();

  return (*this);
}

Span::~Span(void) {}

const unsigned int &Span::_GetReservedSize(void) const {
  return (_reserved_size);
}

const unsigned int &Span::_GetElementCount(void) const { return (_elem_count); }

const std::vector<int> &Span::_GetStorage(void) const { return (_storage); }

std::vector<int> &Span::_getStorage(void) { return (_storage); }

void Span::addNumber(const int &to_add) {
  if (_GetElementCount() >= _GetReservedSize())
    throw std::runtime_error("Span::addNumber: this span is full.");

  _storage.push_back(to_add);
  _elem_count++;
}

void Span::addNumbers(std::vector<int>::const_iterator start,
                      std::vector<int>::const_iterator end) {
  if (start == end)
    return;

  while (start != end) {
    if (_GetElementCount() >= _GetReservedSize())
      throw std::runtime_error("Span::addNumbers: this span is full.");
    else
      addNumber(*start), start++;
  }
}

unsigned int Span::shortestSpan(void) {

  if (_GetStorage().size() < 2)
    throw std::runtime_error(
        "Span::shortestSpan: not enough data to make a span.");

  sort(_getStorage().begin(), _getStorage().end());

  unsigned int lowest = 0;
  unsigned int current_diff = 0;
  bool first_iteration = true;
  const std::vector<int> &data = _GetStorage();
  for (size_t i = 0; i < data.size() - 1; i++) {
    current_diff = abs(data[i + 1] - data[i]);
    if (first_iteration)
      lowest = current_diff, first_iteration = false;
    lowest = std::min(current_diff, lowest);
  }

  return (lowest);
}

unsigned int Span::longestSpan(void) const {
  if (_GetStorage().size() < 2)
    throw std::runtime_error(
        "Span::longestSpan: not enough data to make a span.");

  std::vector<int>::const_iterator first_elem = _GetStorage().begin();
  std::vector<int>::const_reverse_iterator last_elem = _GetStorage().rbegin();

  return (abs(*last_elem - *first_elem));
}

void Span::printContent(void) const {
  const size_t &nb_elements = _GetElementCount();
  const std::vector<int> &storage = _GetStorage();
  std::cout << YELLOW << "Span Content:\n" RESET;
  for (size_t i = 0; i < storage.size(); i++)
    std::cout << '\t' << '[' << i << '/' << nb_elements - 1 << "]\t"
              << storage[i] << '\n';
}
