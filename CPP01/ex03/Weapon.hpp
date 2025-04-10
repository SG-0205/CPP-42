/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:08:14 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/09 18:10:54 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
class Weapon {
private:
  std::string _type;

public:
  Weapon() {}
  Weapon(const std::string &type) : _type(type) {}
  Weapon &operator=(const Weapon &other);
  ~Weapon() {}

  const std::string &getType(void);
  void setType(const std::string &type);
};
