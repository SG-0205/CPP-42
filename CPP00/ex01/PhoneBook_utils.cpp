/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:52:08 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/09 13:27:56 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <iostream>
#include <string>

bool utils::is_numbers(const std::string &input) {
  for (int i = 0; input[i]; i++)
    if (!isdigit(input[i]))
      return (false);
  return (true);
}

bool utils::valid_phone_number(const std::string &phone_number) {
  if (std::cin.eof())
    return (true);
  if (phone_number.empty())
    return (false);
  else if (phone_number[0] == '+' &&
           (!is_numbers(phone_number) || phone_number.length() < 4 ||
            phone_number.length() > 17))
    return (false);
  else if (!is_numbers(phone_number) || phone_number.length() < 2 ||
           phone_number.length() > 15)
    return (false);
  return (true);
}

std::string *utils::ask_contact_details(void) {
  std::string *fields;

  fields = new std::string[5];
  std::cout << "Contact details...\n> First name?\t";
  std::getline(std::cin, fields[0]);
  std::cout << "> Last name?\t";
  std::getline(std::cin, fields[1]);
  std::cout << "> Nickname?\t";
  std::getline(std::cin, fields[2]);
  std::cout << "> Phone number?\t";
  std::getline(std::cin, fields[3]);
  while (!valid_phone_number(fields[3])) {
    std::cout << "Please give a valid phone number." << std::endl;
    std::cout << "> Phone number?\t";
    std::getline(std::cin, fields[3]);
  }
  std::cout << "> Secret?\t";
  std::getline(std::cin, fields[4]);

  return (fields);
}

void utils::search_contact_in_book(const PhoneBook &book) {
  if (!book.printContacts())
    return;
  std::string buffer;

  std::cout << "Choose a contact id: ";
  std::getline(std::cin, buffer);
  while (!is_numbers(buffer)) {
    std::cout << "Please give a numeric id.\nChoose a contact id: ";
    std::getline(std::cin, buffer);
    if (buffer.length() > 1)
      throw std::invalid_argument("INVALID SEARCH ID");
  }
  book.printContactInfos(atoi(buffer.c_str()));
}
