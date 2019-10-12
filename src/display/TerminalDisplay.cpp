/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TerminalDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:00:57 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/12 20:36:04 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TerminalDisplay.hpp"

TerminalDisplay::TerminalDisplay() : ADisplay("Terminal display") {}

TerminalDisplay::~TerminalDisplay() {}



//useless
TerminalDisplay::TerminalDisplay( TerminalDisplay const & ) : ADisplay("Terminal display") {}
TerminalDisplay &	TerminalDisplay::operator=( TerminalDisplay const & ) { return *this; }
//...

void	TerminalDisplay::display() {} //this should display in terminal