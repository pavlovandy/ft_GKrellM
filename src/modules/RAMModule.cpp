/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 01:48:05 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 08:06:47 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RAMModule.hpp"

RAMModule::RAMModule() {
	while (!readAgain())
		SDL_Delay(1);
}

bool	RAMModule::readAgain() {
	FILE* f = popen("top -l 1 -i 1 -n 0 | awk '/PhysMem:/ {print $2;}'", "r");
	_used = readInfo(f);
	if (_used == "")
		return (false);
	_used = "Used:  " + _used;
	f = popen("top -l 1 -i 1 -n 0 | awk '/PhysMem:/ {print $6;}'", "r");
	_unused = readInfo(f);
	if (_unused == "")
		return (false);
	_unused  = "Unused: " + _unused;
	f = popen("top -l 1 -i 1 -n 0 | awk '/PhysMem:/ {print $4;}'", "r");
	_reserved = readInfo(f).substr(1);
	if (_reserved == "")
		return (false);
	_reserved = "Reserved: " + _reserved;
	return (true);
}

RAMModule::RAMModule( RAMModule const & m ) {
	_used = m._used;
	_unused = m._unused;
	_reserved = m._reserved;
}

RAMModule &	RAMModule::operator=( RAMModule const & m ) {
	_used = m._used;
	_unused = m._unused;
	_reserved = m._reserved;
	return (*this);
}

RAMModule::~RAMModule() {
}

void	RAMModule::displayModule( int & x, Sdl * sdl, TTF_Font * f ) {
	while (!readAgain())
		SDL_Delay(1);
	SDL_Color color = {255, 0, 0, 0};
	SDL_Surface* used_surface = TTF_RenderText_Solid(f, _used.c_str(), color);
	SDL_Surface* unused_surface = TTF_RenderText_Solid(f, _unused.c_str(), color);
	SDL_Surface* reserved_surface = TTF_RenderText_Solid(f, _reserved.c_str(), color);
	SDL_Rect re = {40, x, 100, 40};
	SDL_BlitSurface(used_surface, nullptr, sdl->win_surr, &re);
	x += 30;
	re.y = x;
	re.x = 40;
	SDL_BlitSurface(unused_surface, nullptr, sdl->win_surr, &re);
	x += 30;
	re.y = x;
	re.x = 35;
	SDL_BlitSurface(reserved_surface, nullptr, sdl->win_surr, &re);
	x += 45;
	SDL_FreeSurface(used_surface);
	SDL_FreeSurface(unused_surface);
	SDL_FreeSurface(reserved_surface);
}

void	RAMModule::displayModule( int & x  ) {
	while (!readAgain())
		SDL_Delay(1);
	displayString( x, _used, 4 );
	displayString( x, _unused, 4 );
	displayString( x, _reserved, 4 );
}
