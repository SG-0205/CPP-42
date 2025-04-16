/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:21:36 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 12:37:09 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <ostream>

WrongAnimal::WrongAnimal(void) : _type("Default") {
  std::cout << "[W/ANIMAL] Default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type) {
  std::cout << "[W/ANIMAL] Constructor called with " << type << " as type."
            << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other.getType()) {
  std::cout << "[W/ANIMAL] Copy constructor called with " << other.getType()
            << " as base." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  if (this == &other)
    return (*this);

  std::cout << "[W/ANIMAL] Assignment operator used." << std::endl;
  this->_type = other.getType();

  return (*this);
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << "[W/ANIMAL] Destructor called." << std::endl;
}

void WrongAnimal::makeSound(void) const { std::cout << "ZBUARG" << std::endl; }

const std::string &WrongAnimal::getType(void) const { return (_type); }
