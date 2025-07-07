#pragma once
#include <cstddef>
#include <iterator>
#include <stack>
template <typename DataType> class MutantStack : public std::stack<DataType> {
public:
  MutantStack(void) : std::stack<DataType>() {}
  MutantStack(const MutantStack &other) : std::stack<DataType>(other) {}
  MutantStack &operator=(const MutantStack &other) {
    if (this == &other)
      return (*this);

    std::stack<DataType>::operator=(other);

    return (*this);
  }
  ~MutantStack(void) {}

  class iterator {
  private:
    DataType *_ptr;

  public:
    typedef std::input_iterator_tag iterator_category;
    typedef DataType value_type;
    typedef DataType &reference;
    typedef DataType *pointer;
    typedef std::ptrdiff_t difference_type;

    iterator(DataType *ptr = 0) { _ptr = ptr; }
    reference operator*(void) const { return (*_ptr); }
    pointer operator->(void) const { return (_ptr); }
    iterator &operator++(void) {
      ++_ptr;
      return (*this);
    }
    iterator &operator++(int) {
      iterator tmp = *this;
      ++_ptr;
      return (*tmp);
    }
    iterator &operator--(void) {
      --_ptr;
      return (*this);
    }
    iterator &operator--(int) {
      iterator tmp = *this;
      --_ptr;
      return (*tmp);
    }

    bool operator==(const iterator &other) const {
      return (_ptr == other._ptr);
    }
    bool operator!=(const iterator &other) const {
      return (_ptr != other._ptr);
    }
  };

  iterator begin(void) { return (iterator(&(*(this->c.begin())))); };
  iterator end(void) { return (iterator(&(*(this->c.end())))); }
};
