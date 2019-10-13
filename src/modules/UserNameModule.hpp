/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserNameModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:26:29 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 07:12:25 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERNAMEMODULE_HPP
# define USERNAMEMODULE_HPP

# include "IMonitorModule.hpp"
# include <cstdlib>

class UserNameModule : public IMonitorModule {
	private:
		std::string		_user_name;
		SDL_Surface*	_name_surr;
	
	public:
		UserNameModule();
		UserNameModule( UserNameModule const & );
		UserNameModule &	operator=( UserNameModule const & );
		~UserNameModule();
		std::string		getUserName();
		void	displayModule( int & x, Sdl * sdl, TTF_Font * f );
		void	displayModule( int & x  );
};

#endif