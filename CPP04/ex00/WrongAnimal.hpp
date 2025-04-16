/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:17:09 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/15 12:41:54 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
class WrongAnimal {
protected:
  std::string _type;

public:
  WrongAnimal(void);
  WrongAnimal(const std::string &type);
  WrongAnimal(const WrongAnimal &other);
  WrongAnimal &operator=(const WrongAnimal &other);
  virtual ~WrongAnimal(void);

  const std::string &getType(void) const;
  void makeSound(void) const;
};
