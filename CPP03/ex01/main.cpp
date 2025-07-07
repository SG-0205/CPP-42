/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:55:49 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/11 21:01:33 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int print_usage(void) {
  std::cerr << "./ClapTrap <name>";
  return (1);
}

int main(int argc, char **argv) {
  if (argc != 2)
    return (print_usage());

  ClapTrap clap(argv[1]);

  clap.attack("Dummy");
  clap.takeDamage(3);
  clap.printState();
  clap.beRepaired(3);
  clap.printState();

  for (int i = 1; i < 11; i++) {
    clap.takeDamage(i);
    clap.printState();
  }

  ClapTrap copy(clap);

  std::cout << "COPY STATE:\n";
  copy.printState();

  ClapTrap assign = copy;

  std::cout << "ASSIGNED STATE:\n";
  assign.printState();

  return (0);
}
