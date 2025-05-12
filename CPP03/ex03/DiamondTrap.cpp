/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:05:41 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 11:24:02 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <ostream>
#include <stdexcept>

DiamondTrap::DiamondTrap(void)
    : ClapTrap("Default_clap_name"), _name("Default") {
  std::cout << "Default constructor for DiamondTrap called." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name),
      _name(name) {
  if (name.empty())
    throw std::invalid_argument(
        "DiamondTrap::DiamondTrap(const std::string &): empty name.");

  std::cout << "[DIAMOND] Constructor called with " << name << " as name."
            << std::endl;

  this->_hit_points = 100;
  this->_energy_points = 50;
  this->_attack_damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other) {
  std::cout << "[DIAMOND] Copy constructor called with " << other._name
            << " as base." << std::endl;

  this->_name = other._name;
  ClapTrap::_name = other._getName();
  this->_hit_points = other._hit_points;
  this->_energy_points = other._energy_points;
  this->_attack_damage = other._attack_damage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  if (this == &other)
    return (*this);

  this->_name = other._name;
  ClapTrap::_name = other._getName();
  this->_hit_points = other._hit_points;
  this->_energy_points = other._energy_points;
  this->_attack_damage = other._attack_damage;

  return (*this);
}

void DiamondTrap::whoAmI(void) {
  std::cout << '<' << this->_name << ">: \"My name is " << DiamondTrap::_name
            << '\"' << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
  ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap(void) {
  std::cout << "DiamondTrap " << _name << " has been destroyed." << std::endl;
}
