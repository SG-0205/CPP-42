#include "ScalarConverter.hpp"
#include "colors.h"
#include <exception>
#include <iostream>
#include <ostream>

int printUsage(void) {
  std::cout << RED BOLD << "./convert <to_convert>" << RESET << std::endl;
  return (1);
}

int main(int argc, char **argv) {
  if (argc != 2)
    return (printUsage());

  try {
    ScalarConverter::convert(argv[1]);
  } catch (const std::exception &e) {
    std::cerr << "Error during conversion:\n" + std::string(e.what())
              << std::endl;
  }

  return (0);
}
