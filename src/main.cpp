/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:40:54 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/12 13:58:32 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

# ifdef __APPLE__
#  include "../frameworks/SDL2.framework/Headers/SDL.h"
#  include "../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
# else
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_ttf.h>
# endif

int		error_message( char * str)
{
	std::cerr << str << std::endl;
	return (1);
}

int		main() {
	
	SDL_Window *win;
	SDL_Surface *win_surr;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return (error_message((char *)SDL_GetError()));
	if (!(win = SDL_CreateWindow("gkrellm", SDL_WINDOWPOS_CENTERED, \
		SDL_WINDOWPOS_CENTERED, 100, 800, SDL_WINDOW_SHOWN)))
		return (error_message((char *)SDL_GetError()));
	if (!(win_surr = SDL_GetWindowSurface(win)))
		return (error_message((char *)SDL_GetError()));

	SDL_UpdateWindowSurface(win);

	SDL_FreeSurface(win_surr);
	win_surr = 0;
	SDL_DestroyWindow(win);
	win = 0;
	SDL_Quit();

	return (0);
}