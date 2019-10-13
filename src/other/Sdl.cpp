/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sdl.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:13:30 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 08:50:49 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Sdl.hpp"

Sdl::Sdl() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cerr << TRED << SDL_GetError() << COLOR_OFF << std::endl;
		exit(1);
	}
	if (!(win = SDL_CreateWindow("gkrellm", SDL_WINDOWPOS_CENTERED, \
		SDL_WINDOWPOS_CENTERED, default_win_w, default_win_h, SDL_WINDOW_SHOWN)))
	{
		std::cerr << TRED << SDL_GetError() << COLOR_OFF << std::endl;
		exit(1);
	}
	if (!(win_surr = SDL_GetWindowSurface(win)))
	{
		std::cerr << TRED << SDL_GetError() << COLOR_OFF << std::endl;
		exit(1);
	}
	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) != (IMG_INIT_PNG | IMG_INIT_JPG))
	{
		std::cerr << TRED << SDL_GetError() << COLOR_OFF << std::endl;
		exit(1);
	}
	if (TTF_Init() == -1) {
		std::cout << "Coudnt init font" << std::endl;
		exit(1);
	}
}

Sdl::Sdl( unsigned int x, unsigned int y, unsigned int w, unsigned int h ) : w(w), h(h) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cerr << TRED << SDL_GetError() << COLOR_OFF << std::endl;
		exit(1);
	}
	if (!(win = SDL_CreateWindow("gkrellm", static_cast<int>(x), static_cast<int>(y), \
					static_cast<int>(w), static_cast<int>(h), SDL_WINDOW_SHOWN)))
	{
		std::cerr << TRED << SDL_GetError() << COLOR_OFF << std::endl;
		exit(1);
	}
	if (!(win_surr = SDL_GetWindowSurface(win)))
	{
		std::cerr << TRED << SDL_GetError() << COLOR_OFF << std::endl;
		exit(1);
	}
	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) != (IMG_INIT_PNG | IMG_INIT_JPG))
	{
		std::cerr << TRED << SDL_GetError() << COLOR_OFF << std::endl;
		exit(1);
	}
	if (TTF_Init() == -1) {
		std::cout << "Coudnt init font" << std::endl;
		exit(1);
	}
}

Sdl::~Sdl() {
	SDL_FreeSurface(win_surr);
	win_surr = 0;
	SDL_DestroyWindow(win);
	win = 0;
	TTF_Quit();
	SDL_Quit();
}

const int	Sdl::default_win_w = 200;
const int	Sdl::default_win_h = 800;