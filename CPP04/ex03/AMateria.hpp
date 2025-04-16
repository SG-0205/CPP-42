/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:17:58 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 16:01:59 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "LinkedList.hpp"
#include <string>

class ICharacter;

class AMateria {
protected:
  std::string _type;
  static LinkedList _collector;

public:
  AMateria(void);
  AMateria(const AMateria &other);
  AMateria &operator=(const AMateria &other);
  AMateria(std::string const &type);
  virtual ~AMateria(void);

  std::string const &getType() const; // Returns the materia type
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);
  void del(void);
  void registerThis(void);
};
