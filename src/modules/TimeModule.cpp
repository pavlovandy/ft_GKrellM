/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:38:22 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 08:06:57 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TimeModule.hpp"
#include <sstream>

std::string	TimeModule::getData() {
	std::stringstream ss;
	ss << _now->tm_mday << '.' << _now->tm_mon + 1 << '.' << _now->tm_year + 1900;
	return (ss.str());
}

std::string	TimeModule::getTime() {
	std::stringstream ss;
	ss << _now->tm_hour << ':' << _now->tm_min << ':' << _now->tm_sec;
	return (ss.str());
}

std::string	TimeModule::getDayOfWeek() {
	static std::string	days[7] = {"Sun", "Mon", "Tue", "Wed", "Thr", "Fri", "Sat"};
	return (days[_now->tm_wday]);
}

void	TimeModule::upToDate() {
	std::time_t t = std::time(0);
	_now = std::localtime(&t);
}

TimeModule::TimeModule() {
	upToDate();
}

TimeModule::~TimeModule() {}

TimeModule::TimeModule( TimeModule const & m ) {
	*_now = *m._now;
}

TimeModule &	TimeModule::operator=( TimeModule const & m ) {
	*_now = *m._now;
	return (*this);
}

//displays
void	TimeModule::displayModule( int & x, Sdl * sdl, TTF_Font * f ) {
	upToDate();
	SDL_Color color = {0, 0, 0, 0};
	SDL_Surface* date_surface = TTF_RenderText_Solid(f, getData().c_str(), color);
	SDL_Surface* time_surface = TTF_RenderText_Solid(f, getTime().c_str(), color);
	SDL_Surface* day_surface = TTF_RenderText_Solid(f, getDayOfWeek().c_str(), color);
	SDL_Rect re = {60, x, 100, 40};
	SDL_BlitSurface(date_surface, nullptr, sdl->win_surr, &re);
	x += 30;
	re.y = x;
	re.x = 70;
	SDL_BlitSurface(time_surface, nullptr, sdl->win_surr, &re);
	x += 30;
	re.y = x;
	re.x = 80;
	SDL_BlitSurface(day_surface, nullptr, sdl->win_surr, &re);
	x += 45;
	SDL_FreeSurface(date_surface);
	SDL_FreeSurface(time_surface);
	SDL_FreeSurface(day_surface);
}

void	TimeModule::displayModule( int & x ) {
	upToDate();
	displayString( x, getData(), 3 );
	displayString( x, getTime(), 3 );
	displayString( x, getDayOfWeek(), 3 );
}
