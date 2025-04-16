/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:53:22 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 14:07:15 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <ostream>

Dog::Dog(void) : Animal("Dog"), _brain(new Brain()) {
  std::cout << "[DOG] Default constructor called." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), _brain(new Brain()) {
  std::cout << "[DOG] Copy constructor called." << std::endl;
  *(this->_brain) = *(other._brain);
}

Dog &Dog::operator=(const Dog &other) {
  if (this == &other)
    return (*this);

  std::cout << "[DOG] Assignment operator used." << std::endl;
  _type = other.getType();
  *(this->_brain) = *(other._brain);

  return (*this);
}

Dog::~Dog(void) {
  std::cout << "[DOG] Destructor called." << std::endl;
  delete _brain;
}

Brain *Dog::getBrain(void) { return (_brain); }

void Dog::makeSound(void) const {
  std::cout << '<' << getType() << ">: \"Woof!\"" << std::endl;
}
