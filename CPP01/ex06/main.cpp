/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:00:47 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/10 19:08:59 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstring>
#include <iostream>
#include <ostream>

int print_usage(void) {
  std::cerr << "./harlFilter <level> (DEBUG || INFO || WARNING || ERROR)"
            << std::endl;

  return (1);
}

bool check_level(const std::string &level) {
  if (level.empty())
    return (false);

  if (std::strcmp(level.c_str(), "DEBUG") &&
      std::strcmp(level.c_str(), "INFO") &&
      std::strcmp(level.c_str(), "WARNING") &&
      std::strcmp(level.c_str(), "ERROR"))
    return (false);

  return (true);
}

int main(int argc, char **argv) {
  if (argc != 2 || !check_level(argv[1]))
    return (print_usage());

  Harl harl;

  // TODO relire le suejt pour message d'usage et renseigner sur le fallthrough;
  switch (argv[1][0]) {
  case ('D'): {
    harl.complain()
  }
  }
}
