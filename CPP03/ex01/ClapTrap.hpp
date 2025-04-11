/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:41:48 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/11 21:37:14 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ClapTrap {
protected:
  enum pointsType {
    HIT,
    NRJ,
    ATK,
  };

  std::string _name;
  int _hit_points;
  int _energy_points;
  int _attack_damage;

  bool _isAlive(void) const;
  bool _isReady(void) const;

  void _incrementPoints(const pointsType &type);
  void _decrementPoints(const pointsType &type);

  const std::string &_getName(void) const;
  const int &_getPoints(const pointsType &type) const;

public:
  ClapTrap(const std::string &name);
  ClapTrap(const ClapTrap &other);
  ClapTrap &operator=(const ClapTrap &other);
  ~ClapTrap() {}

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  void printState(void);
};
