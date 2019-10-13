/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUInfoModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 01:09:29 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 08:19:29 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPUInfoModule.hpp"

bool	CPUInfoModule::readAgain() {
	FILE* f = popen("sysctl hw.ncpu | sed 's/.*: //'", "r");
	_core_count = readInfo(f);
	if (_core_count == "")
		return (false);
	_core_count = "core count: " + _core_count;
	f = popen("top -l 1 -i 1 -n 0 | awk '/CPU usage:/ {print $3;}'", "r");
	_user = readInfo(f);
	if (_user == "")
		return (false);
	_user =	"user usage: " + _user + '%';
	f = popen("top -l 1 -i 1 -n 0 | awk '/CPU usage:/ {print $5;}'", "r");
	_system = readInfo(f);
	if (_system == "")
		return (false);
	_system =	"system: " + _system + '%';
	f = popen("top -l 1 -i 1 -n 0 | awk '/CPU usage:/ {print $7;}'", "r");
	_idle = readInfo(f);
	if (_idle == "")
		return (false);
	_idle =	"idle: " + _idle + '%';
	f = popen("sysctl -n machdep.cpu.brand_string", "r");
	_system_info = readInfo(f);
	if (_system_info == "")
		return (false);
	return (true);
}

CPUInfoModule::CPUInfoModule() {
	readAgain();
}

CPUInfoModule::CPUInfoModule( CPUInfoModule const & m ) {
	_core_count = m._core_count;
	_user = m._user;
	_system = m._system;
	_idle = m._idle;
	_system_info = m._system_info;
}

CPUInfoModule &	CPUInfoModule::operator=( CPUInfoModule const & m ) {
	_core_count = m._core_count;
	_user = m._user;
	_system = m._system;
	_idle = m._idle;
	_system_info = m._system_info;
	return (*this);
}

CPUInfoModule::~CPUInfoModule() {
	
}

void	CPUInfoModule::displayModule( int & x, Sdl * sdl, TTF_Font * f ) {
	while (!readAgain())
		SDL_Delay(1);
	SDL_Color color = {0, 200, 100, 0};
	SDL_Surface* surface1 = TTF_RenderText_Solid(f, "CPU Info", color);
	SDL_Surface* surface2 = TTF_RenderText_Solid(f, _system.c_str(), color);
	SDL_Surface* surface3 = TTF_RenderText_Solid(f, _user.c_str(), color);
	SDL_Surface* surface4 = TTF_RenderText_Solid(f, _idle.c_str(), color);
	SDL_Rect re = {60, x, 100, 40};
	SDL_BlitSurface(surface1, nullptr, sdl->win_surr, &re);
	x += 30;
	re.y = x;
	re.x = 30;
	SDL_BlitSurface(surface2, nullptr, sdl->win_surr, &re);
	x += 30;
	re.y = x;
	re.x = 30;
	SDL_BlitSurface(surface3, nullptr, sdl->win_surr, &re);
	x += 30;
	re.y = x;
	re.x = 30;
	SDL_BlitSurface(surface4, nullptr, sdl->win_surr, &re);
	x += 45;
	SDL_FreeSurface(surface1);
	SDL_FreeSurface(surface2);
	SDL_FreeSurface(surface3);
	SDL_FreeSurface(surface4);
}

void	CPUInfoModule::displayModule( int & x ) {
	while (!readAgain())
		SDL_Delay(1);
	displayString( x, _system_info, 5 );
	displayString( x, _core_count, 5 );
	displayString( x, _system, 5 );
	displayString( x, _user, 5 );
	displayString( x, _idle, 5 );
}