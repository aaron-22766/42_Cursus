/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:22:26 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/21 14:22:22 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

void	trimWhitespace(std::string str) {
	str.erase(0, str.find_first_not_of(" \n\t\b\f\r"));
	str.erase(str.find_last_not_of(" \n\t\b\f\r") + 1);
}

static void	runPhoneBook(std::string pb_name = "My Awesome PhoneBook") {
	PhoneBook	phonebook;
	std::string	command;

	std::cout << "Welcome to " << pb_name << std::endl;
	std::cout << "Available commands: ADD / SEARCH / EXIT" << std::endl;
	do {
		std::cout << pb_name << "> ";
		if (!std::getline(std::cin, command)) {
			if (std::cin.eof()) {
				std::cout << "EXIT" << std::endl;
				break;
			}
			std::cerr << "Error while reading input!" << std::endl;
			std::exit(EXIT_FAILURE);
		}
		trimWhitespace(command);
		if (command == "ADD") {
			phonebook.addContact();
		} else if (command == "SEARCH") {
			phonebook.searchPhoneBook();
		}
	} while (command != "EXIT");
	std::cout << "You left " << pb_name << std::endl;
}

int	main(int argc, char *argv[]) {
	if (argc == 1) {
		return (runPhoneBook(), EXIT_SUCCESS);
	}
	for (int i = 1; i < argc; i++) {
		runPhoneBook(argv[i]);
	}
	return (EXIT_SUCCESS);
}
