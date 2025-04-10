#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
private:
  std::string &_name;
  int &_hit_points;
  int &_energy_points;
  int &_attack_damage;

public:
  FragTrap(const std::string &name);
  FragTrap(const FragTrap &other);
  FragTrap &operator=(const FragTrap &other);

  void highFivesGuys(void);

  ~FragTrap(void);
};
