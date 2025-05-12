/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:55:49 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 11:22:48 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int print_usage(void) {
  std::cerr << "./DiamondTrap <name>";
  return (1);
}

template <typename TypeTrap>
void test_loop(TypeTrap *to_test, const std::string &source, const int &max_i) {
  std::cout << "\nTEST LOOP FOR " << source << '\n';

  TypeTrap copy(*to_test);
  std::cout << "---Copy Constructor Test---\n";
  std::cout << "Base Object:\n";
  to_test->printState();
  std::cout << "Copied Object:\n";
  copy.printState();

  std::cout << "---Action loop---\n";
  for (int i = 1; i < max_i; i++) {
    copy.takeDamage(i);
    copy.beRepaired(i / 2);
    copy.printState();
  }

  std::cout << "---Assignation test---\n";
  TypeTrap assign("AssignTest");
  std::cout << "Before assignation:\n";
  assign.printState();
  assign = copy;
  std::cout << "After assignation:\n";
  assign.printState();
  std::cout << std::endl;
}

int main(int argc, char **argv) {
  if (argc != 2)
    return (print_usage());

  const std::string name(argv[1]);

  // ClapTrap clap(name + "_Clap");
  // ScavTrap scav(name + "_Scav");
  // FragTrap frag(name + "_Frag");
  DiamondTrap diams(name + "_Diams");

  // test_loop(&clap, "EX00", 15);
  // test_loop(&scav, "EX01", 30);
  // scav.guardGate();
  // test_loop(&frag, "EX02", 20);
  // frag.highFiveGuys();
  test_loop(&diams, "EX03", 20);
  diams.whoAmI();
  diams.guardGate();
  diams.highFiveGuys();
  diams.attack("Dummy");

  return (0);
}
