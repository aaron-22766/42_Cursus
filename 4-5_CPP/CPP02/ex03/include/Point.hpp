/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:13:03 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/28 16:57:37 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
# define FILE_HPP

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include "Fixed.hpp"

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

class Point {

public:

    Point(void);
    Point(const float x, const float y);
    Point(const Point &other);
    Point &operator=(const Point &other);
    ~Point(void);

    const Fixed &getX(void) const;
    const Fixed &getY(void) const;

private:

    const Fixed _x;
    const Fixed _y;

};

std::ostream &operator<<(std::ostream &os, const Point &point);

/* ************************************************************************** */
/*                                  FUNCTION                                  */
/* ************************************************************************** */

bool bsp(const Point &a, const Point &b, const Point &c, const Point &point);

#endif