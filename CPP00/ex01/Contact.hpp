/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:27:30 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/09 13:02:24 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstring>
#include <stdexcept>
#include <string>

class Contact {
  // Les donnees/fonctions private ne sont accessibles qu'a l'interieur de la
  // classe.
private:
  std::string _fields[5];

  bool _emptyField(std::string input) {
    const char *field = input.c_str();
    for (int i = 0; field[i]; i++)
      if (!strchr(" \n\t\r\v\0", field[i]))
        return (false);
    return (true);
  }
  // Les fonctions public peuvent etre appelees par toute autre instance
  // utilisant la classe
public:
  enum e_contact_field_key {
    F_NAME,
    L_NAME,
    N_NAME,
    PHONE,
    D_SECRET,
  };

  Contact() {};
  Contact(const std::string inputs[5]);
  Contact &operator=(const Contact &other);
  const std::string &operator[](const e_contact_field_key &key) const;
  const std::string &operator[](const int &key) const;
  const std::string &getField(const e_contact_field_key &key) const;
  ~Contact() {}
};
