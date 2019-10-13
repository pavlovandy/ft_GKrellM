/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:40:54 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/13 08:31:50 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./other/Sdl.hpp"
#include <ctime>
#include <iostream>
# include <sys/time.h>
#include "./modules/OSInfoModule.hpp"
#include "./modules/TimeModule.hpp"
#include "./modules/UserNameModule.hpp"
#include "./display/GraphicDisplay.hpp"
#include "./display/TerminalDisplay.hpp"
#include "./modules/CPUInfoModule.hpp"
#include "./modules/RAMModule.hpp"
#include "./modules/NetworkModule.hpp"
#include "./modules/CatModulo.hpp"
#include "./modules/DiskModule.hpp"
#include <ncurses.h>

int		main( int argc, char ** argv ) {
	int		_input;
	bool	_quit = true;

	if (argc != 2)
		std::cout << TGRE << "Usage: ./ft_gkrellm -[f|t]"  << COLOR_OFF << std::endl;
	else if (argc == 2)
	{
		std::string flag = argv[1];
		if (flag == "-g")
		{
			GraphicDisplay gd(200, 800, 1000, 200);

			gd.addNewModule( new UserNameModule() );
			gd.addNewModule( new TimeModule() );
			gd.addNewModule( new RAMModule() );
			gd.addNewModule( new OSInfoModule() );
			gd.addNewModule( new NetworkModule() );
			gd.addNewModule( new DiskModule() );
			gd.addNewModule( new CPUInfoModule() );

			SDL_Surface* loadedCat = IMG_Load("resources/skins/cat.jpeg");
			if (!loadedCat)
			{
				std::cout << TBLU << "There is no cat... <tear drops>" << COLOR_OFF << std::endl;
			}
			else
				gd.addNewModule( new CatModulo(loadedCat) );

			gd.Sdl_loop();
		}
		else if (flag == "-t")
		{
			TerminalDisplay	td;

			td.addNewModule( new UserNameModule() );
			td.addNewModule( new TimeModule() );
			td.addNewModule( new OSInfoModule() );
			td.addNewModule( new RAMModule() );
			td.addNewModule( new OSInfoModule() );
			td.addNewModule( new CPUInfoModule() );
			td.addNewModule( new DiskModule() );
			td.addNewModule( new CatModulo() );

			while (_quit){
				_input = getch();
				if (_input == 'q' || _input == 'Q')
					_quit = false;
				td.display();
				refresh();
				SDL_Delay(100);
				
			}
		}
		else 
			std::cout << TGRE << "Usage: ./ft_gkrellm -[g|t]" << COLOR_OFF << std::endl;
	}
	return (0);
}
