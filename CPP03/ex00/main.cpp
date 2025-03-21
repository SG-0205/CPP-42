#include "ClapTrap.hpp"

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
  ClapTrap clap1(argv[1]);
  ClapTrap clap2(argv[2]);

  // Test du constructeur par copie
  ClapTrap cpy_test(clap1);

  // Test de l'operateur d'assignation
  ClapTrap assign_test("Assignation");
  assign_test = cpy_test = assign_test = clap1;

  // Test des actions et de la logique d'enegie / vie
  for (int i = 0; i < 11; i++) {
    clap2.beRepaired(i);
    clap2.attack("Dummy");
  }
  // Cette action ne devrait pas prendre de points d'energie et ne devrait tenir
  // compte que des hit points
  for (int i = 0; i < 11; i++)
    clap2.takeDamage(i);

  // Les autres actions sont maintenant bloquees par le manque de hit points
  clap2.attack("Dummy 2");
  clap2.beRepaired(10);

  return (0);
}

// TODO VERIFIER ASSIGNATION && VERIFIER VIE EN PREMIER;
