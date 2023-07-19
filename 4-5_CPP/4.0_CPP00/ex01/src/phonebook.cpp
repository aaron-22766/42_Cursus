/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:50:09 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/19 15:23:47 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook(const std::string name) : pb_name(name) {
	this->contacts_count = 0;
}

PhoneBook::~PhoneBook(void) {}

void	PhoneBook::addContact(void) {
	if (this->contacts_count < MAX_CONTACTS) {
		this->contacts[this->contacts_count].newContact();
	} else {
		this->contacts[MAX_CONTACTS - 1].newContact();
	}
	std::cout << "Successfully added new contact";
	if (this->contacts_count < MAX_CONTACTS) {
		this->contacts_count++;
	} else {
		std::cout << " (last got overwritten)";
	}
	std::cout << std::endl;
}

void	PhoneBook::printPhoneBook(void) const {
	std::cout << std::endl << std::string(45, '-') << std::endl << '|';
	printColumn("Index");
	printColumn("First Name");
	printColumn("Last Name");
	printColumn("Nickname");
	std::cout << std::endl << '|' << std::string(43, '-') << '|' << std::endl;
	for (int i = 0; i < this->contacts_count; i++) {
		this->contacts[i].printTableLine();
	}
	std::cout << std::string(45, '-') << std::endl << std::endl;
}

void	PhoneBook::searchPhoneBook(void) const {
	std::string	input;
	int			index;

	if (this->contacts_count == 0) {
		std::cout << "No Contacts" << std::endl;
		return ;
	}
	this->printPhoneBook();
	while (true) {
		input = promptForInput("contact index");
		index = std::atoi(input.c_str());
		if (isValidInt(input) && index >= 0 && index < this->contacts_count) {
			this->contacts[index].printContact();
			return ;
		}
		std::cout << "Please enter a number in range 0 - "
			<< (this->contacts_count - 1) << std::endl;
	}
}

void	PhoneBook::runPhoneBook(void) {
	std::string	command;

	std::cout << "Welcome to " << this->pb_name << std::endl;
	std::cout << "Available commands: ADD / SEARCH / EXIT" << std::endl;
	do {
		std::cout << this->pb_name << "> ";
		if (!std::getline(std::cin, command)) {
			if (std::cin.eof()) {
				std::cout << "EXIT" << std::endl;
				break;
			}
			error("Error while reading input!");
		}
		trimWhitespace(command);
		if (command == "ADD") {
			this->addContact();
		} else if (command == "SEARCH") {
			this->searchPhoneBook();
		}
	} while (command != "EXIT");
	std::cout << "You left " << this->pb_name << std::endl;
}
