/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sdl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:00:41 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/12 18:21:13 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <string>
# include "terminal_colors.hpp"

# ifdef __APPLE__
#  include "../../frameworks/SDL2.framework/Headers/SDL.h"
#  include "../../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
#  include "../../frameworks/SDL2_image.framework/Headers/SDL_image.h"
# else
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_ttf.h>
#  include <SDL2/SDL_image.h>
# endif

struct	Sdl {
	SDL_Window*	win;
	SDL_Surface* win_surr;

	static const int	default_win_w;
	static const int	default_win_h;
	unsigned int	w;
	unsigned int	h;

	Sdl();
	Sdl( unsigned int x, unsigned int y, unsigned int w, unsigned int h );
	~Sdl();

	private:
		Sdl( Sdl const & );
		Sdl &	operator=( Sdl const & );
};

#endif