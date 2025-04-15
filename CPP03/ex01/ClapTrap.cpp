/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:46:59 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 10:44:51 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <stdexcept>

const std::string &ClapTrap::_getName(void) const { return (_name); }
const int &ClapTrap::_getPoints(const pointsType &type) const {
  switch (type) {
  case (HIT):
    return (_hit_points);
    break;
  case (NRJ):
    return (_energy_points);
    break;
  case (ATK):
    return (_attack_damage);
    break;
  default:
    throw std::invalid_argument(
        "ClapTrap::_decrementPoints: invalid point type.");
    break;
  }
}

void ClapTrap::_decrementPoints(const pointsType &type) {
  switch (type) {
  case (HIT):
    _hit_points--;
    break;
  case (NRJ):
    _energy_points--;
    break;
  case (ATK):
    _energy_points--;
    break;
  default:
    throw std::invalid_argument(
        "ClapTrap::_decrementPoints: invalid point type.");
    break;
  }
}

void ClapTrap::_incrementPoints(const pointsType &type) {
  switch (type) {
  case (HIT):
    _hit_points++;
    break;
  case (NRJ):
    _energy_points++;
    break;
  case (ATK):
    _energy_points++;
    break;
  default:
    throw std::invalid_argument(
        "ClapTrap::_incrementPoints: invalid point type.");
    break;
  }
}

bool ClapTrap::_isAlive(void) const {
  if (_hit_points > 0)
    return (true);
  else
    return (false);
}

bool ClapTrap::_isReady(void) const {
  if (_energy_points > 0)
    return (true);
  else
    return (false);
}

ClapTrap::ClapTrap(void)
    : _name("Default"), _hit_points(10), _energy_points(10), _attack_damage(0) {
  std::cout << "Default ClapTrap constructor called." << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
    : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
  std::cout << "ClaptTrap " << _name << " has been created." << '\n';
}
ClapTrap::ClapTrap(const ClapTrap &other)
    : _name(other._name), _hit_points(other._hit_points),
      _energy_points(other._energy_points),
      _attack_damage(other._attack_damage) {
  std::cout << "Copy constructor called with " << other._name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  if (this == &other)
    return (*this);

  std::cout << "Assignment operator called." << std::endl;

  this->_name = other._name;
  this->_hit_points = other._hit_points;
  this->_energy_points = other._energy_points;
  this->_attack_damage = other._attack_damage;

  return (*this);
}

void ClapTrap::attack(const std::string &target) {
  if (target.empty())
    throw std::invalid_argument("ClapTrap::attack: empty target.");

  const std::string &name(_getName());
  const int &attack_points(_getPoints(ATK));

  if (!_isAlive())
    std::cout << "ClapTrap " << name << " is out of life and couldn't attack.";
  else if (!_isReady())
    std::cout << "ClaptTrap " << name
              << " is out of energy and couldn't attack.";
  else {
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
              << attack_points << " points of damage!\n";
    _decrementPoints(NRJ);
  }
  std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  const std::string &name(_getName());
  const int &hit_points(_getPoints(HIT));

  if (!_isAlive())
    std::cout << "ClapTrap " << name
              << " is already dead and couldn't take more damage.";
  else {
    std::cout << "ClapTrap " << name << " took " << amount
              << " points of damage.";
    for (; amount > 0 && hit_points > 0; amount--)
      _decrementPoints(HIT);
    _decrementPoints(NRJ);
  }
  std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  const std::string &name(_getName());

  if (!_isAlive())
    std::cout << "ClapTrap " << name
              << " is already dead and couldn't be repaired.";
  else if (!_isReady())
    std::cout << "ClapTrap " << name
              << " is out of energy and couldn't be repaired.";
  else {
    std::cout << "ClapTrap " << name << " has repaired and regained " << amount
              << " hit points.";
    for (; amount > 0; amount--)
      _incrementPoints(HIT);
    _decrementPoints(NRJ);
  }
  std::cout << std::endl;
}

void ClapTrap::printState(void) {
  const int &hit_points(_getPoints(HIT)), &energy_points(_getPoints(NRJ)),
      &attack_damage(_getPoints(ATK));
  const std::string &name(_getName());

  std::cout << "----STATE FOR CLAPTRAP " << name << "----" << '\n'
            << "HIT_POINTS: " << hit_points << '\n'
            << "ENERGY: " << energy_points << '\n'
            << "DAMAGE POINTS: " << attack_damage << '\n'
            << std::endl;
}

ClapTrap::~ClapTrap(void) {
  std::cout << "ClapTrap " << _getName() << " has been destroyed." << std::endl;
}
