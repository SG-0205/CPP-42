/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:43:36 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 12:41:30 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Animal {
protected:
  std::string _type;

public:
  Animal(void);
  Animal(const std::string &type);
  Animal(const Animal &other);
  Animal &operator=(const Animal &other);
  virtual ~Animal(void);

  const std::string &getType(void) const;
  virtual void makeSound(void) const;
};
