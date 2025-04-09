/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:02:51 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/09 13:01:39 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>

void PhoneBook::_printColumn(const std::string &field) const {
  std::string formatted;

  formatted = field;
  if (formatted.length() > 10)
    formatted.replace(formatted.begin() + 9, formatted.end(), ".\0");
  else
    formatted.insert(formatted.begin(), 10 - formatted.length(), ' ');
  std::cout << std::right << "|" << formatted;
}

void PhoneBook::_printSearchHeader(void) const {
  std::string header[6];

  header[0] = "ID";
  header[1] = "FIRST NAME";
  header[2] = "LAST NAME";
  header[3] = "NICKNAME";
  header[4] = "PHONE NUM";
  header[5] = "SECRET";
  for (int i = 0; i < 6; i++)
    _printColumn(header[i]);
  std::cout << std::endl;
}
void PhoneBook::_printInfos(const Contact &contact) const {
  std::cout << "---------[" << contact.getField(Contact::F_NAME) << " "
            << contact.getField(Contact::L_NAME) << "]---------" << std::endl;
  std::cout << contact.getField(Contact::N_NAME) << std::endl;
  std::cout << contact.getField(Contact::PHONE) << std::endl;
  std::cout << contact.getField(Contact::D_SECRET) << std::endl;
  std::cout << "------------------" << std::endl;
}

PhoneBook &PhoneBook::operator=(const PhoneBook &other) {
  this->_list_iterator = other._list_iterator;
  for (int i = 0; i < 8; i++)
    this->_contact_list[i] = other._contact_list[i];
  return (*this);
}

const Contact &PhoneBook::operator[](const int &contact_index) const {
  if (contact_index < 0 || contact_index > 7)
    throw std::invalid_argument("UNREACHABLE ID");
  return (_contact_list[contact_index]);
}

void PhoneBook::addContact(const std::string inputs[5]) {
  if (_list_iterator == 8)
    _list_iterator = 0;

  try {
    _contact_list[_list_iterator] = Contact(inputs);
    _list_iterator++;
  } catch (const std::invalid_argument &error) {
    std::cerr << error.what() << std::endl;
  }
}

void PhoneBook::printContactInfos(const int &contact_id) const {
  if (contact_id < 0 || contact_id > 7)
    throw std::invalid_argument("ID OUT OF RANGE [0-7]");
  _printInfos((*this)[contact_id]);
}

bool PhoneBook::printContacts(void) const {
  std::stringstream int_impression;

  if (this->_list_iterator == 0) {
    std::cout << "NO CONTACTS IN BOOK" << std::endl;
    return (false);
  } else
    _printSearchHeader();
  for (unsigned int i = 0; i < this->_list_iterator; i++) {
    int_impression << i;
    _printColumn(int_impression.str());
    _printColumn((*this)[i][Contact::F_NAME]);
    _printColumn((*this)[i][Contact::L_NAME]);
    _printColumn((*this)[i][Contact::N_NAME]);
    _printColumn((*this)[i][Contact::PHONE]);
    _printColumn((*this)[i][Contact::D_SECRET]);
    std::cout << std::endl;
    int_impression.str("");
    int_impression.clear();
  }
  return (true);
}
// TODO REGLER PROBLEMES A LA COMPILATION
