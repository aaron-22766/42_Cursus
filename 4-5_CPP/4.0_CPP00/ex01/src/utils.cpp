/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:00:20 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/19 13:53:12 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

std::string	promptForInput(std::string prompt) {
	std::string	input;

	while (true) {
		std::cout << "Enter " << prompt << ": ";
		if (!getline(std::cin, input)) {
			if (std::cin.eof()) {
				std::exit(EXIT_SUCCESS);
			}
			error("Error while reading input!");
		}
		if (input.empty()) {
			std::cout << "Field cannot be empty!" << std::endl;
		} else {
			return (input);
		}
	}
}

bool	isValidInt(const std::string &str) {
	for (size_t i = (str[0] == '+' || str[0] == '-'); i < str.length(); i++) {
		if (!std::isdigit(str[i])) {
			return (false);
		}
	}
	return (true);
}

void	printColumn(std::string content) {
	if (content.length() > 10) {
		std::cout << content.substr(0, 9) << '.';
	} else {
		std::cout << std::setfill(' ') << std::setw(10) << content;
	}
	std::cout << '|';
}

void	error(std::string err) {
	std::cerr << err << std::endl;
	std::exit(EXIT_FAILURE);
}
