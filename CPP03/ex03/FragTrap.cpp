#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <ostream>

const std::string &FragTrap::_getName(void) const { return (this->_name); }
const int &FragTrap::_getPoints(const PointsType &type) const {
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
    throw std::invalid_argument("FragTrap::_getPoints: invalid point type.");
    break;
  }

  return (this->_hit_points);
}

void FragTrap::_incrementPoints(const PointsType &type) {
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

void FragTrap::_decrementPoints(const PointsType &type) {
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
        "FragTrap::_incrementPoints: invalid point type.");
    break;
  }
}

FragTrap::FragTrap(const std::string &name)
    : ClapTrap(name), _name(name), _hit_points(100), _energy_points(100),
      _attack_damage(30) {
  _message("new FragTrap named " + name);
}

FragTrap::FragTrap(const FragTrap &other)
    : ClapTrap(other), _name(other._getName()),
      _hit_points(other._getPoints(HIT)),
      _energy_points(other._getPoints(ENERGY)),
      _attack_damage(other._getPoints(ATTACK_DMG)) {
  _message("new FragTrap with " + other._getName() + " as base");
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  _message(_getName() + " is copying " + other._getName());

  this->_name = other._getName();
  this->_hit_points = other._getPoints(HIT);
  this->_energy_points = other._getPoints(ENERGY);
  this->_attack_damage = other._getPoints(ATTACK_DMG);

  return ((*this));
}

void FragTrap::highFivesGuys(void) {
  if (_getPoints(ENERGY) > 0 && _getPoints(HIT) > 0) {
    _message(_getName() + " is asking for a high five.");

    _decrementPoints(ENERGY);
  } else if (_getPoints(HIT) < 1) {
    _message(_getName() +
             " is out of hit points and couldn't ask for a high five.");
  } else if (_getPoints(ENERGY) < 1) {
    _message(_getName() +
             " is out of energy points and couldn't ask for a high five.");
  }
}

void FragTrap::printState(void) {
  std::cout << _getName() << std::endl;
  std::cout << "\tHIT_POINTS: " << _getPoints(HIT) << std::endl;
  std::cout << "\tENERGY_POINTS: " << _getPoints(ENERGY) << std::endl;
  std::cout << "\tATTACK_DAMAGE: " << _getPoints(ATTACK_DMG) << std::endl;
  std::cout << "------" << std::endl;
}

FragTrap::~FragTrap(void) {
  _message("FragTrap " + _getName() + " has been destroyed.");
}
