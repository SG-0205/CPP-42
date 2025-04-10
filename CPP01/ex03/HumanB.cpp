/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:10:03 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/10 13:32:17 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <exception>
#include <iostream>
#include <ostream>

HumanB &HumanB::operator=(const HumanB &other) {
  if (this == &other)
    return (*this);

  this->_weapon = other._weapon;
  this->_name = other._name;

  return (*this);
}

void HumanB::attack(void) {
  if (!_weapon)
    throw std::exception();

  std::cout << _name << " attacks with their " << _weapon->getType()
            << std::endl;
}

void HumanB::setWeapon(Weapon &new_weapon) {
  if (&new_weapon == _weapon)
    return;

  _weapon = &new_weapon;
}
