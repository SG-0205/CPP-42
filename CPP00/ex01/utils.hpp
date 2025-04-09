/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:49:49 by sgoldenb          #+#    #+#             */
/*   Updated: 2025/04/09 13:28:25 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PhoneBook.hpp"
#include <stdlib.h>

namespace utils {
bool is_numbers(const std::string &input);
bool valid_phone_number(const std::string &phone_number);
std::string *ask_contact_details(void);
void search_contact_in_book(const PhoneBook &book);
} // namespace utils
