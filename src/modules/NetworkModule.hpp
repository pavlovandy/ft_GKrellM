/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 02:27:51 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 07:13:08 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKMODULE_HPP
# define NETWORKMODULE_HPP

# include "IMonitorModule.hpp"
# include <fstream>

class NetworkModule : public IMonitorModule
{
private:
	std::string		_in;
	std::string		_out;
	
public:
	NetworkModule();
	NetworkModule( NetworkModule const & );
	NetworkModule &	operator=( NetworkModule const & );
	~NetworkModule();

	void	displayModule( int & x, Sdl * sdl, TTF_Font * f );
	void	displayModule( int & x  ) ;
	bool	readAgain();
};

#endif