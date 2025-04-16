/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:53:22 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 12:10:00 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>
#include <ostream>

Dog::Dog(void) : Animal("Dog") {
  std::cout << "[DOG] Default constructor called." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "[DOG] Copy constructor called." << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
  if (this == &other)
    return (*this);

  std::cout << "[DOG] Assignment operator used." << std::endl;
  _type = other.getType();

  return (*this);
}

Dog::~Dog(void) { std::cout << "[DOG] Destructor called." << std::endl; }

void Dog::makeSound(void) const {
  std::cout << '<' << getType() << ">: \"Woof!\"" << std::endl;
}
