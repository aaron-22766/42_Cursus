/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:54:02 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/29 17:13:37 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

using std::cout;
using std::clog;
using std::endl;

/* ************************************************************************** */
/*                          PUBLIC: SPECIAL METHODS                           */
/* ************************************************************************** */

FragTrap::FragTrap(void) : ClapTrap() {
    clog << "\033[2mFragTrap default constructor called\033[0m" << endl;
    _health = 100;
    _energy = 100;
    _damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    clog << "\033[2mFragTrap name constructor called\033[0m" << endl;
    _health = 100;
    _energy = 100;
    _damage = 30;
}

FragTrap::FragTrap(const FragTrap &other) {
    clog << "\033[2mFragTrap copy constructor called\033[0m" << endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    clog << "\033[2mFragTrap copy assignment operator called\033[0m" << endl;
    _name = other.getName();
    _health = other.getHealth();
    _energy = other.getEnergy();
    _damage = other.getDamage();
    return (*this);
}

FragTrap::~FragTrap(void) {
    clog << "\033[2mFragTrap destructor called\033[0m" << endl;
}

/* ************************************************************************** */
/*                              PUBLIC: METHODS                               */
/* ************************************************************************** */

void FragTrap::highFivesGuys(void) const {
    cout << "\033[2mFragTrap\033[0m " << _name
         << " wants to high-five all soldiers for winning the battle." << endl;
}
