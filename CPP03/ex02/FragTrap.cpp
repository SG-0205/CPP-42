#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(const std::string &name)
    : ClapTrap(name), _name(ClapTrap::_name),
      _hit_points(ClapTrap::_hit_points),
      _energy_points(ClapTrap::_energy_points),
      _attack_damage(ClapTrap::_attack_damage) {
  _message("new FragTrap named " + name);

  _hit_points = 100;
  _energy_points = 100;
  _attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &other)
    : ClapTrap(other), _name(ClapTrap::_name),
      _hit_points(ClapTrap::_hit_points),
      _energy_points(ClapTrap::_energy_points),
      _attack_damage(ClapTrap::_attack_damage) {
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

FragTrap::~FragTrap(void) {
  _message("FragTrap " + _getName() + " has been destroyed.");
}
