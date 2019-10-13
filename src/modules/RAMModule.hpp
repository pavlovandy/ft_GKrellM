/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 01:39:20 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 07:12:56 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

# include "IMonitorModule.hpp"


class RAMModule : public IMonitorModule
{
private:
	std::string		_used;
	std::string		_unused;
	std::string		_reserved;
	
public:
	RAMModule();
	RAMModule( RAMModule const & );
	RAMModule &	operator=( RAMModule const & );
	~RAMModule();

	void	displayModule( int & x, Sdl * sdl, TTF_Font * f );
	void	displayModule( int & x  );
	bool	readAgain();
};

#endif
