/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:02:51 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/11/01 00:06:52 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PB.hpp"

int	main(void)
{
	PhoneBook	book;
	std::string	*new_fields;
	char		input[8];

	book = PhoneBook();
	std::cout << "PhoneBook> ";
	while (std::cin.getline(input, 7) && strcmp(input, "EXIT") != 0)
	{
		if (strcmp(input, "ADD") == 0)
		{
			new_fields = ask_contact_details();
			try {book.add_contact(new_fields);}
			catch (const std::invalid_argument &err)
			{std::cerr << err.what() << std::endl;}
			delete[] new_fields;
		}
		else if (strcmp(input, "SEARCH") == 0)
		{
			try {search_contact_in_book(book, input);}
			catch (const std::invalid_argument &err)
			{std::cerr << err.what() << std::endl;}
		}
		std::cout << "PhoneBook> ";
	}
	return (0);
}

//TODO REGLER PROBLEMES A LA COMPILATION