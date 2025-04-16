/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:05:56 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 12:15:31 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>
#include <ostream>

Cat::Cat(void) : Animal("Cat") {
  std::cout << "[CAT] Default constructor called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "[CAT] Copy constructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
  if (this == &other)
    return (*this);

  std::cout << "[CAT] Assignment operator used." << std::endl;
  _type = other.getType();

  return (*this);
}

Cat::~Cat(void) { std::cout << "[CAT] Destructor called." << std::endl; }

void Cat::makeSound(void) const {
  std::cout << '<' << getType() << ">: \"Meaow!\"" << std::endl;
}
