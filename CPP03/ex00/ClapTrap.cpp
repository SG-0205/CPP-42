#include "ClapTrap.hpp"
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>

static std::string to_string(const int &value) {
  std::stringstream buff;
  buff << value;

  return (buff.str());
}

void ClapTrap::_message(const std::string &message) {
  std::cout << message << std::endl;
}

const std::string &ClapTrap::_getName(void) const { return (_name); }
const int &ClapTrap::_getPoints(const PointsType &type) const {
  switch (type) {
  case (ATTACK_DMG):
    return (_attack_damage);
    break;
  case (ENERGY):
    return (_energy_points);
    break;
  case (HIT):
    return (_hit_points);
    break;
  default:
    throw std::invalid_argument("ClapTrap::_getPoints: invalid point type.");
    break;
  }

  return (_hit_points);
}

void ClapTrap::_incrementPoints(const PointsType &type) {
  switch (type) {
  case (ENERGY):
    _energy_points++;
    return;
    break;
  case (HIT):
    _hit_points++;
    return;
    break;
  case (ATTACK_DMG):
    _attack_damage++;
    return;
    break;
  default:
    throw std::invalid_argument(
        "ClapTrap::_incrementPoints: invalid point type.");
    break;
  }
}

void ClapTrap::_decrementPoints(const PointsType &type) {
  switch (type) {
  case (ENERGY):
    _energy_points--;
    return;
    break;
  case (HIT):
    _hit_points--;
    return;
    break;
  case (ATTACK_DMG):
    _attack_damage--;
    return;
    break;
  default:
    throw std::invalid_argument(
        "ClapTrap::_incrementPoints: invalid point type.");
    break;
  }
}

ClapTrap::ClapTrap(const std::string &name)
    : _name(name), _attack_damage(0), _hit_points(10), _energy_points(10) {
  _message(std::string("new ClapTrap called " + _getName()));
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : _name(other._getName()), _hit_points(other._getPoints(HIT)),
      _energy_points(other._getPoints(ENERGY)),
      _attack_damage(other._getPoints(ATTACK_DMG)) {
  _message(std::string("New ClapTrap with " + other._getName() + " as base."));
};

ClapTrap &ClapTrap::operator[](const ClapTrap &other) {
  this->_name = other._getName();
  this->_hit_points = other._getPoints(HIT);
  this->_energy_points = other._getPoints(ENERGY);
  this->_attack_damage = other._getPoints(ATTACK_DMG);

  _message(std::string("ClapTrap " + _getName() + " is copying " +
                       other._getName()));

  return (*this);
}

void ClapTrap::attack(const std::string &target) {
  if (_getPoints(ENERGY) > 0 && _getPoints(HIT)) {
    _message(std::string("ClapTrap " + _getName() + " attacks " + target +
                         ", causing " + to_string(_getPoints(ATTACK_DMG)) +
                         " points of damage!"));

    _decrementPoints(ENERGY);
  } else if (_getPoints(ENERGY) <= 0) {
    _message(std::string("ClapTrap " + _getName() +
                         " is out of energy and couldn\t attack " + target));
  } else if (_getPoints(HIT) <= 0) {
    _message(std::string("ClapTrap " + _getName() +
                         " is out of hit points and couldn\'t attack " +
                         target));
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_getPoints(ENERGY) > 0 && _getPoints(HIT) > 0) {
    _message(std::string("ClapTrap " + _getName() +
                         " has been repaired and regained " +
                         to_string(amount) + " hit points."));

    _decrementPoints(ENERGY);
  } else if (_getPoints(ENERGY) <= 0) {
    _message(std::string("ClapTrap " + _getName() +
                         " is out of energy and couldn\t be repaired."));
  } else if (_getPoints(HIT) <= 0) {
    _message(std::string("ClapTrap " + _getName() +
                         " is out of hit points and couldn\'t be repaired."));
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_getPoints(HIT) > 0) {
    _message("ClapTrap " + _getName() + " took " + to_string(amount) +
             " damage points.");

    while (amount-- > 0)
      _decrementPoints(HIT);
  } else {
    _message(std::string("ClapTrap " + _getName() +
                         " is already dead and can't take any more damage."));
  }
}

ClapTrap::~ClapTrap(void) {}
