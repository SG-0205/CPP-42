/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:27:30 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/10/31 18:58:27 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <cstring>
# include <string>
# include <stdexcept>

class	Contact{
	//Les donnees/fonctions private ne sont accessibles qu'a l'interieur de la classe.
	private:
		std::string fields[5];

		bool	empty_field(std::string input){
			const char	*field = input.c_str();
			for (int i = 0; field[i]; i++)
				if (!strchr(" \n\t\r\v\0", field[i]))
						return (false);
			return (true);
		}
	//Les fonctions public peuvent etre appelees par toute autre instance utilisant la classe
	public:
		enum	e_contact_field_key{
				F_NAME,
				L_NAME,
				N_NAME,
				PHONE,
				D_SECRET,
		};
	
		Contact(){};
		Contact(std::string inputs[5]) {
			int	i = -1;
			while (++i < 5)
				if (inputs[i].empty() || empty_field(inputs[i]))
					throw std::invalid_argument("EMPTY FIELD BLOCKED CREATION OF CONTACT");
				else
					this->fields[i] = inputs[i];
		}
		Contact operator =(const Contact *other){
			if (this == other)
				throw std::invalid_argument("CAN'T COPY OBJECT INTO ITSELF");
			else
				for (int i = 0; i < 5 ; i++)
					this->fields[i] = other->fields[i];
			return (*this);
		}
		std::string operator [](Contact::e_contact_field_key key){
			return (get_field(key));
		}
		~Contact() {
			for (int i = 0; i < 5 ; i++)
				fields[i].clear();
		}

		std::string get_field(e_contact_field_key key){
			if (key < F_NAME || key > D_SECRET)
				throw std::invalid_argument("NO FIELD FOR THIS KEY");
			else
				return (this->fields[key]);
		}
};

#endif