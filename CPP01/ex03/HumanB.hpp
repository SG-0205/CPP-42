/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:07:17 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/10 13:30:31 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB {
private:
  std::string _name;
  Weapon *_weapon;

public:
  HumanB(void) {}
  HumanB(const std::string &name) : _name(name), _weapon(NULL) {};
  HumanB &operator=(const HumanB &other);
  ~HumanB(void) {}

  void setWeapon(Weapon &other);
  void attack(void);
};
