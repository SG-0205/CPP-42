/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Incrementations.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:24:23 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/11 15:31:28 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <stdexcept>

Fixed Fixed::operator++(int) {
  Fixed pre_incr(*this);

  this->_value++;
  return (pre_incr);
}

Fixed Fixed::operator++(void) {
  this->_value++;
  return (*this);
}

Fixed Fixed::operator--(int) {
  Fixed pre_decr(*this);

  this->_value--;
  return (pre_decr);
}

Fixed Fixed::operator--(void) {
  this->_value--;
  return (*this);
}

// TODO verifier incrementations
