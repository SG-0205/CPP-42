#include "Fixed.hpp"
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <stdexcept>

const int Fixed::_bit_scale = 8;

std::ostream &operator<<(std::ostream &output, const Fixed &number) {
  int raw_bits = number.getRawBits();
  int scale_factor = number.getScaleFactor();

  std::cout << '\n' << number.getRawBits() << '\n';
  output << (raw_bits / scale_factor +
             ((raw_bits % scale_factor) / scale_factor));
  return (output);
}

bool Fixed::operator>(const Fixed &n2) const {
  Fixed n1 = *this;
  int n1_bits, n2_bits;
  n1_bits = n1.getRawBits();
  n2_bits = n2.getRawBits();

  return (n1_bits > n2_bits);
}

bool Fixed::operator<(const Fixed &n2) const {
  Fixed n1 = *this;
  int n1_bits, n2_bits;
  n1_bits = n1.getRawBits();
  n2_bits = n2.getRawBits();

  return (n1_bits < n2_bits);
}

bool Fixed::operator>=(const Fixed &n2) const {
  Fixed n1 = *this;

  int n1_bits, n2_bits;
  n1_bits = n1.getRawBits();
  n2_bits = n2.getRawBits();

  return (n1_bits >= n2_bits);
}

bool Fixed::operator<=(const Fixed &n2) const {
  Fixed n1 = *this;

  int n1_bits, n2_bits;
  n1_bits = n1.getRawBits();
  n2_bits = n2.getRawBits();

  return (n1_bits <= n2_bits);
}

bool Fixed::operator==(const Fixed &n2) const {
  Fixed n1 = *this;

  int n1_bits, n2_bits;
  n1_bits = n1.getRawBits();
  n2_bits = n2.getRawBits();

  return (n1_bits == n2_bits);
}

bool Fixed::operator!=(const Fixed &n2) const {
  Fixed n1 = *this;

  int n1_bits, n2_bits;
  n1_bits = n1.getRawBits();
  n2_bits = n2.getRawBits();

  return (n1_bits != n2_bits);
}

int Fixed::operator+(const Fixed &n2) {
  return ((getRawBits() + n2.getRawBits()) / _scale_factor());
}

int Fixed::operator-(const Fixed &n2) {
  return ((getRawBits() - n2.getRawBits()) / _scale_factor());
}

int Fixed::operator*(const Fixed &n2) {
  return ((getRawBits() * n2.getRawBits()) / (_scale_factor()));
}

int Fixed::operator/(const Fixed &n2) {
  return ((getRawBits() / n2.getRawBits()) / (_scale_factor() * 2));
}

Fixed &Fixed::operator++(void) {
  int current_value = getRawBits();

  current_value += 1 / _scale_factor();
  setRawBits(current_value);
  return (*this);
}

Fixed &Fixed::operator--(void) {
  int current_value = getRawBits();

  current_value -= 1 / _scale_factor();
  setRawBits(current_value);
  return (*this);
}

Fixed Fixed::operator++(int) {
  int current_value = getRawBits();

  current_value += 1 / _scale_factor();
  setRawBits(current_value);
  return (Fixed(current_value - 1 / _scale_factor()));
}

Fixed Fixed::operator--(int) {
  int current_value = getRawBits();

  current_value -= 1 / _scale_factor();
  setRawBits(current_value);
  return (Fixed(current_value + 1 / _scale_factor()));
}

Fixed &Fixed::min(Fixed &n1, Fixed &n2) {
  if (n1 < n2)
    return (n1);
  else
    return (n2);
}

const Fixed &Fixed::min(const Fixed &n1, const Fixed &n2) {
  if (n1 < n2)
    return (n1);
  else
    return (n2);
}

Fixed &Fixed::max(Fixed &n1, Fixed &n2) {
  if (n1 > n2)
    return (n1);
  else
    return (n2);
}

const Fixed &Fixed::max(const Fixed &n1, const Fixed &n2) {
  if (n1 > n2)
    return (n1);
  else
    return (n2);
}

void Fixed::_writeLog(Fixed::log_type type) const {
  switch (type) {
  case (DEF_CONSTRUCTOR):
    std::cout << "Default constructor called";
    break;
  case (INT_CONSTRUCTOR):
    std::cout << "Int constructor called";
    break;
  case (FLOAT_CONSTRUCTOR):
    std::cout << "Float constructor called";
    break;
  case (COPY_CONSTRUCTOR):
    std::cout << "Copy constructor called";
    break;
  case (COPY_ASSIGNEMENT):
    std::cout << "Copy assignement operator called";
    break;
  case (DESTRUCTOR):
    std::cout << "Desctructor called";
    break;
  default:
    return;
  }
  std::cout << std::endl;
}

int Fixed::_scale_factor(void) const {
  int result = 2;
  int limit = _bit_scale;

  while (limit-- > 0)
    result *= 2;

  return (result);
}

int Fixed::getScaleFactor(void) const { return (_scale_factor()); }

Fixed::Fixed() {
  _value = 0;
  _writeLog(DEF_CONSTRUCTOR);
}

Fixed::Fixed(const int to_convert) {
  if (to_convert * _scale_factor() >= INT_MAX ||
      to_convert * _scale_factor() <= INT_MIN)
    throw std::invalid_argument("Fixed(int to_convert): to_convert would "
                                "overflow/underflow if converted.");
  else
    _value = _scale_factor() * to_convert;
  _writeLog(INT_CONSTRUCTOR);
}

Fixed::Fixed(const float to_convert) {
  if (to_convert * _scale_factor() >= INT_MAX ||
      to_convert * _scale_factor() <= INT_MIN)
    throw std::invalid_argument("Fixed(float to_convert): to_convert would "
                                "overflow/underflow if converted.");
  else
    _value = _scale_factor() * to_convert;
  _writeLog(FLOAT_CONSTRUCTOR);
}

Fixed::Fixed(Fixed const &other) {
  if (this != &other) {
    _writeLog(COPY_CONSTRUCTOR);
    this->operator=(other);
  }
}

void Fixed::operator=(const Fixed &other) {
  _writeLog(COPY_ASSIGNEMENT);
  setRawBits(other.getRawBits());
}

float Fixed::toFloat(void) const { return (_value / _scale_factor()); }

int Fixed::toInt(void) const { return (_value / _scale_factor()); }

int Fixed::getRawBits(void) const { return (_value); }

void Fixed::setRawBits(const int raw) { _value = raw; }

Fixed::~Fixed() { _writeLog(DESTRUCTOR); }
