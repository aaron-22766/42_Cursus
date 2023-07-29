/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:54:02 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/29 18:13:33 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

using std::cout;
using std::clog;
using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

DiamondTrap::DiamondTrap(void) {
    clog << "\033[2mDiamondTrap default constructor called\033[0m" << endl;
}

DiamondTrap::DiamondTrap(std::string name) {
    clog << "\033[2mDiamondTrap name constructor called\033[0m" << endl;
    ClapTrap::_name = name + "_clap_name";
    _name = name;
    _health = FragTrap::_health;//100
    _energy = ScavTrap::_energy;//50
    _damage = FragTrap::_damage;//30
    
    
    //////////////////
    // ENERGY WRONG //
    //////////////////
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) {
    clog << "\033[2mDiamondTrap copy constructor called\033[0m" << endl;
    *this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    clog << "\033[2mDiamondTrap copy assignment operator called\033[0m" << endl;
    _name = other.getName();
    _health = other.getHealth();
    _energy = other.getEnergy();
    _damage = other.getDamage();
    return (*this);
}

DiamondTrap::~DiamondTrap(void) {
    clog << "\033[2mDiamondTrap destructor called\033[0m" << endl;
}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

void DiamondTrap::whoAmI(void) const {
    cout << "\033[2mDiamondTrap\033[0m " << _name
         << " goes by the alias " << ClapTrap::_name << "." << endl;
}
