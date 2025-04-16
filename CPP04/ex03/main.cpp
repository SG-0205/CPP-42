/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:44:33 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/16 11:50:58 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "FireBall.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "LinkedList.hpp"
#include "MateriaSource.hpp"
#include <cstdlib>
#include <iostream>
#include <ostream>

int main(void) {

  // Ice *test_ice = new Ice();
  // Ice *test_ice2 = new Ice();
  // Ice *test_ice3 = new Ice();
  //
  // std::cout << test_ice->getType() << std::endl;
  //
  // Character test_character("John");
  //
  // test_character.equip(test_ice);
  // test_character.equip(test_ice2);
  // test_character.equip(test_ice3);
  // test_character.printInventory();
  //
  // test_character.unequip(2);
  // test_character.printInventory();
  //
  // Character character_clone(test_character);
  // character_clone.printInventory();
  //
  // Ice *test_clone(test_ice->clone());
  // test_clone->use(test_character);
  //
  // MateriaSource source;
  //
  // source.learnMateria(test_ice);
  // source.printSourceContent();
  // source.createMateria("ice")->use(test_character);
  //
  // delete test_ice;
  // delete test_ice2;
  // delete test_ice3;

  // Test du sujet:

  IMateriaSource *src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  src->learnMateria(new FireBall());

  src->printSourceContent();

  ICharacter *me = new Character("me");
  AMateria *tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  tmp = src->createMateria("fireball");
  me->equip(tmp);
  me->printInventory();
  ICharacter *bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  me->use(2, *bob);
  delete bob;
  delete me;
  delete src;

  return (0);
}
