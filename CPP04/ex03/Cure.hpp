/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:04:47 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 16:06:38 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
class Cure : public AMateria {
public:
  Cure(void);
  Cure(const Cure &other);
  Cure &operator=(const Cure &other);
  ~Cure(void);

  Cure *clone(void) const;
  void use(ICharacter &target);
};
