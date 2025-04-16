/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:05:56 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 14:06:35 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>
#include <ostream>

Cat::Cat(void) : Animal("Cat"), _brain(new Brain()) {
  std::cout << "[CAT] Default constructor called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), _brain(new Brain()) {
  std::cout << "[CAT] Copy constructor called." << std::endl;
  *(this->_brain) = *(other._brain);
}

Cat &Cat::operator=(const Cat &other) {
  if (this == &other)
    return (*this);

  std::cout << "[CAT] Assignment operator used." << std::endl;
  _type = other.getType();
  this->_brain = other._brain;

  return (*this);
}

Cat::~Cat(void) {
  std::cout << "[CAT] Destructor called." << std::endl;
  delete _brain;
}

Brain *Cat::getBrain(void) { return (_brain); }

void Cat::makeSound(void) const {
  std::cout << '<' << getType() << ">: \"Meaow!\"" << std::endl;
}
