/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:56:23 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/29 15:28:16 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int main(void) {
    {
        ClapTrap fly1(ClapTrap("Moth"));
        ClapTrap fly2(fly1);
        ClapTrap fly3 = fly2;
        ClapTrap moth;

        moth = fly3;
        moth.printStats();
        moth.attack("Sauron");
        moth.printStats();
        moth.takeDamage(100);
        moth.printStats();
        moth.takeDamage(100);
        moth.printStats();
    }
    std::cout << std::endl;
    {
        ClapTrap *butterfly = new ClapTrap("Butterfly");

        butterfly->printStats();
        butterfly->attack("Sauron");
        butterfly->printStats();
        butterfly->attack("Sauron");
        butterfly->printStats();
        butterfly->attack("Sauron");
        butterfly->printStats();
        butterfly->takeDamage(5);
        butterfly->printStats();
        butterfly->attack("Sauron");
        butterfly->printStats();
        butterfly->attack("Sauron");
        butterfly->printStats();
        butterfly->attack("Sauron");
        butterfly->printStats();
        butterfly->beRepaired(1);
        butterfly->printStats();
        butterfly->takeDamage(5);
        butterfly->printStats();
        butterfly->attack("Sauron");
        butterfly->printStats();
        butterfly->attack("Sauron");
        butterfly->printStats();
        butterfly->attack("Sauron");
        butterfly->printStats();
        butterfly->takeDamage(5);
        butterfly->printStats();
        butterfly->takeDamage(5);
        butterfly->printStats();
        delete butterfly;
    }
    return (EXIT_SUCCESS);
}
