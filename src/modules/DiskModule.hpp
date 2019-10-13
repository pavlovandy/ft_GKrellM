/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiskModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 05:21:04 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 08:13:24 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISKMODULE_HPP
# define DISKMODULE_HPP

# include "IMonitorModule.hpp"

class DiskModule : public IMonitorModule
{
	private:
		std::string		_vscode_large;

	public:
		DiskModule();
		DiskModule( DiskModule const & );
		DiskModule &	operator=( DiskModule const & );
		~DiskModule();
		
		void	displayModule( int & x, Sdl * sdl, TTF_Font * f );
		void	displayModule( int & x  ) ;
		bool	readAgain();
};

#endif