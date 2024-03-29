/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:26:29 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 07:13:02 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFOMODULE_HPP
# define OSINFOMODULE_HPP

# include "IMonitorModule.hpp"
# include <fstream>

class OSInfoModule : public IMonitorModule {
	private:
		std::string		_os_name;
		std::string		_os_version;
		std::string		_os_build;
		
	public:
		OSInfoModule();
		OSInfoModule( OSInfoModule const & );
		OSInfoModule &	operator=( OSInfoModule const & );
		~OSInfoModule();
		void	displayModule( int & x, Sdl * sdl, TTF_Font * f );
		void	displayModule( int & x  ) ;
};

#endif