/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:29:04 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 07:12:49 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMEMODULE_HPP
# define TIMEMODULE_HPP

# include "IMonitorModule.hpp"
# include <ctime>

class TimeModule : public IMonitorModule {
	private:
		std::tm* _now;
		void	upToDate();

	public:
		TimeModule();
		~TimeModule();
		TimeModule( TimeModule const & );
		TimeModule &	operator=( TimeModule const & );
		std::string	getData();
		std::string	getTime();
		std::string	getDayOfWeek();
		void	displayModule( int & x, Sdl * sdl, TTF_Font * f );
		void	displayModule( int & x  );
};

#endif