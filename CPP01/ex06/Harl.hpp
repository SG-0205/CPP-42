/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:18:28 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/10 18:55:31 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
class Harl {
private:
  void _debug(void);
  void _info(void);
  void _warning(void);
  void _error(void);

  void (Harl::*_complaints_pointers[4])(void);
  std::string _levels[4];

public:
  Harl(void);
  Harl(const Harl &other);
  Harl &operator=(const Harl &other);
  ~Harl(void) {}

  void complain(const std::string &level);
};
