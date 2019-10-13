/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 01:11:30 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 06:42:18 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "functions.hpp"

std::string		readInfo( FILE * f ) {
	if (f)
	{
		char buff[255];
		fgets(buff, 255, f);
		std::string name = buff;
		name.erase(remove(name.begin(), name.end(), '\n'), name.end());
		pclose(f);
		return name;
	}
	else
	{
		std::cerr << TRED << "Parse error" << COLOR_OFF << std::endl;
		return ("");
	}
	return ("");
}

void	displayString(  int & x, std::string str , int color ) {
	mvprintw(x, CENTRE_X - 16, "                           ");
	attron(COLOR_PAIR(2));
	mvprintw(x, START_X, BORDERS_1);
	mvprintw(x, LAST_X, BORDERS_1);
	attroff(COLOR_PAIR(2));
	
	attron(COLOR_PAIR(color));
	mvprintw(x++, CENTRE_X - static_cast<int>(str.length()) / 2, str.c_str());
	attroff(COLOR_PAIR(color));
}
