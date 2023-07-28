/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:57:59 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/27 15:31:07 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp" 

const int Fixed::_numFractionalBits = 8;

Fixed::Fixed(void) : _raw(0) {
	std::clog << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::clog << "Int constructor called" << std::endl;
    _raw = value << _numFractionalBits;
}

Fixed::Fixed(const float value) {
	std::clog << "Float constructor called" << std::endl;
	_raw = roundf(value * (1 << _numFractionalBits));
}

Fixed::Fixed(const Fixed &other) {
	std::clog << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::clog << "Copy assignment operator called" << std::endl;
	_raw = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(void) {
    std::clog << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	return (_raw);
}

void Fixed::setRawBits(const int raw) {
	_raw = raw;
}

int Fixed::toInt(void) const {
    return (roundf(toFloat()));
}

float Fixed::toFloat(void) const {
    return ((float)_raw / (1 << _numFractionalBits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	return (os << fixed.toFloat());
}
