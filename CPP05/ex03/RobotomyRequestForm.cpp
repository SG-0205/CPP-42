/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:17:25 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/29 16:29:40 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("default", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._GetTarget()) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this == &other)
    return (*this);

  AForm::operator=(other);
  this->_target = other._GetTarget();

  return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

const std::string &RobotomyRequestForm::_GetTarget(void) const {
  return (_target);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  if (!isSigned())
    throw NoSignatureException(
        "RobotomyRequestForm::execute: this form isn't signed!");
  else if (executor.getGrade() > GetMinimalExecutionGrade())
    throw GradeTooLowException("RobotomyRequestForm::execute: bureaucrat " +
                               executor.getName() +
                               "'s grade is too low to execute this form!");

  const std::string &target = _GetTarget();

  std::cout << "* DRILLING NOISES *" << std::endl;
  if (std::rand() % 2 == 0)
    std::cout << target << " has been robotomized." << std::endl;
  else
    std::cout << "robotomization of " << target << " has failed." << std::endl;
}
