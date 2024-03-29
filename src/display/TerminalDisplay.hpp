/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TerminalDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:33:11 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/12 23:18:09 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINALDISPLAY_HPP
# define TERMINALDISPLAY_HPP

# include "ADisplay.hpp"
# include <ncurses.h>

class TerminalDisplay : public ADisplay {
	private:
		TerminalDisplay( TerminalDisplay const & );
		TerminalDisplay &	operator=( TerminalDisplay const & );

	public:
		TerminalDisplay();
		~TerminalDisplay();

		void	display();
};

#endif