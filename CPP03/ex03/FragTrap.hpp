#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
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
  FragTrap(const std::string &name);
  FragTrap(const FragTrap &other);
  FragTrap &operator=(const FragTrap &other);

  void highFivesGuys(void);
  void printState(void);

  ~FragTrap(void);
};
