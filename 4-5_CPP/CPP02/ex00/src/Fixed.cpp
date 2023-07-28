/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:57:59 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/25 14:57:37 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

const int Fixed::_numFractionalBits = 8;

Fixed::Fixed(void) : _raw(0) {
	std::clog << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::clog << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator = (const Fixed &other) {
	std::clog << "Copy assignment operator called" << std::endl;
	_raw = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(void) {
	std::clog << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::clog << "getRawBits member function called" << std::endl;
	return (_raw);
}

void Fixed::setRawBits(const int raw) {
	std::clog << "setRawBits member function called" << std::endl;
	_raw = raw;
}
