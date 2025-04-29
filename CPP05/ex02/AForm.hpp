/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:27:35 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/29 13:29:30 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

#include <cerrno>
#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

class AForm {
private:
  const std::string _name;
  bool _signed;
  const unsigned int _sign_minimal_grade;
  const unsigned int _execute_minimal_grade;

  void _checkGrades(void) const;

public:
  AForm(void);
  AForm(const std::string &name, const unsigned int &sign_minimal_grade,
        const unsigned int &execute_minimal_grade);
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);
  virtual ~AForm(void);

  const std::string &getName(void) const;
  const unsigned int &GetMinimalSigningGrade(void) const;
  const unsigned int &GetMinimalExecutionGrade(void) const;
  const bool &isSigned(void) const;
  void beSigned(const Bureaucrat &bureaucrat);
  virtual void execute(const Bureaucrat &executor) const = 0;

  class GradeTooHighException : public std::exception {
  private:
    std::string _message;

  public:
    GradeTooHighException(void);
    explicit GradeTooHighException(const std::string &message);
    const char *what(void) const throw();
    ~GradeTooHighException(void) throw();
  };

  class GradeTooLowException : public std::exception {
  private:
    std::string _message;

  public:
    GradeTooLowException(void);
    explicit GradeTooLowException(const std::string &message);
    const char *what(void) const throw();
    ~GradeTooLowException(void) throw();
  };

  class AlreadySignedException : public std::exception {
  private:
    std::string _message;

  public:
    AlreadySignedException(void);
    explicit AlreadySignedException(const std::string &message);
    const char *what(void) const throw();
    ~AlreadySignedException(void) throw();
  };

  class NoSignatureException : public std::exception {
  private:
    std::string _message;

  public:
    NoSignatureException(void);
    explicit NoSignatureException(const std::string &message);
    const char *what(void) const throw();
    ~NoSignatureException(void) throw();
  };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);
