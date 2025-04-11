/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operations.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:58:59 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/11 15:11:32 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed Fixed::operator+(const Fixed &other) const {
  Fixed new_number;
  int new_bits;

  new_bits = this->getRawBits() + other.getRawBits();
  new_number.setRawBits(new_bits);

  return (new_number);
}

Fixed Fixed::operator-(const Fixed &other) const {
  Fixed new_number;
  int new_bits;

  new_bits = this->getRawBits() - other.getRawBits();
  new_number.setRawBits(new_bits);

  return (new_number);
}

Fixed Fixed::operator*(const Fixed &other) const {
  Fixed new_number;
  int new_bits;

  new_bits = (this->getRawBits() * other.getRawBits()) >> _lenght;
  new_number.setRawBits(new_bits);

  return (new_number);
}

Fixed Fixed::operator/(const Fixed &other) const {
  if (other.getRawBits() == 0)
    throw std::exception();
  Fixed new_number;
  int new_bits;

  new_bits = (this->getRawBits() / other.getRawBits()) >> _lenght;
  new_number.setRawBits(new_bits);

  return (new_number);
}
