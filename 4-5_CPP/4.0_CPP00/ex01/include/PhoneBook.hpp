/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:27:21 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/19 13:45:30 by arabenst         ###   ########.fr       */
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

	PhoneBook(const std::string name);
	~PhoneBook(void);
	
	void				runPhoneBook(void);

	private:
	
	void				addContact(void);
	void				searchPhoneBook(void) const;
	void				printPhoneBook(void) const;

	const std::string	pb_name;
	Contact				contacts[MAX_CONTACTS];
	int					contacts_count;
};

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

std::string	promptForInput(std::string prompt);
bool		isValidInt(const std::string &str);
void		printColumn(std::string content);
void		error(std::string err);

#endif