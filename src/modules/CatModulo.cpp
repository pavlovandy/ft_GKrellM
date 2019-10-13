/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CatModulo.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 04:03:51 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 08:45:01 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CatModulo.hpp"

CatModulo::CatModulo() {}

CatModulo::CatModulo( SDL_Surface *cat_surface ) {
	_cat_surface = SDL_CreateRGBSurfaceWithFormat(0, 200, 120, 32, SDL_PIXELFORMAT_ARGB32);
	if (!_cat_surface)
		exit(1);
	SDL_BlitScaled(cat_surface, nullptr, _cat_surface, nullptr);
	SDL_FreeSurface(cat_surface);
}

CatModulo::CatModulo( CatModulo const & ) {}

CatModulo &	CatModulo::operator=( CatModulo const & ) {
	return *this;
}

CatModulo::~CatModulo() {
	SDL_FreeSurface(_cat_surface);
}
	
void	CatModulo::displayModule( int & x, Sdl * sdl, TTF_Font * f ) {
	static_cast<void>(f);
	SDL_Rect re = {0, x + 10, 200, 120};
	SDL_BlitSurface(_cat_surface, nullptr, sdl->win_surr, &re);
	x += 140;
}

void	CatModulo::displayModule( int & x  )  {
	size_t	prev_pos = 0;
	for ( int i = 0; i < 21; i++)
	{
		size_t pos = _cat.find('\n', prev_pos);
		displayString( x, _cat.substr(prev_pos, pos - prev_pos), 1 );
		prev_pos = pos + 1;
	}
}

std::string		CatModulo::_cat =
"             *     ,MMM8&&&.            *    \n"
"                  MMMM88&&&&&    .           \n"
"                 MMMM88&&&&&&&               \n"
"     *           MMM88&&&&&&&&               \n"
"                 MMM88&&&&&&&&               \n"
"                 'MMM88&&&&&&'               \n"
"                   'MMM8&&&'      *          \n"
"          |\\___/|                            \n"
"          )     (             .         '    \n"
"         =\\     /=                           \n"
"           )===(       *                     \n"
"          /     \\                            \n"
"          |     |                            \n"
"         /       \\                           \n"
"         \\       /                           \n"
"  _/\\_/\\_/\\__  _/_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_\n"
"  |  |  |  |( (  |  |  |  |  |  |  |  |  |  |\n"
"  |  |  |  | ) ) |  |  |  |  |  |  |  |  |  |\n"
"  |  |  |  |(_(  |  |  |  |  |  |  |  |  |  |\n"
"  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n"
"  jgs|  |  |  |  |  |  |  |  |  |  |  |  |  |\n";