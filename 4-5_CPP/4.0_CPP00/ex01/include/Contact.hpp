/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:53:12 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/19 11:38:45 by arabenst         ###   ########.fr       */
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
	void		printContact(void) const;
	void		printTableLine(void) const;

	private:

	void		askForField(std::string field);
	void		printField(std::string field) const;

	static int	_nbContacts;

	int			_index;
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;
};

#endif