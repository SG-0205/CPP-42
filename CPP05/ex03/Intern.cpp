/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:26:19 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/30 19:28:59 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "colors.h"
#include <cctype>
#include <cstddef>
#include <curses.h>
#include <iostream>
#include <stdexcept>

Intern::Intern(void) {}

Intern::Intern(const Intern &other) {
  const Intern *dumb = static_cast<const Intern *>(&other);
  (void)dumb;
}

Intern &Intern::operator=(const Intern &other) {
  const Intern *dumb = static_cast<const Intern *>(&other);
  (void)dumb;
  return (*this);
}

Intern::~Intern(void) {}

AForm *Intern::_makeShrubberyCreationForm(const std::string &target) {
  if (target.empty())
    throw std::invalid_argument(
        "Intern::_makeShrubberyCreationForm: target is empty.");

  ShrubberyCreationForm *form = new ShrubberyCreationForm(target);

  std::cout << ITALIC << "Intern creates a ShrubberyCreationForm" << std::endl;

  return (form);
}

AForm *Intern::_makeRobotomyRequestForm(const std::string &target) {
  if (target.empty())
    throw std::invalid_argument(
        "Intern::_makeRobotomyRequestForm: target is empty");

  RobotomyRequestForm *form = new RobotomyRequestForm(target);

  std::cout << ITALIC << "Intern creates a RobotomyRequestForm" << std::endl;

  return (form);
}

AForm *Intern::_makePresidentialPardonForm(const std::string &target) {
  if (target.empty())
    throw std::invalid_argument(
        "Intern::_makePresidentialPardonForm: target is empty.");

  PresidentialPardonForm *form = new PresidentialPardonForm(target);

  std::cout << ITALIC << "Intern creates a PresidentialPardonForm" << std::endl;

  return (form);
}

const std::string Intern::_normalizeFormType(const std::string &raw_form_type) {
  if (raw_form_type.empty())
    throw std::invalid_argument(
        "Intern::_normalizeFormType: empty base form type.");

  size_t i = 0;
  // TODO ne pas skip si pas d'espace et si Upper dans raw_form_type;
  if (raw_form_type.find(" ") == std::string::npos) {
    for (size_t i = 0; i < raw_form_type.length(); i++) {
      if (std::isupper(raw_form_type[i]))
        break;
    }

    return (raw_form_type);
  }

  std::string normalized = raw_form_type;
  while (normalized.find(" ") != std::string::npos)
    normalized.erase(normalized.find(" "), 1);

  for (size_t i = 0; i < normalized.length(); i++)
    normalized[i] = std::tolower(normalized[i]);

  std::cout << normalized << std::endl;

  return (normalized);
}

AForm *Intern::makeForm(const std::string &form_type,
                        const std::string &form_target) {
  if (form_type.empty())
    throw std::invalid_argument(
        "Intern::makeForm: form_type parameter is empty.");
  else if (form_target.empty())
    throw std::invalid_argument(
        "Intern::makeForm: form_target parameter is empty");

  AForm *(Intern::*form_factories[])(const std::string &target) = {
      &Intern::_makeShrubberyCreationForm, &Intern::_makeRobotomyRequestForm,
      &Intern::_makePresidentialPardonForm};

  const std::string allowed_types[] = {"shrubberycreation", "robotomyrequest",
                                       "presidentialpardon"};

  const std::string normalized_type = _normalizeFormType(form_type);

  for (int fct_i = 0; fct_i < 3; fct_i++)
    if (allowed_types[fct_i] == normalized_type)
      return ((this->*form_factories[fct_i])(form_target));

  std::cerr << RED "Interns cannot make a \"" << form_type << "\" form!"
            << RESET << std::endl;

  return (NULL);
}
