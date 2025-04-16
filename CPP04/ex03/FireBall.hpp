/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FireBall.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:41:51 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/16 11:48:24 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class FireBall : public AMateria {
public:
  FireBall(void);
  FireBall(const FireBall &other);
  FireBall &operator=(const FireBall &other);
  ~FireBall(void);

  FireBall *clone(void) const;
  void use(ICharacter &target);
};
