/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:16:02 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/09 17:59:33 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include "Zombie.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <new>

int print_usage(void) {
  std::cout << "./ex01 <N> <name>\n";
  return (1);
}

int main(int argc, char **argv) {
  if (argc < 2)
    return (print_usage());

  Zombie *horde = NULL;
  try {
    horde = zombieHorde(std::atoi(argv[1]), argv[2]);
  } catch (const std::bad_alloc &e) {
    std::cerr << e.what() << std::endl;
  }

  for (int i = 0; i < std::atoi(argv[1]); i++)
    horde[i].announce();

  delete[] horde;
  return (0);
}
