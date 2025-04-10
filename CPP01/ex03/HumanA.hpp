/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:13:21 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/10 13:33:38 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA {
private:
  std::string _name;
  Weapon &_weapon;

public:
  HumanA(const std::string &name, Weapon &weapon)
      : _name(name), _weapon(weapon) {}
  HumanA &operator=(const HumanA &other);
  ~HumanA(void) {}

  void attack(void);
};
