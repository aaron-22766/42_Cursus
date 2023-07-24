/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:47:26 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/22 13:43:19 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

HumanB::~HumanB(void) {}

void	HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void	HumanB::attack(void) const {
	std::cout << this->name << " attacks with their "
		<< this->weapon->getType() << std::endl;
}
