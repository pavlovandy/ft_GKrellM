/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 01:11:58 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 05:13:08 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

# include <cstdio>
# include <string>
# include <iostream>
# include "terminal_colors.hpp"
# include <ncurses.h>
# include "../modules/IMonitorModule.hpp"

std::string		readInfo( FILE * f );
void	displayString(  int & x, std::string str, int color );

#endif