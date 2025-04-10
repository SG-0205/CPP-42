/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:16:02 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/09 14:27:08 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include "Zombie.hpp"
#include <iostream>
#include <new>

int print_usage(void) {
  std::cout << "./ex00 <name1> <name2>\n";
  return (1);
}

int main(int argc, char **argv) {
  if (argc < 2)
    return (print_usage());

  Zombie *long_life_zombie = NULL;
  try {
    long_life_zombie = newZombie(std::string(argv[1]) + "_long_life");
  } catch (const std::bad_alloc &e) {
    std::cerr << e.what() << std::endl;
  }
  long_life_zombie->announce();

  randomChump(argv[2]);
  randomChump(argv[1]);
  randomChump(argv[2]);
  randomChump(argv[1]);

  delete long_life_zombie;
  return (0);
}
