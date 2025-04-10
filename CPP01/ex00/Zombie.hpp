/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:07:47 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/09 17:53:21 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie {
private:
  std::string _name;

public:
  Zombie(void) {};
  Zombie(const std::string &name) : _name(name) {}
  Zombie(const Zombie &other) : _name(other._name) {};
  Zombie &operator=(const Zombie &other);
  ~Zombie();

  void announce(void);
};
