/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:25:51 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/29 16:13:53 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm(), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._GetTarget()) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this == &other)
    return (*this);

  AForm::operator=(other);
  this->_target = other._GetTarget();

  return (*this);
}

const std::string &ShrubberyCreationForm::_GetTarget(void) const {
  return (_target);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
  if (!isSigned())
    throw NoSignatureException(
        "ShrubberyCreationForm::execute: form isn't signed!");
  else if (executor.getGrade() > GetMinimalExecutionGrade())
    throw GradeTooLowException("ShrubberyCreationForm::execute: bureaucrat " +
                               executor.getName() +
                               "'s grade is too low to execute this form.");

  const std::string &target = _GetTarget();
  const std::string tree = "       _-_\n"
                           "    /~~   ~~\\ \n"
                           " /~~         ~~i\\ \n"
                           "{               } \n"
                           " \\  _-     -_  / \n"
                           "   ~  \\ //  ~ \n"
                           "_- -   | | _- _ \n"
                           "  _ -  | |   -_ \n"
                           "      // \\ \n";

  std::ofstream file(target.c_str());
  if (!file.is_open())
    throw std::invalid_argument(
        "ShrubberyCreationForm::execute: cannot create or open target.");

  file << tree;
  file << tree;
  file << tree;
  file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}
