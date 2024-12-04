#include "Fixed.hpp"
#include <iostream>
#include <ostream>

const int Fixed::_decimals_bit_count = 8;

void Fixed::_writeLog(Fixed::log_type type) const {
  switch (type) {
  case (DEF_CONSTRUCTOR):
    std::cout << "Default constructor called";
    break;
  case (COPY_CONSTRUCTOR):
    std::cout << "Copy constructor called";
    break;
  case (COPY_ASSIGNEMENT):
    std::cout << "Copy assignement operator called";
    break;
  case (GETRB):
    std::cout << "getRawBits member function called";
    break;
  case (SETRB):
    std::cout << "setRawBits member function called";
    break;
  case (DESTRUCTOR):
    std::cout << "Desctructor called";
    break;
  default:
    return;
  }
  std::cout << std::endl;
}

Fixed::Fixed() {
  _value = 0;
  _writeLog(DEF_CONSTRUCTOR);
}

Fixed::Fixed(Fixed const &other) {
  if (this != &other) {
    _writeLog(COPY_CONSTRUCTOR);
    this->operator=(other);
  }
}

void Fixed::operator=(const Fixed &other) {
  _writeLog(COPY_ASSIGNEMENT);
  this->_value = other.getRawBits();
}

int Fixed::getRawBits(void) const {
  _writeLog(GETRB);
  return (_value);
}

void Fixed::setRawBits(const int raw) {
  _writeLog(SETRB);
  _value = raw;
}

Fixed::~Fixed() { _writeLog(DESTRUCTOR); }
