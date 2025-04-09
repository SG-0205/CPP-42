/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:59:53 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/09 13:01:21 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>

int main(void) {

  using namespace utils;

  PhoneBook book;
  std::string *new_fields;
  std::string buffer;

  book = PhoneBook();
  std::cout << "PhoneBook> ";
  while (std::getline(std::cin, buffer) &&
         strcmp(buffer.c_str(), "EXIT") != 0) {
    if (strcmp(buffer.c_str(), "ADD") == 0) {
      new_fields = ask_contact_details();
      try {
        book.addContact(new_fields);
      } catch (const std::invalid_argument &err) {
        std::cerr << err.what() << std::endl;
      }
      delete[] new_fields;
    } else if (strcmp(buffer.c_str(), "SEARCH") == 0) {
      try {
        search_contact_in_book(book);
      } catch (const std::invalid_argument &err) {
        std::cerr << err.what() << std::endl;
      }
    }
    std::cout << "PhoneBook> ";
  }
  return (0);
}
