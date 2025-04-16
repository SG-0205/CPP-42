/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:06:45 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 16:11:39 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"
#include "LinkedList.hpp"
#include <iostream>
#include <ostream>

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure &other) : AMateria(other) {
  this->_type = other.getType();
}

Cure &Cure::operator=(const Cure &other) {
  if (this == &other)
    return (*this);

  this->_type = other.getType();

  return (*this);
}

Cure::~Cure(void) {}

Cure *Cure::clone(void) const {
  Cure *cpy = new Cure(*this);

  _collector.addPtr(cpy, MATERIA);

  return (cpy);
}

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
