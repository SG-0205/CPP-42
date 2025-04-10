#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <ostream>

static void usage(void) {
  std::cerr << "./ex00 <name1> <name2>" << std::endl;
  exit(EINVAL);
}

int main(int argc, char **argv) {
  if (argc != 3)
    usage();

  // Test du constructeur par defaut;
  std::cout << "EX00\n" << std::endl;
  ClapTrap clap1(argv[1]);
  ClapTrap clap2(argv[2]);

  // Test du constructeur par copie
  ClapTrap cpy_test(clap1);

  // Test de l'operateur d'assignation
  ClapTrap assign_test("Assignation");
  assign_test = cpy_test = assign_test = clap1;

  clap1.printState();
  clap2.printState();
  cpy_test.printState();
  assign_test.printState();

  // Test des actions et de la logique d'enegie / vie
  for (int i = 0; i < 11; i++) {
    clap2.beRepaired(i);
    clap2.attack("Dummy");
    clap2.printState();
  }
  // Cette action ne devrait pas prendre de points d'energie et ne devrait tenir
  // compte que des hit points
  for (int i = 0; i < 11; i++)
    clap2.takeDamage(i);

  // Les autres actions sont maintenant bloquees par le manque de hit points
  clap2.attack("Dummy 2");
  clap2.beRepaired(10);

  clap1.printState();
  clap2.printState();
  cpy_test.printState();
  assign_test.printState();

  std::cout << "EX01\n" << std::endl;
  // Constructeurs standards;
  ScavTrap scav1(argv[1]);
  ScavTrap scav2(argv[2]);

  // Constructeurs par copie
  ScavTrap scav_cpy(scav2);

  // Assignation
  scav_cpy = scav1;

  scav1.printState();
  scav2.printState();
  scav_cpy.printState();

  for (int i = 1; i < 11; i++) {
    std::cout << "\n\nLoop " << i << std::endl;
    scav1.attack("Dummy");
    scav2.beRepaired(i / 2);
    scav2.takeDamage(i);
    scav2.printState();
    scav1.printState();
  }

  scav1.guardGate();
  scav2.guardGate();

  scav1.printState();
  scav2.printState();
  scav_cpy.printState();

  return (0);
}

// TODO VERIFIER ASSIGNATION && VERIFIER VIE EN PREMIER;
