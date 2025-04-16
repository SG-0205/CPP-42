/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:28:55 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 12:33:03 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>
#include <ostream>

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
  std::cout << "[W/CAT] Default constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
  std::cout << "[W/CAT] Copy constructor called." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
  if (this == &other)
    return (*this);

  std::cout << "[W/CAT] Assignment operator used." << std::endl;
  this->_type = other.getType();

  return (*this);
}

WrongCat::~WrongCat(void) {
  std::cout << "[W/CAT] Destructor called." << std::endl;
}
