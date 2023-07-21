/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:27:52 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/21 19:57:51 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int	main(void) {
	Zombie	*Foo;

	Foo = newZombie("Foo");
	Foo->announce();
	randomChump("Bar");
	delete Foo;
	return (EXIT_SUCCESS);
}
