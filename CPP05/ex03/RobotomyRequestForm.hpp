/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:12:29 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/29 16:21:07 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
class RobotomyRequestForm : public AForm {
private:
  std::string _target;

  const std::string &_GetTarget(void) const;

public:
  RobotomyRequestForm(void);
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &other);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
  ~RobotomyRequestForm(void);

  void execute(const Bureaucrat &executor) const;
};
