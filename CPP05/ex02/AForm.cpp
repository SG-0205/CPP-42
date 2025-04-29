/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::   */
/*   AForm::.cpp                                           :+:      :+:    :+:
 */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:39:19 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/16 14:16:41 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

void AForm::_checkGrades(void) const {
  if (_sign_minimal_grade < 1)
    throw GradeTooHighException(
        "AForm::_checkGrades: minimal signing grade is too high.");
  else if (_sign_minimal_grade > 150)
    throw GradeTooLowException(
        "AForm::_checkGrades: minimal signing grade is too low.");

  if (_execute_minimal_grade < 1)
    throw GradeTooHighException(
        "AForm::_checkGrades: minimal execution grade is too high.");
  else if (_execute_minimal_grade > 150)
    throw GradeTooLowException(
        "AForm::_checkGrades: minimal execution grade is too low");
}

AForm::AForm(void)
    : _name("def"), _signed(false), _sign_minimal_grade(150),
      _execute_minimal_grade(150) {}

AForm::AForm(const std::string &name, const unsigned int &sign_minimal_grade,
             const unsigned int &execute_minimal_grade)
    : _name(name), _signed(false), _sign_minimal_grade(sign_minimal_grade),
      _execute_minimal_grade(execute_minimal_grade) {
  _checkGrades();
}

AForm::AForm(const AForm &other)
    : _name(other.getName()), _signed(other.isSigned()),
      _sign_minimal_grade(other.GetMinimalSigningGrade()),
      _execute_minimal_grade(other.GetMinimalExecutionGrade()) {
  _checkGrades();
}

AForm &AForm::operator=(const AForm &other) {
  if (this == &other)
    return (*this);

  this->_signed = other.isSigned();

  return (*this);
}

AForm::~AForm(void) {}

const std::string &AForm::getName(void) const { return (_name); }

const unsigned int &AForm::GetMinimalExecutionGrade(void) const {
  return (_execute_minimal_grade);
}

const unsigned int &AForm::GetMinimalSigningGrade(void) const {
  return (_sign_minimal_grade);
}

const bool &AForm::isSigned(void) const { return (_signed); }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (isSigned())
    throw AlreadySignedException(getName() + " is already signed.");

  const unsigned int &grade(bureaucrat.getGrade());
  const unsigned int &minimal(GetMinimalSigningGrade());

  if (grade > minimal)
    throw GradeTooLowException("AForm::beSigned: " + bureaucrat.getName() +
                               "\'s grade is too low to sign the form " +
                               getName());
  else
    _signed = true;
}

AForm::GradeTooHighException::GradeTooHighException(void)
    : _message("AForm:: grade too high.") {}

AForm::GradeTooHighException::GradeTooHighException(const std::string &message)
    : _message(message) {}

const char *AForm::GradeTooHighException::what(void) const throw() {
  return (_message.c_str());
}
AForm::GradeTooHighException::~GradeTooHighException(void) throw() {}

AForm::GradeTooLowException::GradeTooLowException(void)
    : _message("AForm:: grade too low.") {}

AForm::GradeTooLowException::GradeTooLowException(const std::string &message)
    : _message(message) {}

const char *AForm::GradeTooLowException::what(void) const throw() {
  return (_message.c_str());
}

AForm::GradeTooLowException::~GradeTooLowException(void) throw() {}

AForm::AlreadySignedException::AlreadySignedException(void)
    : _message("AForm:: already signed.") {}

AForm::AlreadySignedException::AlreadySignedException(
    const std::string &message)
    : _message(message) {}

const char *AForm::AlreadySignedException::what(void) const throw() {
  return (_message.c_str());
}

AForm::AlreadySignedException::~AlreadySignedException(void) throw() {}

AForm::NoSignatureException::NoSignatureException(void)
    : _message("AForm:: form isn't signed.") {}

AForm::NoSignatureException::NoSignatureException(const std::string &message)
    : _message(message) {}

const char *AForm::NoSignatureException::what(void) const throw() {
  return (_message.c_str());
}

AForm::NoSignatureException::~NoSignatureException(void) throw() {}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
  const unsigned int &minimal_signing_grade(form.GetMinimalSigningGrade());
  const unsigned int &minimal_exec_grade(form.GetMinimalExecutionGrade());
  const std::string &name(form.getName());

  out << "AForm:: " << name << '\n'
      << '\t' << "Minimal signing grade: " << minimal_signing_grade << '\n'
      << '\t' << "Minimal execution grade : " << minimal_exec_grade
      << std::endl;

  return (out);
}
