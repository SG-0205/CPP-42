/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:18:51 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/11/01 18:17:21 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <exception>
# include <stdexcept>
# include <iostream> 
# include <sstream>

class	PhoneBook{

	private:
		Contact				contact_list[8];
		unsigned int		list_iterator;

		void	print_column(std::string field){
			std::string	formatted;

			formatted = field;
			if (formatted.length() > 10)
				formatted.replace(formatted.begin() + 9, formatted.end(), ".\0");
			else
				formatted.insert(formatted.begin(), 10 - formatted.length(), ' ');
			std::cout << std::right << "|" << formatted;
		}
		void	print_search_header(){
			std::string	header[6];

			header[0] = "ID";
			header[1] = "FIRST NAME";
			header[2] = "LAST NAME";
			header[3] = "NICKNAME";
			header[4] = "PHONE NUM";
			header[5] = "SECRET";
			for (int i = 0; i < 6; i++)
				print_column(header[i]);
			std::cout << std::endl;
		}
		void	print_infos(Contact contact)
		{
			std::cout	<< "---------["
						<< contact.get_field(Contact::F_NAME)
						<< " " << contact.get_field(Contact::L_NAME)
						<< "]---------" << std::endl;
			std::cout	<< contact.get_field(Contact::N_NAME) << std::endl;
			std::cout	<< contact.get_field(Contact::PHONE) << std::endl;
			std::cout	<< contact.get_field(Contact::D_SECRET) << std::endl;
			std::cout	<< "------------------" << std::endl;
		}

	public:
		PhoneBook(){
			this->list_iterator = 0;
			}

		PhoneBook operator =(const PhoneBook *other){
			this->list_iterator = other->list_iterator;
			for (int i = 0; i < 8; i++)
				this->contact_list[i] = other->contact_list[i];
			return (*this);
		}
		~PhoneBook(){}
		Contact& operator [](int contact_index){
			if (contact_index < 0 || contact_index > 7)
				throw std::invalid_argument("UNREACHABLE ID");
			return (this->contact_list[contact_index]);
		}

		void	add_contact(std::string inputs[5]){
			if (this->list_iterator == 8)
				this->list_iterator = 0;
			
			try {
				(*this)[this->list_iterator] = Contact(inputs);
				this->list_iterator ++;
				}
			catch (const std::invalid_argument &error)
				{std::cerr << error.what() << std::endl;}
		}

		bool	print_contacts(){
			std::stringstream	int_impression;

			if (this->list_iterator == 0){
				std::cout << "NO CONTACTS IN BOOK" << std::endl;
				return (false);}
			else
				print_search_header();
			for (unsigned int i = 0; i < this->list_iterator; i++){
				int_impression << i;
				print_column(int_impression.str());
				print_column((*this)[i][Contact::F_NAME]);
				print_column((*this)[i][Contact::L_NAME]);
				print_column((*this)[i][Contact::N_NAME]);
				print_column((*this)[i][Contact::PHONE]);
				print_column((*this)[i][Contact::D_SECRET]);
				std::cout << std::endl;
				int_impression.str("");
			}
			return (true);
		}
	
		void	print_contact_infos(int contact_id)
		{
			if (contact_id < 0 || contact_id > 7)
				throw std::invalid_argument("ID OUT OF RANGE [0-7]");
			print_infos((*this)[contact_id]);
		}
};

#endif