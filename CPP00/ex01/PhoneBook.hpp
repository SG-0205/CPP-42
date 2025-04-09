/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:18:51 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/09 13:01:58 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

class PhoneBook {

private:
  Contact _contact_list[8];
  unsigned int _list_iterator;

  void _printColumn(const std::string &field) const;
  void _printSearchHeader(void) const;
  void _printInfos(const Contact &contact) const;

public:
  PhoneBook() : _list_iterator(0) {}
  PhoneBook &operator=(const PhoneBook &other);
  const Contact &operator[](const int &contact_index) const;
  void addContact(const std::string inputs[5]);
  bool printContacts(void) const;
  void printContactInfos(const int &contact_id) const;
  ~PhoneBook() {}
};
