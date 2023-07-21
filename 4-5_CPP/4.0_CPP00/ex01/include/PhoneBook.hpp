/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:27:21 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/21 14:25:39 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <iomanip>
# include "../include/Contact.hpp"

/* ************************************************************************** */
/*                                  DEFINES                                   */
/* ************************************************************************** */

# define MAX_CONTACTS 8

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

class PhoneBook {

	public:

		PhoneBook(void);
		~PhoneBook(void);

		Contact	getContact(int index) const;
		int		getContactsCount(void) const;

		void	addContact(void);
		void	searchPhoneBook(void) const;

		static std::string	promptForInput(std::string prompt);

	private:

		Contact	_contacts[MAX_CONTACTS];
		int		_contacts_count;
};

std::ostream	&operator<<(std::ostream &os, const PhoneBook &phonebook);

#endif