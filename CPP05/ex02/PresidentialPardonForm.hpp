/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:48:44 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/29 16:51:02 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
private:
  std::string _target;
  const std::string &GetTarget(void) const;

public:
  PresidentialPardonForm(void);
  PresidentialPardonForm(const std::string &target);
  PresidentialPardonForm(const PresidentialPardonForm &other);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
  ~PresidentialPardonForm(void);

  void execute(const Bureaucrat &executor) const;
};
