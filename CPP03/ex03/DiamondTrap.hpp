#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
  const std::string &_name;
  int &_hit_points;
  int &_energy_points;
  int &_attack_damage;

public:
  DiamondTrap(const std::string &name);
  DiamondTrap(const DiamondTrap &other);
  DiamondTrap &operator=(const DiamondTrap &other);

  void attack(void);

  ~DiamondTrap(void);
};
// TODO se renseigner plus sur ce truc de merde de virtual
