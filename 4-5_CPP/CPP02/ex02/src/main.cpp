/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:58:16 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/27 21:30:57 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <iomanip>

using std::cout;
using std::endl;
using std::left;
using std::setw;
using std::boolalpha;
using std::stof;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        Fixed a(0);
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
        cout << a << endl;
        cout << ++a << endl;
        cout << a << endl;
        cout << a++ << endl;
        cout << a << endl;
        cout << b << endl;
        cout << Fixed::max( a, b ) << endl;
	    return (EXIT_SUCCESS);
    }
    Fixed a(stof(argv[1]));
    const Fixed b(stof(argv[2]));
    
    cout << setw(10) << left << a << " ++pre : " << setw(10) << left << ++a
        << " -> " << setw(10) << left << a << endl;
    cout << setw(10) << left << a << " --pre : " << setw(10) << left << --a
        << " -> " << setw(10) << left << a << endl;
    cout << setw(10) << left << a << " post++: " << setw(10) << left << a++
        << " -> " << setw(10) << left << a << endl;
    cout << setw(10) << left << a << " post--: " << setw(10) << left << a--
        << " -> " << setw(10) << left << a << endl;
    cout << endl;

    cout << a << " >  " << b << " ? " << boolalpha << (a > b) << endl;
    cout << a << " <  " << b << " ? " << boolalpha << (a < b) << endl;
    cout << a << " >= " << b << " ? " << boolalpha << (a >= b) << endl;
    cout << a << " <= " << b << " ? " << boolalpha << (a <= b) << endl;
    cout << a << " == " << b << " ? " << boolalpha << (a == b) << endl;
    cout << a << " != " << b << " ? " << boolalpha << (a != b) << endl;
    cout << endl;
    
    cout << "min(" << a << ", " << b << ") = " << Fixed::min(a, b) << endl;
    cout << "max(" << a << ", " << b << ") = " << Fixed::max(a, b) << endl << endl;
    
    cout << a << " + " << b << " = " << (a + b) << endl;
    cout << a << " - " << b << " = " << (a - b) << endl;
    cout << a << " * " << b << " = " << (a * b) << endl;
    cout << a << " / " << b << " = " << (a / b) << endl;
	return (EXIT_SUCCESS);
}
