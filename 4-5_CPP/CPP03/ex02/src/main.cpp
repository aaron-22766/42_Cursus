/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:56:23 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/29 18:02:15 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

int main(void) {
    {
        FragTrap person1(FragTrap("Elendil"));
        FragTrap person2(person1);
        FragTrap person3 = person2;
        FragTrap elendil;

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
        FragTrap *isildur = new FragTrap("Isildur");

        isildur->printStats();
        isildur->takeDamage(50);
        isildur->printStats();
        isildur->beRepaired(25);
        isildur->printStats();
        isildur->takeDamage(50);
        isildur->printStats();
        isildur->attack("Sauron");
        isildur->printStats();
        isildur->takeDamage(20);
        isildur->printStats();
        isildur->attack("Sauron");
        isildur->printStats();
        isildur->attack("Sauron");
        isildur->printStats();
        isildur->takeDamage(10);
        isildur->printStats();
        isildur->beRepaired(25);
        isildur->printStats();
        isildur->attack("Sauron");
        isildur->printStats();
        isildur->highFivesGuys();
        isildur->printStats();
        delete isildur;
    }
    return (EXIT_SUCCESS);
}
