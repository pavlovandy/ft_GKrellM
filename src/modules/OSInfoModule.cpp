/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:11:59 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/12 20:30:54 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "OSInfoModule.hpp"

OSInfoModule::OSInfoModule() {
	system("sw_vers > sw_vers");
	std::ifstream	osvers("sw_vers");
	if (osvers)
	{
		std::string name;
		std::getline(osvers, name);
		name = name.substr(12);
		name.erase(remove(name.begin(), name.end(), '\t'), name.end()); 
		_os_name = name;
	}
	else
		std::cerr << TRED << "Coudnt get os name" << COLOR_OFF << std::endl;
	system("rm -f sw_vers");
}

OSInfoModule::OSInfoModule( OSInfoModule const & m ) {
	_os_name = m._os_name;
}

OSInfoModule &	OSInfoModule::operator=( OSInfoModule const & m ) {
	_os_name = m._os_name;
	return (*this);
}

OSInfoModule::~OSInfoModule() { _os_name.clear(); }

//displays

void	OSInfoModule::displayModule( Sdl & sdl ){
	
}

void	OSInfoModule::displayModule( ) {
	
}
