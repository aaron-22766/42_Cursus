/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:22:26 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/19 15:22:44 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

int	main(void) {
	PhoneBook	phonebook("My Awesome PhoneBook");

	phonebook.runPhoneBook();
	return (EXIT_SUCCESS);
}
