/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:15:02 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/10 16:10:57 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

int print_usage(void) {
  std::cerr << "./ex04 <filename> <to_replace> <to_replace_with>" << std::endl;
  return (1);
}

std::string read_and_format(std::ifstream &infile,
                            const std::string &to_replace,
                            const std::string &to_replace_with) {
  std::string buffer;
  std::string infile_content;

  while (std::getline(infile, buffer))
    infile_content.append(buffer + '\n');

  for (int i = -1; i != 0;) {
    i = infile_content.find(to_replace);
    if (static_cast<size_t>(i) > infile_content.size() ||
        static_cast<size_t>(i) == std::string::npos)
      break;
    infile_content.erase(i, to_replace.length());
    infile_content.insert(i, to_replace_with);
  }

  return (infile_content);
}

int main(int argc, char **argv) {
  if (argc != 4)
    return (print_usage());

  std::string outfile_name(argv[1]);
  outfile_name.append(".replace");

  std::ifstream infile(argv[1]);
  std::ofstream outfile(outfile_name.c_str());
  std::string to_replace(argv[2]);
  std::string to_replace_with(argv[3]);

  if (to_replace.empty())
    throw std::invalid_argument("s1/to_replace is empty.");
  if (to_replace_with.empty())
    throw std::invalid_argument("s2/to_replace_with is empty.");
  if (!infile.is_open())
    throw std::invalid_argument("Infile couldn't be opened.");
  if (!outfile.is_open())
    throw std::invalid_argument("Outfile couldn't be opened or created.");

  try {
    std::string formatted =
        read_and_format(infile, to_replace, to_replace_with);
    outfile << formatted;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return (0);
}
