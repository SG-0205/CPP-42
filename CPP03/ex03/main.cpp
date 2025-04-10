#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <stdexcept>

static void usage(void) {
  std::cerr << "./ex00 <name1>" << std::endl;
  exit(EINVAL);
}

template <typename TrapType>
static void testLoop(TrapType *to_test, const std::string &source,
                     unsigned int nb_iterations = 10) {
  if (!to_test)
    throw std::invalid_argument("testLoop: null pointer as parameter.");

  std::cout << "TEST LOOP FOR " << source + '\n';

  // Constructeur par copie
  TrapType duplicate(*to_test);
  TrapType assignation("AssignTrap");
  assignation = *to_test;

  while (nb_iterations-- > 0) {
    std::cout << "i = " << nb_iterations << '\n';
    to_test->printState();
    std::cout << '\n';
    to_test->attack("Dummy");
    to_test->takeDamage(nb_iterations);
    to_test->beRepaired(nb_iterations / 2);
  }

  std::cout << "\n\nEND OF TEST LOOP\n";
  std::cout << "Original:\n";
  to_test->printState();

  std::cout << "Copy:\n";
  duplicate.printState();

  std::cout << "Assignation:\n";
  assignation.printState();
};

int main(int argc, char **argv) {
  if (argc != 2)
    usage();

  ClapTrap clap(argv[1]);
  ScavTrap scav("Scav" + std::string(argv[1]));
  FragTrap frag("Frag" + std::string(argv[1]));

  testLoop(&clap, "EX00");
  testLoop(&scav, "EX01");
  scav.guardGate();
  testLoop(&frag, "EX02");
  frag.highFivesGuys();
  // Test du constructeur par defaut;
  // std::cout << "EX00\n" << std::endl;
  // ClapTrap clap1(argv[1]);
  // ClapTrap clap2(argv[2]);
  //
  // // Test du constructeur par copie
  // ClapTrap cpy_test(clap1);
  //
  // // Test de l'operateur d'assignation
  // ClapTrap assign_test("Assignation");
  // assign_test = cpy_test = assign_test = clap1;
  //
  // clap1.printState();
  // clap2.printState();
  // cpy_test.printState();
  // assign_test.printState();
  //
  // // Test des actions et de la logique d'enegie / vie
  // for (int i = 0; i < 11; i++) {
  //   clap2.beRepaired(i);
  //   clap2.attack("Dummy");
  //   clap2.printState();
  // }
  // // Cette action ne devrait pas prendre de points d'energie et ne devrait
  // tenir
  // // compte que des hit points
  // for (int i = 0; i < 11; i++)
  //   clap2.takeDamage(i);
  //
  // // Les autres actions sont maintenant bloquees par le manque de hit points
  // clap2.attack("Dummy 2");
  // clap2.beRepaired(10);
  //
  // clap1.printState();
  // clap2.printState();
  // cpy_test.printState();
  // assign_test.printState();
  //
  // std::cout << "EX01\n" << std::endl;
  // // Constructeurs standards;
  // ScavTrap scav1(std::string(argv[1]) + "Scav");
  // ScavTrap scav2(std::string(argv[2]) + "Scav");
  //
  // // Constructeurs par copie
  // ScavTrap scav_cpy(scav2);
  //
  // // Assignation
  // scav_cpy = scav1;
  //
  // scav1.printState();
  // scav2.printState();
  // scav_cpy.printState();
  //
  // for (int i = 1; i < 11; i++) {
  //   std::cout << "\n\nLoop " << i << std::endl;
  //   scav1.attack("Dummy");
  //   scav2.beRepaired(i / 2);
  //   scav2.takeDamage(i);
  //   scav2.printState();
  //   scav1.printState();
  // }
  //
  // scav1.guardGate();
  // scav2.guardGate();
  //
  // scav1.printState();
  // scav2.printState();
  // scav_cpy.printState();
  //
  // std::cout << "EX01\n" << std::endl;
  // // Constructeurs standards;
  // FragTrap frag1(std::string(argv[1]) + "Frag");
  // FragTrap frag2(std::string(argv[2]) + "Frag");
  //
  // // Constructeurs par copie
  // FragTrap frag_cpy(frag1);
  //
  // // Assignation
  // frag_cpy = frag2;
  //
  // frag1.printState();
  // frag2.printState();
  // frag_cpy.printState();
  //
  // for (int i = 1; i < 11; i++) {
  //   std::cout << "\n\nLoop " << i << std::endl;
  //   frag1.attack("Dummy");
  //   frag2.beRepaired(i / 2);
  //   frag2.takeDamage(i);
  //   frag2.printState();
  //   frag1.printState();
  // }
  //
  // frag1.highFivesGuys();
  // frag2.highFivesGuys();
  //
  // frag1.printState();
  // frag2.printState();
  // frag_cpy.printState();
  //
  // return (0);
}

// TODO VERIFIER ASSIGNATION && VERIFIER VIE EN PREMIER;
