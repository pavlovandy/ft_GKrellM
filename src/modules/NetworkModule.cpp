/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 02:30:18 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 08:12:00 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetworkModule.hpp"
#include <sstream>

NetworkModule::NetworkModule() {
	while (!readAgain())
		SDL_Delay(50);
}

NetworkModule::NetworkModule( NetworkModule const & m ) {
	_in = m._in;
	_out = m._out;
}

NetworkModule &	NetworkModule::operator=( NetworkModule const & m ) {
	_in = m._in;
	_out = m._out;
	return (*this);
}

NetworkModule::~NetworkModule() {
}


void	NetworkModule::displayModule( int & x, Sdl * sdl, TTF_Font * f ) {
	while (!readAgain())
		SDL_Delay(10);
	SDL_Color color = {215, 0, 125, 0};
	SDL_Surface* surface2 = TTF_RenderText_Solid(f, _in.c_str(), color);
	SDL_Surface* surface3 = TTF_RenderText_Solid(f, _out.c_str(), color);
	SDL_Surface* surface1 = TTF_RenderText_Solid(f, "Internet", color);
		SDL_Rect re = {50, x, 100, 40};
	SDL_BlitSurface(surface1, nullptr, sdl->win_surr, &re);
	x += 30;
	re.y = x;
	re.x = 50;
	SDL_BlitSurface(surface2, nullptr, sdl->win_surr, &re);
	x += 30;
	re.y = x;
	re.x = 50;
	SDL_BlitSurface(surface3, nullptr, sdl->win_surr, &re);
	x += 45;
	SDL_FreeSurface(surface1);
	SDL_FreeSurface(surface2);
	SDL_FreeSurface(surface3);
}

void	NetworkModule::displayModule( int & x  ) {
	while (!readAgain())
		SDL_Delay(50);
	displayString( x, "in: " + _in, 5 );
	displayString( x, "out: " + _out, 5 );
}

bool	NetworkModule::readAgain() {
	FILE* f = popen("top -l 1 -i 1 -n 0 | awk '/Networks: packets:/ {print $3;}'", "r");
	_in = readInfo(f);
	if (_in == "")
		return (false);
	double lol = atof(_in.c_str());
	lol /= 1000000;

	std::stringstream ss;
	ss << lol;
	_in = "In: " + ss.str() + 'M';
	
	f = popen("top -l 1 -i 1 -n 0 | awk '/Networks: packets:/ {print $3;}'", "r");
	_out = readInfo(f);
	if (_out == "")
		return (false);
	lol = atof(_out.c_str());
	lol /= 1000000;
	ss.str("");
	
	ss << lol;
	_out = "Out: " + ss.str() + 'M';
	return (true);
}
