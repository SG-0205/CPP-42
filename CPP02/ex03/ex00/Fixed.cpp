#include "Fixed.hpp"

const int Fixed::_decimals_bit_count = 8;

Fixed::Fixed() { _value = 0; }

Fixed::Fixed(const Fixed &other) {
  if (this != &other)
    _value = other._value;
}

int Fixed::getRawBits(void) { return (_value); }

void Fixed::setRawBits(const int raw) { _value = raw; }

Fixed::~Fixed() {}
