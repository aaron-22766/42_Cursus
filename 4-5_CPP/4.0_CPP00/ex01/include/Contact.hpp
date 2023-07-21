/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:53:12 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/21 12:59:10 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

class Contact {

	public:

		Contact(void);
		~Contact(void);

		void		newContact(void);

		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickname(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getDarkestSecret(void) const;

	private:

		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
};

std::ostream	&operator<<(std::ostream &os, const Contact &contact);

#endif