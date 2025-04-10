#pragma once

#include "ClapTrap.hpp"

#include <string>

class ScavTrap : virtual public ClapTrap {
protected:
  std::string _name;
  int _hit_points;
  int _energy_points;
  int _attack_damage;

  const std::string &_getName(void) const;
  const int &_getPoints(const PointsType &type) const;
  void _incrementPoints(const PointsType &type);
  void _decrementPoints(const PointsType &type);

public:
  ScavTrap(const std::string &name);
  ScavTrap(const ScavTrap &other);
  ScavTrap &operator=(const ScavTrap &other);

  void guardGate(void);
  void printState(void);

  ~ScavTrap(void);
};
