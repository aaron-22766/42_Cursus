/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:35:22 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/19 11:52:29 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

int	Contact::_nbContacts = 0;

Contact::Contact(void) {
	this->_index = Contact::_nbContacts++;
}

Contact::~Contact(void) {
	Contact::_nbContacts--;
}

void	Contact::askForField(std::string field) {
	if (field == "first name") {
		this->_first_name = promptForInput(field);
	} else if (field == "last name") {
		this->_last_name = promptForInput(field);
	} else if (field == "nickname") {
		this->_nickname = promptForInput(field);
	} else if (field == "phone number") {
		this->_phone_number = promptForInput(field);
	} else if (field == "darkest secret") {
		this->_darkest_secret = promptForInput(field);
	}
}

void	Contact::newContact(void) {
	this->askForField("first name");
	this->askForField("last name");
	this->askForField("nickname");
	this->askForField("phone number");
	this->askForField("darkest secret");
}

void	Contact::printField(std::string field) const {
	std::cout << "\t" << field << ":\t";
	if (field == "First Name") {
		std::cout << this->_first_name;
	} else if (field == "Last Name") {
		std::cout << this->_last_name;
	} else if (field == "Nickname") {
		std::cout << this->_nickname;
	} else if (field == "Phone Number") {
		std::cout << this->_phone_number;
	} else if (field == "Darkest Secret") {
		std::cout << this->_darkest_secret;
	}
	std::cout << std::endl;
}

void	Contact::printContact(void) const {
	
	std::cout << std::endl << "Contact:" << std::endl;
	printField("First Name");
	printField("Last Name");
	printField("Nickname");
	printField("Phone Number");
	printField("Darkest Secret");
	std::cout << std::endl;
}

void	Contact::printTableLine(void) const {
	std::cout << '|';
	printColumn(std::to_string(this->_index));
	printColumn(this->_first_name);
	printColumn(this->_last_name);
	printColumn(this->_nickname);
	std::cout << std::endl;
}
