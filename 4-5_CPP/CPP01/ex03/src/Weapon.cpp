/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:42:32 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/22 13:43:31 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {}

Weapon::~Weapon(void) {}

std::string Weapon::getType(void) const {
	return (this->type);
}

void	Weapon::setType(std::string type) {
	this->type = type;
}
