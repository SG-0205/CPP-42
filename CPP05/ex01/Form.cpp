/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:39:19 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/16 14:16:41 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <stdexcept>

void Form::_checkGrades(void) const {
  if (_sign_minimal_grade < 1)
    throw GradeTooHighException(
        "Form::_checkGrades: minimal signing grade is too high.");
  else if (_sign_minimal_grade > 150)
    throw GradeTooLowException(
        "Form::_checkGrades: minimal signing grade is too low.");

  if (_execute_minimal_grade < 1)
    throw GradeTooHighException(
        "Form::_checkGrades: minimal execution grade is too high.");
  else if (_execute_minimal_grade > 150)
    throw GradeTooLowException(
        "Form::_checkGrades: minimal execution grade is too low");
}

Form::Form(void)
    : _name("def"), _signed(false), _sign_minimal_grade(150),
      _execute_minimal_grade(150) {}

Form::Form(const std::string &name, const unsigned int &sign_minimal_grade,
           const unsigned int &execute_minimal_grade)
    : _name(name), _signed(false), _sign_minimal_grade(sign_minimal_grade),
      _execute_minimal_grade(execute_minimal_grade) {
  _checkGrades();
}

Form::Form(const Form &other)
    : _name(other.getName()), _signed(other.isSigned()),
      _sign_minimal_grade(other.getMinimalGrade(SIGN)),
      _execute_minimal_grade(other.getMinimalGrade(EXEC)) {
  _checkGrades();
}

Form &Form::operator=(const Form &other) {
  if (this == &other)
    return (*this);

  this->_signed = other.isSigned();

  return (*this);
}

Form::~Form(void) {}

const std::string &Form::getName(void) const { return (_name); }

const unsigned int &Form::getMinimalGrade(const actionId &action) const {
  switch (action) {
  case (SIGN):
    return (_sign_minimal_grade);
    break;
  case (EXEC):
    return (_execute_minimal_grade);
    break;
  default:
    throw std::invalid_argument(
        "Form::getMinimalGrade: invalid action provided.");
    break;
  }

  return (_execute_minimal_grade);
}

const bool &Form::isSigned(void) const { return (_signed); }

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (isSigned())
    throw AlreadySignedException(getName() + " is already signed.");

  const unsigned int &grade(bureaucrat.getGrade());
  const unsigned int &minimal(getMinimalGrade(SIGN));

  if (grade > minimal)
    throw GradeTooLowException("Form::beSigned: " + bureaucrat.getName() +
                               "\'s grade is too low to sign the form " +
                               getName());
  else
    _signed = true;
}

Form::GradeTooHighException::GradeTooHighException(void)
    : _message("Form: grade too high.") {}

Form::GradeTooHighException::GradeTooHighException(const std::string &message)
    : _message(message) {}

const char *Form::GradeTooHighException::what(void) const throw() {
  return (_message.c_str());
}

Form::GradeTooLowException::GradeTooLowException(void)
    : _message("Form: grade too low.") {}

Form::GradeTooLowException::GradeTooLowException(const std::string &message)
    : _message(message) {}

const char *Form::GradeTooLowException::what(void) const throw() {
  return (_message.c_str());
}

Form::AlreadySignedException::AlreadySignedException(void)
    : _message("Form: already signed.") {}

Form::AlreadySignedException::AlreadySignedException(const std::string &message)
    : _message(message) {}

const char *Form::AlreadySignedException::what(void) const throw() {
  return (_message.c_str());
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
  const unsigned int &minimal_signing_grade(form.getMinimalGrade(Form::SIGN));
  const unsigned int &minimal_exec_grade(form.getMinimalGrade(Form::EXEC));
  const std::string &name(form.getName());

  out << "Form " << name << '\n'
      << '\t' << "Minimal signing grade: " << minimal_signing_grade << '\n'
      << '\t' << "Minimal execution grade : " << minimal_exec_grade
      << std::endl;

  return (out);
}
