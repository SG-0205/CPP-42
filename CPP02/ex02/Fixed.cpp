/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:56:01 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/11 15:21:53 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <ostream>

std::ostream &operator<<(std::ostream &outstream, const Fixed &fixed_nb) {
  outstream << fixed_nb.toFloat();

  return (outstream);
}

const int Fixed::_lenght = 8;

Fixed::Fixed(void) : _value(0) {}

Fixed::Fixed(const int to_store) : _value(to_store << _lenght) {}

Fixed::Fixed(const float to_store)
    : _value(static_cast<int>(roundf(to_store * (1 << _lenght)))) {}

Fixed::Fixed(const Fixed &other) { *this = other; }

Fixed &Fixed::operator=(const Fixed &other) {
  if (this == &other)
    return (*this);

  this->_value = other.getRawBits();

  return (*this);
}

int Fixed::getRawBits(void) const { return (_value); }

void Fixed::setRawBits(int const raw) { _value = raw; }

float Fixed::toFloat(void) const {
  return (static_cast<float>(_value) / (1 << _lenght));
}

int Fixed::toInt(void) const { return (_value >> _lenght); }

Fixed::~Fixed(void) {}
