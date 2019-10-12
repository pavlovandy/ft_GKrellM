/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ADisplay.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:50:49 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/12 18:25:54 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ADisplay.hpp"

ADisplay::ADisplay( std::string type ) : _displayType(type) {
	_list.clear();
	_list_size = 0;
}

ADisplay::~ADisplay() { _list.clear(); }

void	ADisplay::addNewModule( IMonitorModule* m ) {
	_list.push_back(m);
	_list_size++;
}

unsigned	ADisplay::getModuleCount() { return _list_size; }

std::string	ADisplay::getDispayType() { return _displayType; }

void	ADisplay::display( ) {} //must display in window




//useless
ADisplay::ADisplay( ADisplay const & ) {}

ADisplay &	ADisplay::operator=( ADisplay const & ) { return *this; }

ADisplay::ADisplay() {}
//...