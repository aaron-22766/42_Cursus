/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:35:22 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/21 14:24:29 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

std::string	Contact::getFirstName(void) const {
	return (this->_first_name);
}

std::string	Contact::getLastName(void) const {
	return (this->_last_name);
}

std::string	Contact::getNickname(void) const {
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber(void) const {
	return (this->_phone_number);
}

std::string	Contact::getDarkestSecret(void) const {
	return (this->_darkest_secret);
}

void	Contact::newContact(void) {
	this->_first_name = PhoneBook::promptForInput("first name");
	this->_last_name = PhoneBook::promptForInput("last name");
	this->_nickname = PhoneBook::promptForInput("nickname");
	this->_phone_number = PhoneBook::promptForInput("phone number");
	this->_darkest_secret = PhoneBook::promptForInput("darkest secret");
}

std::ostream	&operator<<(std::ostream &os, const Contact &contact) {
	os << "Contact:" << std::endl;
	os << "\tFirst Name:\t" << contact.getFirstName() << std::endl;
	os << "\tLast Name:\t" << contact.getLastName() << std::endl;
	os << "\tNickname:\t" << contact.getNickname() << std::endl;
	os << "\tPhone Number:\t" << contact.getPhoneNumber() << std::endl;
	os << "\tDarkest Secret:\t" << contact.getDarkestSecret() << std::endl;
	return (os);
}
