/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:16:05 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/30 13:21:01 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>
#include <ostream>

static void signing_office(const Bureaucrat &signer, AForm &form) {
  try {
    signer.signForm(form);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl;
}

static void execution_office(const Bureaucrat &executor, AForm &form) {
  try {
    executor.executeForm(form);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl;
}

int main(void) {
  // Good bureaucrats:
  ShrubberyCreationForm shrub("ShrubTest");
  RobotomyRequestForm rob("John");
  PresidentialPardonForm pres("Bob");

  std::cout << GREEN "Forms after construction:" RESET << '\n';
  std::cout << shrub << rob << pres << '\n';

  Bureaucrat ceo("Bill", 5);
  Bureaucrat intern("Bob", 150);

  signing_office(ceo, shrub);

  // Tentative de double signature;
  signing_office(ceo, shrub);

  // Tentative de signature non autorisee
  signing_office(intern, pres);

  // Tentative d'execution sans signature
  execution_office(ceo, pres);

  // Execution valide
  execution_office(ceo, shrub);

  // Test des resultats des formulaires restants

  signing_office(ceo, pres);
  execution_office(ceo, pres);

  signing_office(ceo, rob);
  execution_office(ceo, rob);
  execution_office(ceo, rob);
  execution_office(ceo, rob);
  execution_office(ceo, rob);

  std::cout << shrub << rob << pres << '\n';

  return (0);
}
