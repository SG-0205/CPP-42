/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:16:05 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/30 19:21:02 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
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

  Intern intern;

  Bureaucrat ceo("Bob", 1);

  // Good form request
  AForm *shrub = intern.makeForm("shrubbery creation", "ShrubFile");
  AForm *rob = intern.makeForm("robotomyrequest", "Bill");
  AForm *pres = intern.makeForm("PresidentialPardon", "Zorg");

  std::cout << *shrub << *rob << *pres << std::endl;

  signing_office(ceo, *shrub);
  signing_office(ceo, *rob);
  signing_office(ceo, *pres);
  execution_office(ceo, *shrub);
  execution_office(ceo, *rob);
  execution_office(ceo, *pres);
  // Bad requests
  AForm *bad1 = intern.makeForm("", "Bob");
  AForm *bad2 = intern.makeForm("robotomycreation", "");
  AForm *bad3 = intern.makeForm("wjdoajwdka", "Bob");

  delete shrub;
  delete rob;
  delete pres;

  (void)bad1;
  (void)bad2;
  (void)bad3;

  return (0);
}
