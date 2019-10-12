/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserNameModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 20:31:56 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/12 20:33:17 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserNameModule.hpp"

UserNameModule::UserNameModule() {
	
}

UserNameModule::UserNameModule( UserNameModule const & m ) {
	_user_name = m._user_name;
}

UserNameModule &	UserNameModule::operator=( UserNameModule const & m ) {
	_user_name = m._user_name;
	return (*this);
}

UserNameModule::~UserNameModule() {}

std::string		UserNameModule::getUserName() { return (_user_name); }


//display

void	UserNameModule::displayModule( Sdl & sdl ) {}

void	UserNameModule::displayModule( ) {}
