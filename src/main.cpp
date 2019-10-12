/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:40:54 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/12 20:35:23 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./other/Sdl.hpp"
#include <ctime>
#include <iostream>
#include "./modules/OSInfoModule.hpp"
#include "./modules/TimeModule.hpp"
#include "./modules/UserNameModule.hpp"

int		main( int argc, char ** argv ) {
	Sdl	sdl;
	SDL_UpdateWindowSurface(sdl.win);

	UserNameModule	osmodule;
	return (0);
}