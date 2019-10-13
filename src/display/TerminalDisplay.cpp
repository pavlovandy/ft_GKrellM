/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TerminalDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:00:57 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 03:01:13 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TerminalDisplay.hpp"

TerminalDisplay::TerminalDisplay() : ADisplay("Terminal display") {
	initscr();
	keypad(stdscr, true);
	nodelay(stdscr, true);
	curs_set(false);
	clear();
	noecho();
	cbreak();
	start_color();

	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_MAGENTA, COLOR_GREEN);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
}

TerminalDisplay::~TerminalDisplay() {
	endwin();
}

//useless
TerminalDisplay::TerminalDisplay( TerminalDisplay const & ) : ADisplay("Terminal display") {}
TerminalDisplay &	TerminalDisplay::operator=( TerminalDisplay const & ) { return *this; }
//...

void	TerminalDisplay::display() {
	std::list<IMonitorModule*>::iterator it;
	int		curr_x = 0;
	

	for (it = _list.begin(); it != _list.end(); it++)
	{
		attron(COLOR_PAIR(2));
		mvprintw(curr_x++, 4, BORDERS_3);
		attroff(COLOR_PAIR(2));

		(*it)->displayModule(curr_x);
	}
	attron(COLOR_PAIR(2));
	mvprintw(curr_x++, 4, BORDERS_3);
	attroff(COLOR_PAIR(2));
}
