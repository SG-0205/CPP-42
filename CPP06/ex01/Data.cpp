#include "Data.hpp"

#include "colors.h"
#include <iostream>

Data::Data(void) : _name("def"), _age(0), _active(false), _level(PISCINER) {}

Data::Data(const std::string &name, const unsigned int &age,
           const bool &is_active, const Level &level)
    : _name(name), _age(age), _active(is_active), _level(level) {}

Data::Data(const Data &other)
    : _name(other.GetName()), _age(other.GetAge()), _active(other.IsActive()),
      _level(other.GetLevel()) {}

Data &Data::operator=(const Data &other) {
  if (this == &other)
    return (*this);

  this->setName(other.GetName());
  this->setAge(other.GetAge());
  this->setActivityStatus(other.IsActive());
  this->setLevel(other.GetLevel());

  return (*this);
}

Data::~Data(void) {}

const std::string &Data::GetName(void) const { return (_name); }

const unsigned int &Data::GetAge(void) const { return (_age); }

const bool &Data::IsActive(void) const { return (_active); }

const Level &Data::GetLevel(void) const { return (_level); }

const std::string Data::GetLevelString(void) const {
  switch (GetLevel()) {
  case (PISCINER):
    return ("Pisciner");
    break;
  case (STUDENT):
    return ("Student");
    break;
  case (ALUMNI):
    return ("Alumni");
    break;
  }

  return ("ERROR DURING LEVEL TRANSLATION.");
}

void Data::setName(const std::string &name) { _name = name; }

void Data::setAge(const unsigned int &age) { _age = age; }

void Data::setActivityStatus(const bool &is_active) { _active = is_active; }

void Data::setLevel(const Level &level) { _level = level; }

void Data::print(void) {
  std::cout << BOLD UNDERLINE BLUE << GetName() << RESET << '\n'
            << '\t' << YELLOW << "AGE[" << GetAge() << ']' << RESET << '\n'
            << '\t' << YELLOW << "ACTIVE[" << std::boolalpha << IsActive()
            << ']' << RESET << '\n'
            << '\t' << CYAN << "LEVEL[" << GetLevelString() << ']' << RESET
            << '\n';
}
