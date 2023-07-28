/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:57:28 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/27 14:55:57 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include <iostream>
# include <cmath>

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

class Fixed {

public:

    Fixed(void);
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed(void);

    int getRawBits(void) const;
    void setRawBits(const int raw);
    int toInt(void) const;
    float toFloat(void) const;

private:

    int _raw;
    static const int _numFractionalBits;

};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif