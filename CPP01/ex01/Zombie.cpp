/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:12:22 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/09 17:51:23 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie &Zombie::operator=(const Zombie &other) {
  this->_name = other._name;
  return (*this);
}

void Zombie::announce(void) {
  std::cout << _name << ":  BraiiiiiiinnnzzzZ..." << '\n';
}

void Zombie::setName(const std::string &name) {
  if (name.empty())
    throw std::invalid_argument("Zombie::setName: empty name.");
  _name = name;
}

Zombie::~Zombie(void) { std::cout << _name << " is gone forever." << '\n'; }
