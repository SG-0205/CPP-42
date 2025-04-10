/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:18:53 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/09 14:20:22 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>

Zombie *newZombie(const std::string &name) {
  Zombie *immortal_zombie = new Zombie(name);
  if (!immortal_zombie)
    throw std::bad_alloc();

  return (immortal_zombie);
}
