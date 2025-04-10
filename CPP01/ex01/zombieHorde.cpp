/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:30:03 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/09 17:58:03 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>
#include <stdexcept>

Zombie *zombieHorde(const int &N, const std::string &name) {
  if (N < 1)
    throw std::invalid_argument(
        "zombieHorde: null or negative number of zombies.");

  Zombie *horde = new Zombie[N];
  for (int i = 0; i < N; i++)
    horde[i].setName(name);

  return (horde);
}
