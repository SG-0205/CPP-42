/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 21:28:33 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/11 21:34:55 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
  std::string &_name;
  int &_hit_points;
  int &_energy_points;
  int &_attack_damage;

public:
  ScavTrap(const std::string &name);
  ScavTrap(const ScavTrap &other);
  ScavTrap &operator=(const ScavTrap &other);
  ~ScavTrap(void);

  void attack(unsigned int amount);
  void guardGate(void);
};
