/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:08:08 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 14:15:47 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <ostream>

void askSound(const Animal &animal) { animal.makeSound(); }

void replicateAnimals(unsigned int amount) {
  while (amount % 2 != 0)
    amount++;

  Animal *array[amount];

  for (unsigned int i = 0; i < amount; i++) {
    if (i % 2 == 0)
      array[i] = new Dog();
    else
      array[i] = new Cat();

    askSound(*array[i]);
  }

  for (unsigned int i = 0; i < amount; i++)
    delete array[i];
}

int main() {
  std::cout << "----------EX01----------" << std::endl;
  replicateAnimals(10);

  Dog sentient_dog;
  Cat sentient_cat;

  // storeFast insere le parametre dans le premier slot disponible
  // inputIdea insere le parametre a l'index specifie (exception possible)
  sentient_dog.getBrain()->storeFast("woof woof");
  sentient_dog.getBrain()->inputIdea(50, "wif wif");
  sentient_cat.getBrain()->storeFast("meaow meaow");
  sentient_cat.getBrain()->inputIdea(50, "purrr");

  // La copie d'un objet Dog/Cat devrait aussi copier ses idees
  Dog new_dog(sentient_dog);
  Cat new_cat(sentient_cat);

  // firstThingInMind renvoie la premiere idee non vide
  // outputIdea renoie l'idee stockee a l'index specifie
  std::cout << new_cat.getBrain()->firstThingInMind() << std::endl;
  std::cout << new_cat.getBrain()->outputIdea(50) << std::endl;
  std::cout << new_dog.getBrain()->firstThingInMind() << std::endl;
  std::cout << new_dog.getBrain()->outputIdea(50) << std::endl;

  // Test du sujet:
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  delete j; // should not create a leak
  delete i;

  // Tout le code precedent fonctionne comme prevu, la ligne suivante et
  // commentee sera lue comme une erreur par le compilateur car c'est un essai
  // d'instanciation d'une classe abstraite:

  // Animal test_abs;
  // const Animal c_test_abs;
  return 0;
}
