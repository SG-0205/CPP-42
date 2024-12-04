/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PB.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:49:49 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/11/01 18:11:12 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PB_H
# define PB_H

# include "PhoneBook.hpp"
# include "Contact.hpp"
# include <stdlib.h>

bool			is_numbers(std::string input);
bool			valid_phone_number(std::string phone_number);
std::string		*ask_contact_details(void);
void			search_contact_in_book(PhoneBook book, char *input_buff);

#endif