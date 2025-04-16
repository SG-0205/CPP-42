/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:18:15 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/16 10:43:22 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <ostream>
#include <stdexcept>

void MateriaSource::_refreshKnownTypes(void) {
  for (unsigned int i = 0; i < 4; i++)
    if (_materias[i])
      _materias_types[i] = _materias[i]->getType();
}

void MateriaSource::_initMateriasArray(void) {
  for (unsigned int i = 0; i < 4; i++) {
    _materias[i] = NULL;
    _materias_types[i] = "";
  }
}

int MateriaSource::_getMateriaIndexFromType(const std::string &type) {
  for (int i = 0; i < 4; i++)
    if (_materias_types[i] == type)
      return (i);

  return (-1);
}

MateriaSource::MateriaSource(void) { _initMateriasArray(); }

MateriaSource::MateriaSource(const MateriaSource &other) {
  for (unsigned int i = 0; i < 4; i++)
    if (other._materias[i])
      this->_materias[i] = other._materias[i]->clone();
  _refreshKnownTypes();
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
  if (this == &other)
    return (*this);

  for (unsigned int i = 0; i < 4; i++)
    if (other._materias[i])
      this->_materias[i] = other._materias[i]->clone();
  _refreshKnownTypes();

  return (*this);
}

MateriaSource::~MateriaSource(void) {
  for (unsigned int i = 0; i < 4; i++)
    if (_materias[i])
      _materias[i]->del();
}

void MateriaSource::learnMateria(AMateria *m) {
  bool inserted = false;

  m->registerThis();
  for (unsigned int i = 0; i < 4; i++)
    if (!_materias[i]) {
      _materias[i] = m->clone(), inserted = true;
      break;
    }

  if (inserted)
    _refreshKnownTypes();
}

AMateria *MateriaSource::createMateria(const std::string &type) {
  if (type.empty())
    throw std::invalid_argument(
        "MateriaSource::createMateria: empty type as param.");

  const int &materia_index(_getMateriaIndexFromType(type));

  if (materia_index < 0)
    return (0);

  return (_materias[materia_index]->clone());
}

void MateriaSource::printSourceContent(void) const {
  std::cout << "---Known Materias for " << this << "---\n";
  for (unsigned int i = 0; i < 4; i++)
    if (_materias[i])
      std::cout << '[' << i << "]\t" << _materias[i] << "\t"
                << _materias[i]->getType() << '\n';

  std::cout << std::endl;
}
