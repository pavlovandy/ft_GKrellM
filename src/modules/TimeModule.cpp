/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:38:22 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/12 20:30:50 by apavlov          ###   ########.fr       */
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

	ss << _now->tm_hour << ':' << _now->tm_min;
	return (ss.str());
}

std::string	TimeModule::getDayOfWeek() {
	static std::string	days[] = {"Mon", "Tue", "Wed", "Thr", "Fri", "Sat", "Sun"};
	return (days[_now->tm_wday - 1]);
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
void	TimeModule::displayModule( Sdl & sdl ) {}

void	TimeModule::displayModule( ) {}
