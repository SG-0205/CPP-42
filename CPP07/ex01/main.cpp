#include "colors.h"
#include "iter.hpp"
#include <iostream>
#include <ostream>

int printUsage(void) {
  std::cerr << RED "./iter <value1> <value2> [...]" RESET << std::endl;
  return (1);
}

void printData(const std::string &data) { std::cout << data << '\n'; }

void printNum(const unsigned int &data) { std::cout << data << '\n'; }

void modifyData(std::string &data) {
  for (size_t i = 0; i < data.length(); i++)
    data[i] = std::toupper(data[i]);
}

void modifyNum(unsigned int &data) { data += data; }

int main(int argc, char **argv) {
  if (argc < 2)
    return (printUsage());

  std::string array[argc - 1];

  for (int i = 1; i < argc; i++)
    array[i - 1] = argv[i];

  iter(array, argc - 1, printData);
  iter(array, argc - 1, modifyData);
  std::cout << "\nAfter modifying call:\n";
  iter(array, argc - 1, printData);

  std::cout << "\n\n";

  unsigned int numbers[10];
  for (int i = 0; i < 10; i++)
    numbers[i] = i;

  std::cout << GREEN "Test with numeric values:" RESET << '\n';

  iter(numbers, 10, printNum);
  iter(numbers, 10, modifyNum);
  std::cout << "\nAfter modifying call:\n";
  iter(numbers, 10, printNum);

  return (0);
}
