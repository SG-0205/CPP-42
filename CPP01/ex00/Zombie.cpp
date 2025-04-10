/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:12:22 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/09 17:54:18 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <exception>
#include <iostream>

Zombie &Zombie::operator=(const Zombie &other) {
  this->_name = other._name;
  return (*this);
}

void Zombie::announce(void) {
  if (_name.empty())
    throw std::exception();
  std::cout << _name << ":  BraiiiiiiinnnzzzZ..." << '\n';
}

Zombie::~Zombie(void) { std::cout << _name << " is gone forever." << '\n'; }
