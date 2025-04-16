/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:45:00 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 12:15:30 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
#include <ostream>

const std::string &Animal::getType(void) const { return (_type); }

Animal::Animal(void) : _type("Default") {
  std::cout << "[ANIMAL] Default constructor called." << std::endl;
}

Animal::Animal(const std::string &type) : _type(type) {
  std::cout << "[ANIMAL] Constructor called with " << type << " as type."
            << std::endl;
}

Animal::Animal(const Animal &other) : _type(other.getType()) {
  std::cout << "[ANIMAL] Copy constructor called with " << other.getType()
            << " as base.";
}

Animal &Animal::operator=(const Animal &other) {
  if (this == &other)
    return (*this);

  this->_type = other.getType();

  return (*this);
}

Animal::~Animal(void) {
  std::cout << "[ANIMAL] Destructor called." << std::endl;
}

void Animal::makeSound(void) const {}
