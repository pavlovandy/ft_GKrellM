/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CatModulo.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 03:57:20 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 07:13:43 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CATMODULO_HPP
# define CATMODULO_HPP

# include "IMonitorModule.hpp"

class CatModulo : public IMonitorModule
{
	private:
		static std::string		_cat;
		SDL_Surface		*_cat_surface;

	public:
		CatModulo();
		CatModulo( SDL_Surface *cat_surface );
		CatModulo( CatModulo const & );
		CatModulo &	operator=( CatModulo const & );
		~CatModulo();
		
		void	displayModule( int & x, Sdl * sdl, TTF_Font * f );
		void	displayModule( int & x  ) ;
};





#endif
