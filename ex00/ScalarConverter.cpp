/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:21:17 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/05/01 18:00:27 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <stdexcept>

ScalarConverter::ScalarConverter(void) {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
  *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  if (this == &other)
    return (*this);

  return (*this);
}

ScalarConverter::~ScalarConverter(void) {}

static void printChar(const std::string &to_convert) {
  const bool printable = (to_convert.length() == 1);

  std::cout << "char litteral: ";
  if (printable)
    std::cout << to_convert[0];
  else
    std::cout << "no conversion possible";

  std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &to_convert) {
  if (to_convert.empty())
    throw std::invalid_argument("ScalarConverter::convert: empty parameter.");
}
