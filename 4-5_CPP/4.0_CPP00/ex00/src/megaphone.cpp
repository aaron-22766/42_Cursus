/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:34:43 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/17 14:03:01 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	} else {
		for (int i = 1; i < argc; i++) {
			std::string	str = argv[i];
			for (size_t j = 0; j < str.length(); j++)
				std::cout << (char)std::toupper(str.at(j));
		}
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
