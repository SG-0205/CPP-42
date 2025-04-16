/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:08:08 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 12:40:40 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <ostream>

void askSound(const Animal &animal) { animal.makeSound(); }

int main() {
  // virtual override
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); // will output the cat sound!
  j->makeSound();
  meta->makeSound();

  // override une fonction virtuelle permet de simplifier le code tout en
  // specialisant chaque classe:
  askSound(*j);
  askSound(*i);

  // no override
  const WrongAnimal *meta2 = new WrongAnimal();
  const WrongCat *wcat = new WrongCat();
  std::cout << wcat->getType() << std::endl;
  wcat->makeSound();
  meta2->makeSound();

  delete meta;
  delete j;
  delete i;
  delete meta2;
  delete wcat;
  return 0;
}
