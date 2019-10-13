/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:11:59 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 08:06:50 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "OSInfoModule.hpp"


OSInfoModule::OSInfoModule() {
	FILE* f = popen("sw_vers -productName", "r");
	while ((_os_name = readInfo(f)) == "")
		SDL_Delay(2);
	f = popen("sw_vers -productVersion", "r");
	while ((_os_version = readInfo(f)) == "")
		SDL_Delay(2);
	f = popen("sw_vers -buildVersion", "r");
	while ((_os_build = readInfo(f)) == "")
		SDL_Delay(2);
}

OSInfoModule::OSInfoModule( OSInfoModule const & m ) {
	_os_name = m._os_name;
	_os_version = m._os_version;
	_os_build = m._os_build;
}

OSInfoModule &	OSInfoModule::operator=( OSInfoModule const & m ) {
	_os_name = m._os_name;
	_os_version = m._os_version;
	_os_build = m._os_build;
	return (*this);
}

OSInfoModule::~OSInfoModule() { _os_name.clear(); }

void	OSInfoModule::displayModule( int & x, Sdl * sdl, TTF_Font * f ){
	SDL_Color color = {255, 0, 255, 0};
	SDL_Surface* surface1 = TTF_RenderText_Solid(f, _os_name.c_str(), color);
	SDL_Surface* surface2 = TTF_RenderText_Solid(f, _os_version.c_str(), color);
	SDL_Surface* surface3 = TTF_RenderText_Solid(f, _os_build.c_str(), color);
	SDL_Rect re = {60, x, 100, 40};
	SDL_BlitSurface(surface1, nullptr, sdl->win_surr, &re);
	x += 30;
	re.y = x;
	re.x = 63;
	SDL_BlitSurface(surface2, nullptr, sdl->win_surr, &re);
	x += 30;
	re.y = x;
	re.x = 65;
	SDL_BlitSurface(surface3, nullptr, sdl->win_surr, &re);
	x += 45;
	SDL_FreeSurface(surface1);
	SDL_FreeSurface(surface2);
	SDL_FreeSurface(surface3);
}

void	OSInfoModule::displayModule( int & x  ) {
	displayString( x, _os_name, 4 );
	displayString( x, _os_version, 4 );
	displayString( x, _os_build, 4 );
}
