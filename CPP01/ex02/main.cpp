/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:02:30 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/09 18:06:30 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <string>

int main(void) {
  std::string brain_str("HI THIS IS BRAIN");
  std::string *stringPTR = &brain_str;
  std::string &stringREF = brain_str;

  std::cout << &brain_str << '\n'
            << stringPTR << '\n'
            << &stringREF << std::endl;

  std::cout << '\n'
            << brain_str << '\n'
            << *stringPTR << '\n'
            << stringREF << std::endl;

  return (0);
}
