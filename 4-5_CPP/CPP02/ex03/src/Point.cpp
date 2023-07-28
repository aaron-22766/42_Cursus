/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:16:37 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/28 17:32:44 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(const Point &other) : _x(other.getX()), _y(other.getY()) {}

Point &Point::operator=(const Point &other) {
    this->~Point();
    new(this) Point(other);
	return (*this);
}

Point::~Point(void) {}

const Fixed &Point::getX(void) const {
    return (_x);
}

const Fixed &Point::getY(void) const {
    return (_y);
}

std::ostream &operator<<(std::ostream &os, const Point &point) {
    return (os << "(" << point.getX() << "|" << point.getY() << ")");
}
