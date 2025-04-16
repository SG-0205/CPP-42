/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:08:20 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/16 10:50:59 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
  std::string _materias_types[4];
  AMateria *_materias[4];

  void _refreshKnownTypes(void);
  void _initMateriasArray(void);
  int _getMateriaIndexFromType(const std::string &type);

public:
  MateriaSource(void);
  MateriaSource(const MateriaSource &other);
  MateriaSource &operator=(const MateriaSource &other);
  ~MateriaSource(void);

  void learnMateria(AMateria *m);
  AMateria *createMateria(const std::string &type);
  void printSourceContent(void) const;
};
