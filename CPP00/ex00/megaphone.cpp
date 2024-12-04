/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:28:33 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/11/01 18:07:06 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <string>

#define DEF_MSG "* LOUD AND UNBEAREABLE FEEDBACK NOISE *"

int	print_message(std::string amplified_message)
{
	std::cout << amplified_message << std::endl;
	return (0);
}

size_t	message_total_lenght(char **argv)
{
	size_t	lenght;

	if (!argv)
		return (0);

	lenght = 0;
	while (argv[lenght])
		lenght ++;
	return (lenght);
}

char	*capitalize(char *str)
{
	int	i;

	if (!str)
		return (NULL);

	i = -1;
	while (str[++i])
		str[i] = toupper(str[i]);
	return (str);
}

size_t	size_of_array(char **argv)
{
	size_t	size;

	if (!argv)
		return (0);

	size = 0;
	while (argv[size])
		size ++;
	return (size);
}

std::string	*convert_parameters_to_strs_array(char **argv)
{
	int			i;
	std::string	*strs;

	if (!argv)
		return (NULL);

	strs = new std::string[size_of_array(argv)];
	if (!strs)
		return (NULL);

	i = -1;
	while (argv[++i])
		strs[i] = std::string(capitalize(argv[i]));
	return (strs);
}

int	main(int argc, char **argv)
{
	std::string	amplified_message;
	std::string	*message_parts;

	if (argc < 2)
		return (print_message(std::string(DEF_MSG)));
	
	message_parts = convert_parameters_to_strs_array(&argv[1]);
	if (!message_parts)
		return (1);

	for (size_t i = 0 ; i < size_of_array(&argv[1]) ; i ++)
		amplified_message.append(message_parts[i]);

	print_message(amplified_message);
	delete[] message_parts;
	return (0);
}
