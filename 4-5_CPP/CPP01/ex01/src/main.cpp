/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:27:52 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/22 09:57:39 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

#define N 5

int	main(void) {
	Zombie	*horde = zombieHorde(N, "Foo");

	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}
	delete[] horde;
	return (EXIT_SUCCESS);
}
