/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:04:11 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 10:56:51 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <cerrno>
#include <iostream>
#include <ostream>
#include <stdexcept>

FragTrap::FragTrap(void) : ClapTrap() {
  std::cout << "Default constructor for FragTrap called." << std::endl;

  _hit_points = 100;
  _energy_points = 100;
  _attack_damage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
  if (name.empty())
    throw std::invalid_argument(
        "FragTrap::FragTrap(const std::string &) empty name.");

  std::cout << "[FRAG] Constructor called with name: " << _getName()
            << std::endl;
  _hit_points = 100;
  _energy_points = 100;
  _attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
  std::cout << "[FRAG] Copy constructor called with " << other._getName()
            << " as base." << std::endl;

  this->_name = other._getName();
  this->_hit_points = other._getPoints(HIT);
  this->_energy_points = other._getPoints(NRJ);
  this->_attack_damage = other._getPoints(ATK);
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  if (&other == this)
    return *this;

  std::cout << "[FRAG] Assignment operator called with " << other._getName()
            << " as base." << std::endl;

  this->_name = other._getName();
  this->_hit_points = other._getPoints(HIT);
  this->_energy_points = other._getPoints(NRJ);
  this->_attack_damage = other._getPoints(ATK);

  return (*this);
}

FragTrap::~FragTrap(void) {
  std::cout << "FragTrap " << _getName() << " has been destroyed." << std::endl;
}

void FragTrap::attack(const std::string &target) {
  if (target.empty())
    throw std::invalid_argument("FragTrap::attack: empty target.");

  const std::string &name(_getName());
  const int &attack_damage(_getPoints(ATK));

  if (!_isAlive())
    std::cout << "FragTrap " << name << " is dead and couldn't attack "
              << target;
  else if (!_isReady())
    std::cout << "FragTrap " << name
              << " is out of energy points and couldn't attack " << target;
  else {
    std::cout << "FragTrap " << name << " attacks " << target << ", causing "
              << attack_damage << " points of damage.";
    _decrementPoints(NRJ);
  }
  std::cout << std::endl;
}

void FragTrap::highFiveGuys(void) {
  const std::string &name(_getName());

  if (!_isAlive())
    std::cout << "FragTrap " << name
              << " is dead and couldn't ask for a high five :(";
  else if (!_isReady())
    std::cout << "FragTrap " << name
              << " is out of energy and couldn't ask for a high five.";
  else {
    std::cout << "FragTrap " << name << " is asking for a high five!";
    _decrementPoints(NRJ);
  }
  std::cout << std::endl;
}
