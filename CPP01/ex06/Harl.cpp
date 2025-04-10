/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:36:20 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/10 18:57:37 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <ostream>
#include <stdexcept>

void Harl::_debug(void) {
  std::cout
      << "<DEBUG>\nI love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
      << std::endl;
}

void Harl::_info(void) {
  std::cout
      << "<INFO>\nI cannot believe adding extra bacon costs more money. You "
         "didn’t put"
         " enough bacon in my burger! If you did, I wouldn’t be asking for more"
      << std::endl;
}

void Harl::_warning(void) {
  std::cout << "<WARNING>\nI think I deserve to have some extra bacon for "
               "free. I’ve been "
               "coming for"
               " years, whereas you started working here just last month"
            << std::endl;
}

void Harl::_error(void) {
  std::cout
      << "<ERROR>\nThis is unacceptable! I want to speak to the manager now."
      << std::endl;
}

Harl &Harl::operator=(const Harl &other) {
  if (this == &other)
    return (*this);

  for (int i = 0; i < 4; i++) {
    this->_levels[i] = other._levels[i];
    this->_complaints_pointers[i] = other._complaints_pointers[i];
  }

  return (*this);
}

Harl::Harl(void) {
  _complaints_pointers[0] = &Harl::_debug;
  _complaints_pointers[1] = &Harl::_info;
  _complaints_pointers[2] = &Harl::_warning;
  _complaints_pointers[3] = &Harl::_error;

  _levels[0] = "DEBUG";
  _levels[1] = "INFO";
  _levels[2] = "WARNING";
  _levels[3] = "ERROR";
}

Harl::Harl(const Harl &other) {
  for (int i = 0; i < 4; i++) {
    _levels[i] = other._levels[i];
    _complaints_pointers[i] = other._complaints_pointers[i];
  }
}

void Harl::complain(const std::string &level) {
  if (level.empty())
    throw std::invalid_argument("Harl::complain: invalid level provided.");

  for (int i = 0; i < 4; i++) {
    if (_levels[i] == level) {
      (this->*_complaints_pointers[i])();
      break;
    }
  }
}
