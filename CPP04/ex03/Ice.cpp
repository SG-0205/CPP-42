/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:46:25 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 16:03:47 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include "LinkedList.hpp"
#include <iostream>
#include <ostream>

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice &other) : AMateria(other) {}

Ice &Ice::operator=(const Ice &other) {
  if (this == &other)
    return (*this);

  this->_type = other.getType();

  return (*this);
}

Ice::~Ice(void) {}

Ice *Ice::clone(void) const {
  Ice *cpy = new Ice(*this);

  _collector.addPtr(cpy, MATERIA);

  return (cpy);
}

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
