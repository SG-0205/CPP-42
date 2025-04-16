/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:20:07 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 14:31:30 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria {
public:
  Ice(void);
  Ice(const Ice &other);
  Ice &operator=(const Ice &other);
  ~Ice(void);

  Ice *clone(void) const;
  void use(ICharacter &target);
};
