/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ADisplay.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:37:08 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 07:08:02 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADISPLAY_HPP
# define ADISPLAY_HPP

# include "IMonitorDisplay.hpp"
# include <list>
# include "../modules/IMonitorModule.hpp"

class IMonitorModule;

class ADisplay : public IMonitorDisplay
{
	private:
		ADisplay( );
		ADisplay &	operator=( ADisplay const & );
		ADisplay( ADisplay const & );

	protected:
		std::string		_displayType;
		unsigned int	_list_size;
		std::list<IMonitorModule*>	_list;

	public:
		ADisplay( std::string type );
		virtual ~ADisplay();
		void	addNewModule( IMonitorModule* m );
		unsigned	getModuleCount();
		std::string	getDispayType();
		virtual void	display() = 0;
};

#endif