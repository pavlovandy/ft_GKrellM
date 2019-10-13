/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserNameModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 20:31:56 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 08:29:33 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserNameModule.hpp"

UserNameModule::UserNameModule() {
	FILE* f = popen("id -F", "r");
	while ((_user_name = readInfo(f)) == "")
		SDL_Delay(2);
	_name_surr = 0;
}

UserNameModule::UserNameModule( UserNameModule const & m ) {
	_user_name = m._user_name;
}

UserNameModule &	UserNameModule::operator=( UserNameModule const & m ) {
	_user_name = m._user_name;
	return (*this);
}

UserNameModule::~UserNameModule() {
	if (_name_surr)
		SDL_FreeSurface(_name_surr);
}

std::string		UserNameModule::getUserName() { return (_user_name); }

//display

void	UserNameModule::displayModule( int & x, Sdl * sdl, TTF_Font * f ) {
	if (_name_surr == 0)
	{
		SDL_Color color = {0, 255, 255, 0};
		_name_surr = TTF_RenderText_Solid(f, \
		_user_name.c_str(), color);
	}
	SDL_Rect re = {50, x, 100, 40};
	SDL_BlitSurface(_name_surr, nullptr, sdl->win_surr, &re);
	x += 45;
}

void	UserNameModule::displayModule( int & x ) {
	displayString( x, _user_name, 1 );
}
