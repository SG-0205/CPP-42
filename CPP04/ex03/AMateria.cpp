/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:22:29 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/16 09:42:48 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "LinkedList.hpp"
#include <iostream>
#include <ostream>

LinkedList AMateria::_collector = LinkedList();

AMateria::AMateria(void) : _type("def") {}

AMateria::AMateria(const std::string &type) : _type(type) {}

AMateria::AMateria(const AMateria &other) : _type(other.getType()) {}

AMateria &AMateria::operator=(const AMateria &other) {
  if (this == &other)
    return (*this);

  this->_type = other._type;

  return (*this);
}

AMateria::~AMateria(void) {}

const std::string &AMateria::getType() const { return (_type); }

void AMateria::use(ICharacter &target) {
  std::cout << target.getName() << std::endl;
}

void AMateria::registerThis(void) {
  ListNode *registered = _collector.getNode(this, MATERIA);

  if (!registered)
    _collector.addPtr(this, MATERIA);
}

void AMateria::del(void) {
  ListNode *registered = _collector.getNode(this, MATERIA);

  if (!registered)
    delete this;
  else {
    delete static_cast<AMateria *>(registered->ptr);
    registered->ptr = NULL;
  }
}
