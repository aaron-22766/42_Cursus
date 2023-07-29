/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:50:52 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/29 10:43:52 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include <iostream>
# include <string>

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

class ClapTrap {

public:

    ClapTrap(void);
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &other);
    ClapTrap &operator=(const ClapTrap &other);
    ~ClapTrap(void);
    
    std::string getName(void) const;
    unsigned int getHealth(void) const;
    unsigned int getEnergy(void) const;
    unsigned int getDamage(void) const;

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void printStats(void) const;

private:

    std::string _name;
    unsigned int _health;
    unsigned int _energy;
    unsigned int _damage;

};

#endif