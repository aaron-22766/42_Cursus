/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:51:29 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/24 11:07:54 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include <iostream>
# include <string>

/* ************************************************************************** */
/*                                  DEFINES                                   */
/* ************************************************************************** */

# define NB_LEVELS 4

/* ************************************************************************** */
/*                                   CLASS                                    */
/* ************************************************************************** */

class Harl {

	public:

		Harl(void);
		~Harl(void);

		static int	getLevelIndex(std::string level);
		void		complain(std::string level);

	private:

		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);

		void		(Harl::*_levels[NB_LEVELS])(void);
};

#endif