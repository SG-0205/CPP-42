#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(const std::string &name)
    : ClapTrap(name), _name(name), _hit_points(100), _energy_points(50),
      _attack_damage(20) {
  _message("new ScavTrap named " + name);
}

ScavTrap::ScavTrap(const ScavTrap &other)
    : ClapTrap(other), _name(other._name), _hit_points(other._hit_points),
      _energy_points(other._energy_points),
      _attack_damage(other._attack_damage) {
  _message("new ScavTrap with " + other._getName() + " as base.");
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  _message("ScavTrap " + _getName() + " is copying " + other._getName());

  this->_hit_points = other._getPoints(HIT, &other);
  this->_attack_damage = other._getPoints(ATTACK_DMG, &other);
  this->_energy_points = other._getPoints(ENERGY, &other);
  this->_name = other._getName();

  return ((*this));
}

void ScavTrap::guardGate(void) {
  if (_getPoints(ENERGY, this) > 0 && _getPoints(HIT, this) > 0) {
    _message(_getName() + " is keeping the gate.");
  } else if (_getPoints(HIT, this) < 1) {
    _message(_getName() + " is out of hit points and couldn\'t keep the gate.");
  } else if (_getPoints(ENERGY, this) < 1) {
    _message(_getName() +
             " is out of energy points and couldn't keep the gate.");
  }
}

ScavTrap::~ScavTrap(void) {
  _message("ScavTrap " + _getName(), "has been destroyed.");
}
