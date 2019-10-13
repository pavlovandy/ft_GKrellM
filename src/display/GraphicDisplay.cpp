/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicDisplay.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:07:34 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 08:48:54 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GraphicDisplay.hpp"

GraphicDisplay::GraphicDisplay( unsigned w, unsigned h, unsigned x, unsigned y ) : \
ADisplay("Graphic display"), _w(w), _h(h), _skin(nullptr) {
	_sdl = new Sdl( x, y, w, h );

	_font = TTF_OpenFont("resources/fonts/Amatic-Bold.ttf", 35);
	if(!_font) {
		std::cout << TRED << "There is no font that i needed" << COLOR_OFF << std::endl;
		exit(1);
	}
		
	SDL_Surface* skin = IMG_Load("resources/skins/second.jpg");
	if (!skin) {
		std::cout << TRED << "There is no skin that i needed" << COLOR_OFF << std::endl;
		exit(1);
	}
	changeSkin(skin);
	SDL_FreeSurface(skin);
}

GraphicDisplay::~GraphicDisplay() {
	if (_skin)
		SDL_FreeSurface(_skin);
	delete _sdl;
}

void	GraphicDisplay::changeSkin( SDL_Surface* skin ) {
	if (!_skin)
		_skin = SDL_CreateRGBSurfaceWithFormat(0, static_cast<int>(_w), static_cast<int>(_h), 32, SDL_PIXELFORMAT_ARGB32);
	SDL_BlitScaled(skin, nullptr, _skin, nullptr);
}

void	GraphicDisplay::setFont( TTF_Font* font ) {
	_font = font;
}

TTF_Font*	GraphicDisplay::getFont( void ) {
	return _font;
}

//useless
GraphicDisplay::GraphicDisplay() : \
	ADisplay("Graphic display"), _w(0), _h(0), _skin(nullptr) {}

GraphicDisplay &	GraphicDisplay::operator=( GraphicDisplay const & mm ) {
	_w = mm._w;
	_h = mm._h;
	return (*this);
}

GraphicDisplay::GraphicDisplay( GraphicDisplay const & mm ) : \
 ADisplay("Graphic display"), _w(mm._w), _h(mm._h), _skin(nullptr) {}
//...

//this should display in sdl window
void	GraphicDisplay::display( ) {
	std::list<IMonitorModule*>::iterator it;
	int		curr_x = 0;

	SDL_BlitSurface(_skin, nullptr, _sdl->win_surr, nullptr);

	for (it = _list.begin(); it != _list.end(); it++)
		(*it)->displayModule( curr_x, _sdl, _font );
	SDL_UpdateWindowSurface(_sdl->win);
}

void	GraphicDisplay::Sdl_loop() {
	int	quit = 0;
	SDL_Event ev;

	while (!quit) {
		display();
		while (SDL_PollEvent(&ev) > 0)
		{
			if (ev.type == SDL_QUIT)
			{
				std::cout << TGRE << "See you..." << COLOR_OFF << std::endl;
				quit = 1;
			}
			else if (ev.type == SDL_KEYDOWN)
			{
				if (ev.key.keysym.sym == SDLK_ESCAPE || ev.key.keysym.sym == SDLK_q)
				{
					std::cout << TGRE << "See you..." << COLOR_OFF << std::endl;
					quit = 1;
				}
			}
		}
	}
}