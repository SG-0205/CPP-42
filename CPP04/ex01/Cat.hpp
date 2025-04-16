/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:04:25 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 13:39:11 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
  Brain *_brain;

public:
  Cat(void);
  Cat(const Cat &other);
  Cat &operator=(const Cat &other);
  ~Cat(void);

  void makeSound(void) const;
  Brain *getBrain(void);
};
