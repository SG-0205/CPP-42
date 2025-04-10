#pragma once

#include "ClapTrap.hpp"

#include <string>

class ScavTrap : public ClapTrap {
private:
  std::string _name;
  int _hit_points;
  int _energy_points;
  int _attack_damage;

public:
  ScavTrap(const std::string &name);
  ScavTrap(const ScavTrap &other);
  ScavTrap &operator=(const ScavTrap &other);

  void guardGate(void);

  ~ScavTrap(void);
};
