/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 21:35:05 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/11 21:48:09 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string &name)
    : ClapTrap(name), _name(ClapTrap::_name),
      _hit_points(ClapTrap::_hit_points),
      _energy_points(ClapTrap::_energy_points),
      _attack_damage(ClapTrap::_attack_damage) {
  std::cout << "ScavTrap " << name << " created." << std::endl;

  _hit_points = 100;
  _energy_points = 50;
  _attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other)
    : ClapTrap(other), _name(other._name), _hit_points(other._hit_points),
      _energy_points(other._energy_points),
      _attack_damage(other._attack_damage) {
  std::cout << "[SCAV] Copy constructor called with " << other._name
            << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  if (this == &other)
    return (*this);

  this->_name = other._name;
  this->_hit_points = other._hit_points;
  this->_energy_points = other._energy_points;
  this->_attack_damage = other._attack_damage;

  return (*this);
}

// TODO VERIFIER COPIE OBJET CLAPTRAP;
