/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicDisplay.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:34:08 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/12 19:05:28 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICDISPLAY_HPP
# define GRAPHICDISPLAY_HPP

# include "ADisplay.hpp"
# include "../other/Sdl.hpp"

class GraphicDisplay : public ADisplay {
	private:
		Sdl *	_sdl;
		unsigned	_w;
		unsigned	_h;
		SDL_Surface*	_skin;
		TTF_Font*		_font;

		GraphicDisplay();
		GraphicDisplay( GraphicDisplay const & );
		GraphicDisplay &	operator=( GraphicDisplay const &);

	public:
		GraphicDisplay( unsigned w, unsigned h, unsigned x, unsigned y );	
		~GraphicDisplay();
		void	changeSkin( SDL_Surface* skin );
		void	setFont( TTF_Font* font );
		void	display( );
};

#endif