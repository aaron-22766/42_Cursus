/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:23:02 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/28 18:44:47 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

bool bsp(const Point &a, const Point &b, const Point &c, const Point &point) {
    Fixed deno((b.getY() - c.getY()) * (a.getX() - c.getX())
             + (c.getX() - b.getX()) * (a.getY() - c.getY()));
    Fixed bc1(((b.getY() - c.getY()) * (point.getX() - c.getX())
             + (c.getX() - b.getX()) * (point.getY() - c.getY())) / deno);
    Fixed bc2(((c.getY() - a.getY()) * (point.getX() - c.getX())
             + (a.getX() - c.getX()) * (point.getY() - c.getY())) / deno);
    return (bc1 > Fixed(0) && bc1 < Fixed(1)
         && bc2 > Fixed(0) && bc2 < Fixed(1)
         && (Fixed(1) - bc1 - bc2) > Fixed(0));
}
