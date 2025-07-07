#include "Data.hpp"
#include "Serializer.hpp"
#include "colors.h"
#include <cctype>
#include <cstddef>
#include <exception>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <stdlib.h>

int printUsage(void) {
  std::cerr << RED "./serialize <name> <age(>0)> <is_active(true/false)> "
                   "<Level(PISCINER/STUDENT/ALUMNI)>" RESET
            << std::endl;

  return (1);
}

inline bool checkLevel(const std::string &level_str) {
  return (level_str == "PISCINER" || level_str == "STUDENT" ||
          level_str == "ALUMNI");
}

Level parseLevel(const std::string &level_str) {
  if (level_str == "PISCINER")
    return (PISCINER);
  else if (level_str == "STUDENT")
    return (STUDENT);
  else if (level_str == "ALUMNI")
    return (ALUMNI);
  else
    throw std::runtime_error(
        "parseLevel: invalid level string after checkLevel.");
}

Data *makeData(char **args_start) {
  const std::string name = args_start[0], age = args_start[1],
                    is_active = args_start[2], level = args_start[3];

  if (name.empty())
    throw std::invalid_argument("makeData: empty name.");

  for (size_t i = 0; i < age.length(); i++)
    if (!std::isdigit(age[i]))
      throw std::invalid_argument(
          "makeData: age must be a not null or negative number.");
  if (atoi(age.c_str()) <= 0)
    throw std::invalid_argument("makeData: age cannot be null or negative.");

  if (is_active != "true" && is_active != "false")
    throw std::invalid_argument("makeData: is_active must be true or false.");

  if (!checkLevel(level))
    throw std::invalid_argument(
        "makeData: level must be PISCINER, STUDENT or ALUMNI.");

  Data *new_data =
      new Data(name, atoi(age.c_str()), (is_active == "true" ? true : false),
               parseLevel(level));

  return (new_data);
}

int main(int argc, char **argv) {
  if (argc != 5)
    return (printUsage());

  Data *new_data = NULL;
  try {
    new_data = makeData(&argv[1]);
  } catch (const std::exception &e) {
    std::cerr << "Error during data creation:\n" << e.what() << '\n';
    return (1);
  }

  std::cout << GREEN "Data creation OK." RESET << '\n';
  new_data->print();
  std::cout << '\n';
  std::cout << ITALIC "Serialized:\t" << Serializer::serialize(new_data)
            << RESET << '\n';

  std::cout << GREEN << "After deserialization:\n" RESET << '\n';
  Data *unserialized = Serializer::deserialize(Serializer::serialize(new_data));
  unserialized->print();

  delete unserialized;

  return (0);
}
