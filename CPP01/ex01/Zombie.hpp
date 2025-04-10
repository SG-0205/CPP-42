/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:07:47 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/09 17:46:32 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie {
private:
  std::string _name;

public:
  Zombie() {}
  Zombie(const std::string &name) : _name(name) {}
  Zombie(const Zombie &other) : _name(other._name) {};
  Zombie &operator=(const Zombie &other);
  ~Zombie();

  void setName(const std::string &name);
  void announce(void);
};
