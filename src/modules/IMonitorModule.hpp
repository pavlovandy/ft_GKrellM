/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:58:21 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 07:13:15 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include "../other/Sdl.hpp"
# include <algorithm>
# include <cstdio>
# include <curses.h>
# include "../other/functions.hpp"
# define BORDERS_1 "||"
# define BORDERS_2 "||"
# define BORDERS_3 "===================================================================="
# define START_X	4
# define LAST_X		70
# define CENTRE_X	((LAST_X - START_X) / 2 + START_X)

class GraphicDisplay;

class IMonitorModule {
	public:
		virtual 		~IMonitorModule() {}
		virtual void	displayModule( int & x, Sdl * sdl, TTF_Font * f ) = 0;
		virtual void	displayModule( int & x ) = 0;
};

#endif