/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:58:16 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/28 18:42:00 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"
#include <iomanip>

using std::cout;
using std::endl;
using std::stof;

void test(const float ax, const float ay,
          const float bx, const float by,
          const float cx, const float cy,
          const float px, const float py) {
    Point a(ax, ay);
    Point b(bx, by);
    Point c(cx, cy);
    Point p(px, py);

    cout << "▲: a" << a << " b" << b << " c" << c << " ? point" << p << " "
         << (bsp(a, b, c, p) ? "✅" : "❌") << endl;
}

int main(int argc, char *argv[]) {
    if (argc == 9) {
        test(stof(argv[1]), stof(argv[2]), stof(argv[3]), stof(argv[4]),
             stof(argv[5]), stof(argv[6]), stof(argv[7]), stof(argv[8]));
	    return (EXIT_SUCCESS);
    }
    test (93, 2, 2, 72, 70, 81, 44, 68); //inside -> ✅
    test (93, 2, 2, 72, 70, 81, 5, 72); // near edge -> ✅
    test (93, 2, 2, 72, 70, 81, 47.5f, 37); // on edge -> ❌
    test (93, 2, 2, 72, 70, 81, 2, 72); // is vertex -> ❌
    test (93, 2, 2, 72, 70, 81, -2, 72); // outside -> ❌
    cout << endl;
    test (14, 63, 39, 97, 56, 75, 43, 80); //inside -> ✅
    test (14, 63, 39, 97, 56, 75, 33, 69); // near edge -> ✅
    test (14, 63, 39, 97, 56, 75, 45.8, 88.2); // on edge -> ❌
    test (14, 63, 39, 97, 56, 75, 14, 63); // is vertex -> ❌
    test (14, 63, 39, 97, 56, 75, 50, 50); // outside -> ❌
    cout << endl;
    test (5, 88, 8, 95, 94, 13, 19, 81); //inside -> ✅
    test (5, 88, 8, 95, 94, 13, 66, 39); // near edge -> ✅
    test (5, 88, 8, 95, 94, 13, 13.9, 80.1); // on edge -> ❌
    test (5, 88, 8, 95, 94, 13, 94, 13); // is vertex -> ❌
    test (5, 88, 8, 95, 94, 13, 13, 15); // outside -> ❌
	return (EXIT_SUCCESS);
}

// check triangle: https://planetcalc.com/8108/
// generate triangle: https://jsfiddle.net/PerroAZUL/zdaY8/1/
