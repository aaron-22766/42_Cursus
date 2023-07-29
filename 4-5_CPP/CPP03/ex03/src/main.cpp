/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:56:23 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/29 18:05:45 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

int main(void) {
    {
        DiamondTrap person1(DiamondTrap("Elendil"));
        DiamondTrap person2(person1);
        DiamondTrap person3 = person2;
        DiamondTrap elendil;

        elendil = person3;
        elendil.printStats();
        elendil.attack("Sauron");
        elendil.printStats();
        elendil.takeDamage(100);
        elendil.printStats();
        elendil.takeDamage(100);
        elendil.printStats();
    }
    std::cout << std::endl;
    {
        DiamondTrap *aragorn = new DiamondTrap("Aragorn");
    
        aragorn->printStats();
        aragorn->whoAmI();
        delete aragorn;
    }
    return (EXIT_SUCCESS);
}
