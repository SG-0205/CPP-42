/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:06:18 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/16 10:07:57 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
class IMateriaSource {
public:
  virtual ~IMateriaSource(void) {}
  virtual void learnMateria(AMateria *m) = 0;
  virtual AMateria *createMateria(const std::string &type) = 0;
  virtual void printSourceContent(void) const = 0;
};
