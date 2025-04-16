/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:39:33 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/16 14:24:31 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>
#include <stdexcept>

void Bureaucrat::_checkGrade(void) const {
  const unsigned int &grade(getGrade());

  if (grade < 1)
    throw GradeTooHighException();
  else if (grade > 150)
    throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(void) : _name("def"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, const unsigned int &grade)
    : _name(name), _grade(grade) {
  _checkGrade();
  if (name.empty())
    throw std::invalid_argument(
        "Bureaucrat(const std::string &, const unsigned int &): empty name.");
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _name(other.getName()), _grade(other.getGrade()) {
  _checkGrade();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this == &other)
    return (*this);

  this->_grade = other.getGrade();
  _checkGrade();

  return (*this);
}

Bureaucrat::~Bureaucrat(void) {}

const std::string &Bureaucrat::getName(void) const { return (_name); }

const unsigned int &Bureaucrat::getGrade(void) const { return (_grade); }

void Bureaucrat::incrementGrade(void) {
  if (getGrade() < 2)
    throw GradeTooHighException(
        "Bureaucrat::incrementGrade: grade is too high to be incremented.");

  _grade--;
}

void Bureaucrat::decrementGrade(void) {
  if (getGrade() > 149)
    throw GradeTooLowException(
        "Bureaucrat::decrementGrade: grade is too low to be decremented");

  _grade++;
}

void Bureaucrat::signForm(Form &form) const {
  try {
    form.beSigned(*this);
  } catch (const Form::GradeTooLowException &e) {
    std::cerr << getName() << " couldn't sign form  \"" << form.getName()
              << "\" because of his low grade." << std::endl;

    return;
  } catch (const Form::AlreadySignedException &e) {
    std::cerr << getName() << " couldn't sign form \"" << form.getName()
              << "\" because it was already signed." << std::endl;

    return;
  }

  std::cout << getName() << " signed " << form.getName() << std::endl;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void)
    : _message("Bureaucrat: grade too high.") {}

Bureaucrat::GradeTooHighException::GradeTooHighException(
    const std::string &message)
    : _message(message) {}

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
  return (_message.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void)
    : _message("Bureaucrat: grade too low.") {}

Bureaucrat::GradeTooLowException::GradeTooLowException(
    const std::string &message)
    : _message(message) {}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
  return (_message.c_str());
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
  const unsigned int &grade(bureaucrat.getGrade());
  const std::string &name(bureaucrat.getName());

  out << name << ", bureaucrat grade " << grade << '.';

  return (out);
}
