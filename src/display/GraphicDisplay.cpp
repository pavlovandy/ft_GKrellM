/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicDisplay.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:07:34 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/12 20:36:38 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GraphicDisplay.hpp"

GraphicDisplay::GraphicDisplay( unsigned w, unsigned h, unsigned x, unsigned y ) : \
ADisplay("Graphic display"), _w(w), _h(h), _skin(nullptr) {
	 Sdl *	_sdl = new Sdl( x, y, w, h );
}

GraphicDisplay::~GraphicDisplay() {
	if (_skin)
		SDL_FreeSurface(_skin);
	delete _sdl;
}

void	GraphicDisplay::changeSkin( SDL_Surface* skin ) {
	if (!_skin)
		_skin = SDL_CreateRGBSurfaceWithFormat(0, _w, _h, 32, SDL_PIXELFORMAT_ARGB32);
	SDL_BlitScaled(skin, nullptr, _skin, nullptr);
}

void	GraphicDisplay::setFont( TTF_Font* font ) {
	_font = font;
}

//useless
GraphicDisplay::GraphicDisplay() : \
	ADisplay("Graphic display"), _w(0), _h(0), _skin(nullptr) {}

GraphicDisplay &	GraphicDisplay::operator=( GraphicDisplay const & mm ) {
	_w = mm._w;
	_h = mm._h;
}

GraphicDisplay::GraphicDisplay( GraphicDisplay const & mm ) : \
 ADisplay("Graphic display"), _w(mm._w), _h(mm._h), _skin(nullptr) {}
//...



//this should display in sdl window
void	GraphicDisplay::display( ) {
	
}