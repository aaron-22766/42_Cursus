/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:27:52 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/22 10:48:24 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void) {
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Address of string:\t\t" << &string << std::endl;
	std::cout << "Address held by stringPTR:\t" << stringPTR << std::endl;
	std::cout << "Address held by stringREF:\t" << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value of string:\t\t" << string << std::endl;
	std::cout << "Value pointed to by stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF:\t" << stringREF << std::endl;
	return (EXIT_SUCCESS);
}
