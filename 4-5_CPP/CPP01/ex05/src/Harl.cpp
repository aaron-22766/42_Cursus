/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:42:32 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/24 11:13:33 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

Harl::Harl(void) {
	_levels[0] = &Harl::debug;
	_levels[1] = &Harl::info;
	_levels[2] = &Harl::warning;
	_levels[3] = &Harl::error;
}

Harl::~Harl(void) {}

int	Harl::getLevelIndex(std::string level) {
	std::string	level_names[NB_LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < NB_LEVELS; i++) {
		if (level == level_names[i]) {
			return (i);
		}
	}
	return (-1);
}

void	Harl::complain(std::string level) {
	(this->*_levels[Harl::getLevelIndex(level)])();
	std::cout << std::endl;
}

void	Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
