#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

const std::string &ScavTrap::_getName(void) const { return (this->_name); }
const int &ScavTrap::_getPoints(const PointsType &type) const {
  switch (type) {
  case (ATTACK_DMG):
    return (this->_attack_damage);
    break;
  case (ENERGY):
    return (this->_energy_points);
    break;
  case (HIT):
    return (this->_hit_points);
    break;
  default:
    throw std::invalid_argument("ClapTrap::_getPoints: invalid point type.");
    break;
  }

  return (this->_hit_points);
}

void ScavTrap::_incrementPoints(const PointsType &type) {
  switch (type) {
  case (ENERGY):
    this->_energy_points++;
    return;
    break;
  case (HIT):
    this->_hit_points++;
    return;
    break;
  case (ATTACK_DMG):
    this->_attack_damage++;
    return;
    break;
  default:
    throw std::invalid_argument(
        "ScavTrap_incrementPoints: invalid point type.");
    break;
  }
}

void ScavTrap::_decrementPoints(const PointsType &type) {
  switch (type) {
  case (ENERGY):
    this->_energy_points--;
    return;
    break;
  case (HIT):
    this->_hit_points--;
    return;
    break;
  case (ATTACK_DMG):
    this->_attack_damage--;
    return;
    break;
  default:
    throw std::invalid_argument(
        "ScavTrap::_incrementPoints: invalid point type.");
    break;
  }
}

ScavTrap::ScavTrap(const std::string &name)
    : ClapTrap(name), _name(name), _hit_points(100), _energy_points(50),
      _attack_damage(20) {
  _message("new ScavTrap named " + name);
}

ScavTrap::ScavTrap(const ScavTrap &other)
    : ClapTrap(other), _name(other._getName()),
      _hit_points(other._getPoints(HIT)),
      _energy_points(other._getPoints(ENERGY)),
      _attack_damage(other._getPoints(ATTACK_DMG)) {
  _message("new ScavTrap with " + other._getName() + " as base.");
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  _message("ScavTrap " + _getName() + " is copying " + other._getName());

  this->_hit_points = other._getPoints(HIT);
  this->_attack_damage = other._getPoints(ATTACK_DMG);
  this->_energy_points = other._getPoints(ENERGY);
  this->_name = other._getName();

  return ((*this));
}

void ScavTrap::guardGate(void) {
  if (_getPoints(ENERGY) > 0 && _getPoints(HIT) > 0) {
    _message(_getName() + " is keeping the gate.");
  } else if (_getPoints(HIT) < 1) {
    _message(_getName() + " is out of hit points and couldn\'t keep the gate.");
  } else if (_getPoints(ENERGY) < 1) {
    _message(_getName() +
             " is out of energy points and couldn't keep the gate.");
  }
}

void ScavTrap::printState(void) {
  std::cout << _getName() << std::endl;
  std::cout << "\tHIT_POINTS: " << _getPoints(HIT) << std::endl;
  std::cout << "\tENERGY_POINTS: " << _getPoints(ENERGY) << std::endl;
  std::cout << "\tATTACK_DAMAGE: " << _getPoints(ATTACK_DMG) << std::endl;
  std::cout << "------" << std::endl;
}

ScavTrap::~ScavTrap(void) {
  _message("ScavTrap " + _getName(), "has been destroyed.");
}
