/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:20:58 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/29 16:17:07 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
private:
  std::string _target;
  const std::string &GetTarget(void) const;

public:
  ShrubberyCreationForm(void);
  ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
  ~ShrubberyCreationForm(void);

  void execute(const Bureaucrat &executor) const;
};
