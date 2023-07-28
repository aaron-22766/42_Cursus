/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:57:59 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/28 18:46:54 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp" 

const int Fixed::_numFractionalBits = 8;

Fixed::Fixed(void) : _raw(0) {}

Fixed::Fixed(const int value) {
    _raw = value << _numFractionalBits;
}

Fixed::Fixed(const float value) {
	_raw = roundf(value * (1 << _numFractionalBits));
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	this->_raw = other.getRawBits();
	return (*this);
}

bool Fixed::operator<(const Fixed &other) const {
    return (_raw < other.getRawBits());
}

bool Fixed::operator>(const Fixed &other) const {
    return (other < *this);
}

bool Fixed::operator<=(const Fixed &other) const {
    return (!(*this > other));
}

bool Fixed::operator>=(const Fixed &other) const {
    return (!(*this < other));
}

bool Fixed::operator==(const Fixed &other) const {
    return (_raw == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const {
    return (!(*this == other));
}

Fixed Fixed::operator+(void) const {
    return (Fixed(*this));
}

Fixed Fixed::operator-(void) const {
    return (Fixed(*this * -1));
}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed res;

    res.setRawBits(_raw + other.getRawBits());
    return (res);
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed res;

    res.setRawBits(_raw - other.getRawBits());
    return (res);
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed res;

    res.setRawBits((_raw * other.getRawBits()) >> _numFractionalBits);
    return (res);
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed res;

    res.setRawBits((_raw << _numFractionalBits) / other.getRawBits());
    return (res);
}

Fixed &Fixed::operator++(void) {
    this->_raw++;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed res(*this);

    this->_raw++;
    return (res);
}

Fixed &Fixed::operator--(void) {
    this->_raw--;
    return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed res(*this);

    this->_raw--;
    return (res);
}

Fixed::~Fixed(void) {}

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

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (((b < a) ? b : a));
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (((b < a) ? b : a));
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (((b > a) ? b : a));
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (((b > a) ? b : a));
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	return (os << fixed.toFloat());
}
