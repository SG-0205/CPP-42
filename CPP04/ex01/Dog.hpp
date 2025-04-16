/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:51:32 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 13:39:33 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
  Brain *_brain;

public:
  Dog(void);
  Dog(const Dog &other);
  Dog &operator=(const Dog &other);
  ~Dog(void);

  Brain *getBrain(void);
  void makeSound(void) const;
};
