/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:51:10 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/29 16:58:12 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cmath>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("default", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other), _target(other.GetTarget()) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  if (this == &other)
    return (*this);

  AForm::operator=(other);
  this->_target = other.GetTarget();

  return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  if (!isSigned())
    throw NoSignatureException(
        "PresidentialPardonForm::execute: this form isn't signed!");
  else if (executor.getGrade() > GetMinimalExecutionGrade())
    throw GradeTooLowException("PresidentialPardonForm::execute: bureaucrat " +
                               executor.getName() +
                               "'s grade is too low to execute this form!");

  const std::string &target = GetTarget();

  std::cout << target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
