/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:00:08 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 11:26:17 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
  FragTrap(void);
  FragTrap(const std::string &name);
  FragTrap(const FragTrap &other);
  FragTrap &operator=(const FragTrap &other);
  virtual ~FragTrap(void);

  void attack(const std::string &target);
  void highFiveGuys(void);
};
