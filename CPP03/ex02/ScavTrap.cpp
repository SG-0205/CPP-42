#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(const std::string &name)
    : ClapTrap(name), _name(ClapTrap::_name),
      _hit_points(ClapTrap::_hit_points),
      _energy_points(ClapTrap::_energy_points),
      _attack_damage(ClapTrap::_attack_damage) {
  _message("new ScavTrap named " + name);

  _hit_points = 100;
  _energy_points = 50;
  _attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other)
    : ClapTrap(other), _name(ClapTrap::_name),
      _hit_points(ClapTrap::_hit_points),
      _energy_points(ClapTrap::_energy_points),
      _attack_damage(ClapTrap::_attack_damage) {
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

ScavTrap::~ScavTrap(void) {
  _message("ScavTrap " + _getName(), "has been destroyed.");
}
