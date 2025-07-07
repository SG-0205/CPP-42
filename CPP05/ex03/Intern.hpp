/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:23:32 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/30 18:44:16 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Intern {
private:
  AForm *_makeShrubberyCreationForm(const std::string &target);
  AForm *_makeRobotomyRequestForm(const std::string &target);
  AForm *_makePresidentialPardonForm(const std::string &target);

  const std::string _normalizeFormType(const std::string &raw_form_type);

public:
  Intern(void);
  Intern(const Intern &other);
  Intern &operator=(const Intern &other);
  ~Intern(void);

  AForm *makeForm(const std::string &form_type, const std::string &form_target);
};
