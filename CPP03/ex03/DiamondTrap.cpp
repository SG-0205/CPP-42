#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name),
      _name(name), _hit_points(FragTrap::_hit_points),
      _energy_points(ScavTrap::_energy_points),
      _attack_damage(FragTrap::_energy_points) {}
