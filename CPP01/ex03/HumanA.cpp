/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:01:24 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/10 13:06:56 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>
#include <ostream>

HumanA &HumanA::operator=(const HumanA &other) {
  if (this == &other)
    return (*this);

  this->_name = other._name;
  this->_weapon = other._weapon;

  return (*this);
}

void HumanA::attack(void) {
  std::cout << _name << " attacks with their " << _weapon.getType()
            << std::endl;
}
