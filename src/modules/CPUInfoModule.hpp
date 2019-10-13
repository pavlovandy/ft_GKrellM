/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUInfoModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 01:04:11 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 07:13:24 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUINFOMODULE_HPP
# define CPUINFOMODULE_HPP

# include "IMonitorModule.hpp"
# include <fstream>

class CPUInfoModule : public IMonitorModule
{
private:
	std::string		_core_count;
	std::string		_user;
	std::string		_system;
	std::string		_idle;
	std::string		_system_info;
	
public:
	CPUInfoModule();
	CPUInfoModule( CPUInfoModule const & );
	CPUInfoModule &	operator=( CPUInfoModule const & );
	~CPUInfoModule();

	void	displayModule( int & x, Sdl * sdl, TTF_Font * f );
	void	displayModule( int & x  ) ;
	bool	readAgain();
};

#endif