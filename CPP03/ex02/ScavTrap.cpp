/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 21:35:05 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 10:49:47 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
  std::cout << "ScavTrap " << name << " created." << std::endl;

  _hit_points = 100;
  _energy_points = 50;
  _attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
  std::cout << "[SCAV] Copy constructor called with " << other._name
            << std::endl;

  this->_name = other._getName();
  this->_hit_points = other._getPoints(HIT);
  this->_energy_points = other._getPoints(NRJ);
  this->_attack_damage = other._getPoints(ATK);
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  if (this == &other)
    return (*this);

  std::cout << "ScavTrap " << _getName() << " is copying " << other._getName()
            << std::endl;
  this->_name = other._getName();
  this->_hit_points = other._getPoints(HIT);
  this->_energy_points = other._getPoints(NRJ);
  this->_attack_damage = other._getPoints(ATK);

  return (*this);
}

void ScavTrap::attack(const std::string &target) {
  const std::string &name(_getName());
  const int &attack_damage(_getPoints(ATK));

  if (!_isAlive())
    std::cout << "ScavTrap " << name << " is dead and couldn't attack"
              << target;
  else if (!_isReady())
    std::cout << "ScavTrap " << name << " is out of energy and couldn't attack "
              << target;
  else {
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing"
              << attack_damage << " damage points.";
    _decrementPoints(NRJ);
  }
  std::cout << std::endl;
}

void ScavTrap::guardGate(void) {
  const std::string &name(_getName());

  if (!_isAlive())
    std::cout << "ScavTrap " << name << " is dead and couldn't keep the gate.";
  else if (!_isReady())
    std::cout << "ScavTrap " << name
              << " is out of energy and couldn't guard the gate.";
  else {
    std::cout << "ScavTrap " << name << " is guarding the gate.";
    _decrementPoints(NRJ);
  };
  std::cout << std::endl;
}

ScavTrap::~ScavTrap(void) {
  std::cout << "ScavTrap " << _getName() << " has been destroyed." << std::endl;
}
