/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:51:32 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 12:14:13 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal {
public:
  Dog(void);
  Dog(const Dog &other);
  Dog &operator=(const Dog &other);
  ~Dog(void);

  void makeSound(void) const;
};
