/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:56:23 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/29 18:02:25 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

int main(void) {
    {
        ScavTrap person1(ScavTrap("Elendil"));
        ScavTrap person2(person1);
        ScavTrap person3 = person2;
        ScavTrap elendil;

        elendil = person3;
        elendil.printStats();
        elendil.attack("Sauron");
        elendil.printStats();
        elendil.guardGate();
        elendil.printStats();
        elendil.takeDamage(100);
        elendil.printStats();
        elendil.takeDamage(100);
        elendil.printStats();
    }
    std::cout << std::endl;
    {
        ScavTrap *anarion = new ScavTrap("Anarion");

        anarion->printStats();
        anarion->attack("Sauron");
        anarion->printStats();
        anarion->takeDamage(50);
        anarion->printStats();
        anarion->attack("Sauron");
        anarion->printStats();
        anarion->takeDamage(50);
        anarion->printStats();
        for (int i = 0; i <= 48; i++) {
            anarion->beRepaired(1);
        }
        anarion->printStats();
        anarion->attack("Sauron");
        anarion->printStats();
        anarion->guardGate();
        anarion->printStats();
        anarion->takeDamage(50);
        anarion->printStats();
        anarion->takeDamage(50);
        anarion->printStats();
        delete anarion;
    }
    return (EXIT_SUCCESS);
}
