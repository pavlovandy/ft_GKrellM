/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:58:21 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/12 20:30:37 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include "../other/Sdl.hpp"
# include <algorithm>

class IMonitorModule {
	public:
		virtual 		~IMonitorModule() {}
		virtual void	displayModule( Sdl & sdl ) = 0;
		virtual void	displayModule( ) = 0;
};

#endif