/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:11:01 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/10 13:30:31 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <stdexcept>
#include <string>

Weapon &Weapon::operator=(const Weapon &other) {
  if (this == &other)
    return (*this);

  this->_type = other._type;

  return (*this);
}

const std::string &Weapon::getType(void) { return (_type); }

void Weapon::setType(const std::string &type) {
  if (type.empty())
    throw std::invalid_argument("Weapon::setType: empty type.");

  _type = type;
}
