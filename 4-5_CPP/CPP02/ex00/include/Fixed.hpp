/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:57:28 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/25 14:09:58 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include <iostream>

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

class Fixed {

public:

	Fixed(void);
	Fixed(const Fixed &other);
	Fixed &operator = (const Fixed &other);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(const int raw);

private:

	int _raw;
	static const int _numFractionalBits;

};

#endif