/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:27:52 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/22 16:20:52 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	error(std::string err) {
	std::cerr << "Error: " << err << std::endl;
	std::exit(EXIT_FAILURE);
}

void	replace(std::string filename, std::string s1, std::string s2) {
	if (s1.empty()) {
		error("String to find (s1) cannot be empty");
	}
	std::ifstream	in_file(filename);
	if (in_file.is_open() == false) {
		error("Unable to open input file");
	}
	std::ofstream	out_file(filename + ".replace");
	if (out_file.is_open() == false) {
		in_file.close();
		error("Unable to open/create output file");
	}
	std::string	line;
	size_t		sub;
	while (getline(in_file, line)) {
		while (!line.empty()) {
			sub = line.find(s1);
			if (sub == std::string::npos) {
				break ;
			}
			out_file << line.substr(0, sub) << s2;
			line.erase(0, sub + s1.length());
		}
		out_file << line << std::endl;
	}
	in_file.close();
	out_file.close();
}

int main(int argc, char *argv[]) {
	if (argc != 4)
		error("Expexted parameters: [filename] [s1] [s2]");
	replace(argv[1], argv[2], argv[3]);
	return (EXIT_SUCCESS);
}
