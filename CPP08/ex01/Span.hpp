#pragma once

#include <vector>

class Span {
private:
  unsigned int _reserved_size;
  unsigned int _elem_count;
  std::vector<int> _storage;

  const unsigned int &_GetReservedSize(void) const;
  const std::vector<int> &_GetStorage(void) const;
  std::vector<int> &_getStorage(void);
  const unsigned int &_GetElementCount(void) const;

public:
  Span(void);
  Span(const unsigned int &span_size);
  Span(const Span &other);
  Span &operator=(const Span &other);
  ~Span(void);

  void addNumber(const int &to_add);
  void addNumbers(std::vector<int>::const_iterator start,
                  std::vector<int>::const_iterator end);
  unsigned int shortestSpan(void);
  unsigned int longestSpan(void) const;

  void printContent(void) const;
};
