/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:28:33 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/11/01 18:07:06 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <string>

#define DEF_MSG "* LOUD AND UNBEAREABLE FEEDBACK NOISE *"

int print_message(std::string amplified_message) {
  std::cout << amplified_message << std::endl;
  return (0);
}

int main(int argc, char **argv) {
  if (argc < 2)
    return (print_message(DEF_MSG));

  std::string messages[argc - 1];
  std::locale loc;

  for (int i = 1; i < argc; i++) {
    messages[i - 1] = std::string(argv[i]);
  }

  for (int i = 0; i < argc - 1; i++) {
    for (size_t j = 0; j < messages[i].length(); j++) {
      std::cout << std::toupper(messages[i][j], loc);
    }
  }
  std::cout << std::endl;

  return (0);
}
