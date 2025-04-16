/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:04:25 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 12:08:40 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal {
public:
  Cat(void);
  Cat(const Cat &other);
  Cat &operator=(const Cat &other);
  ~Cat(void);

  void makeSound(void) const;
};
