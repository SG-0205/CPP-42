/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FireBall.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:44:28 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/16 11:49:18 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FireBall.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "LinkedList.hpp"
#include <iostream>
#include <ostream>

FireBall::FireBall(void) : AMateria("fireball") {}

FireBall::FireBall(const FireBall &other) : AMateria(other) {}

FireBall &FireBall::operator=(const FireBall &other) {
  if (this == &other)
    return (*this);

  this->_type = other.getType();

  return (*this);
}

FireBall::~FireBall(void) {}

FireBall *FireBall::clone(void) const {
  FireBall *cpy = new FireBall(*this);

  _collector.addPtr(cpy, MATERIA);

  return (cpy);
}

void FireBall::use(ICharacter &target) {
  std::cout << "* shoots a fireball at " << target.getName() << " *"
            << std::endl;
}
