/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:27:52 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/24 11:11:03 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int main(int argc, char *argv[])
{
	Harl		harl;

	if (argc != 2) {
		std::cerr << "Error! Wrong number of arguments. Expected: 1" << std::endl;
		return (EXIT_FAILURE);
	}
	harl.complainFiltered(argv[1]);
	return (EXIT_SUCCESS);
}
