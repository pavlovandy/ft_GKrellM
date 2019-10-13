/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiskModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 05:23:57 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 08:14:47 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiskModule.hpp"

bool	DiskModule::readAgain() {
	FILE* f = popen("du -sh ~/.vscode-cpptools", "r");
	_vscode_large = readInfo(f);
	_vscode_large = "Vscode's plugins: " + _vscode_large.substr(0, _vscode_large.find("\t"));
	return (true);
}

DiskModule::DiskModule() {
	readAgain();
}

DiskModule::DiskModule( DiskModule const & ) {
	
}
DiskModule &	DiskModule::operator=( DiskModule const & ) {
	return (*this);
}
DiskModule::~DiskModule() {
	
}

void	DiskModule::displayModule( int & x, Sdl * sdl, TTF_Font * f ) {
	while (!readAgain())
		SDL_Delay(1);
	SDL_Color color = {175, 120, 130, 0};
	SDL_Surface* surface1 = TTF_RenderText_Solid(f, _vscode_large.c_str(), color);
	SDL_Rect re = {0, x, 100, 40};
	SDL_BlitSurface(surface1, nullptr, sdl->win_surr, &re);
	x += 30;
	SDL_FreeSurface(surface1);
}
void	DiskModule::displayModule( int & x  ) {
	while (!readAgain())
		SDL_Delay(1);
	displayString( x, _vscode_large, 5 );
}