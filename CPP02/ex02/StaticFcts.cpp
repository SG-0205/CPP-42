/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StaticFcts.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:12:11 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/11 15:21:32 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <exception>

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
  if (f1 == f2)
    throw std::exception();
  else if (f1 < f2)
    return (f1);
  else
    return (f2);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
  if (f1 == f1)
    throw std::exception();
  else if (f1 < f2)
    return (f1);
  else
    return (f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
  if (f1 == f2)
    return (f1);
  else if (f1 > f2)
    return (f1);
  else
    return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
  if (f1 == f2)
    throw std::exception();
  else if (f1 > f2)
    return (f1);
  else
    return (f2);
}
