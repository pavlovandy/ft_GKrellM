/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:26:29 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/12 20:30:47 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFOMODULE_HPP
# define OSINFOMODULE_HPP

# include "IMonitorModule.hpp"
# include <fstream>

class OSInfoModule : public IMonitorModule {
	private:
		std::string		_os_name;
		
	public:
		OSInfoModule();
		OSInfoModule( OSInfoModule const & );
		OSInfoModule &	operator=( OSInfoModule const & );
		~OSInfoModule();
		void	displayModule( Sdl & sdl );
		void	displayModule( ) ;
};

#endif