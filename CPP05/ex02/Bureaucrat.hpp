/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:35:20 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/16 13:53:55 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

#include <exception>
#include <iterator>
#include <string>

class AForm;

class Bureaucrat {
private:
  const std::string _name;
  unsigned int _grade;

  void _checkGrade(void) const;

public:
  Bureaucrat(void);
  Bureaucrat(const std::string &name, const unsigned int &grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);
  ~Bureaucrat(void);

  const std::string &getName(void) const;
  const unsigned int &getGrade(void) const;
  void signForm(AForm &form) const;
  void incrementGrade(void);
  void decrementGrade(void);

  // Specialized std::exceptions
  class GradeTooHighException : public std::exception {
  private:
    std::string _message;

  public:
    GradeTooHighException(void);
    explicit GradeTooHighException(const std::string &message);
    const char *what(void) const throw();
    ~GradeTooHighException(void) throw() {}
  };

  class GradeTooLowException : public std::exception {
  private:
    std::string _message;

  public:
    GradeTooLowException(void);
    explicit GradeTooLowException(const std::string &message);
    const char *what(void) const throw();
    ~GradeTooLowException(void) throw() {}
  };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureacrat);
