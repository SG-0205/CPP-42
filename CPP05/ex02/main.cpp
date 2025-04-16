/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:16:05 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/16 14:26:36 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <ostream>

int main(void) {
  // Good bureaucrats:
  const Bureaucrat ceo("Bob", 1);
  const Bureaucrat manager("Jack", 100);
  const Bureaucrat junior("John", 150);

  const Bureaucrat cfo(ceo);
  const Bureaucrat hr(manager);
  const Bureaucrat employee(junior);

  std::cout << ceo << '\n' << manager << '\n' << junior << std::endl;
  std::cout << "---Copies---\n"
            << cfo << '\n'
            << hr << '\n'
            << employee << std::endl;

  try {
    Bureaucrat president("Jill", 0);
    // Ici on s'attend a une note trop haute
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Bureaucrat external("Max", 151);
    // Ici une note trop basse
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Bureaucrat random("jwdlkj", 100000);
    // Par principe d'heritage l'exception specialisee reste une std::exception
  } catch (const std::exception &error) {
    std::cerr << error.what() << std::endl;
  }

  std::cout << "\n-----EX01-----" << std::endl;

  Form merge("Merging contract", 2, 1);
  Form meeting_recap("Meeting recap", 50, 50);
  Form notice("Random notice", 150, 150);

  std::cout << merge << '\n' << meeting_recap << '\n' << notice << std::endl;

  ceo.signForm(merge);
  ceo.signForm(merge);
  ceo.signForm(notice);

  junior.signForm(meeting_recap);
  junior.signForm(meeting_recap);

  return (0);
}
