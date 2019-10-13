# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 13:27:10 by apavlov           #+#    #+#              #
#    Updated: 2019/10/13 08:37:06 by apavlov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++

FLAGS =  -Wall -Wextra -Wconversion -std=c++98 -Werror 

NAME = ft_gkrellm

SRC =	main.cpp \
		other/Sdl.cpp other/functions.cpp \
		modules/OSInfoModule.cpp modules/TimeModule.cpp modules/UserNameModule.cpp \
		modules/CPUInfoModule.cpp modules/RAMModule.cpp modules/NetworkModule.cpp \
		modules/CatModulo.cpp modules/DiskModule.cpp \
		display/ADisplay.cpp display/GraphicDisplay.cpp display/TerminalDisplay.cpp

HEAD =	other/Sdl.hpp other/terminal_colors.hpp other/functions.hpp \
		modules/OSInfoModule.hpp modules/TimeModule.hpp modules/UserNameModule.hpp \
		modules/IMonitorModule.hpp modules/CPUInfoModule.hpp modules/RAMModule.hpp \
		modules/NetworkModule.hpp modules/CatModulo.hpp modules/DiskModule.hpp\
		display/ADisplay.hpp display/GraphicDisplay.hpp display/TerminalDisplay.hpp display/IMonitorDisplay.hpp

HEADERS = $(addprefix $(SRC_DIR), $(HEAD))

SRC_DIR = ./src/

OBJ_DIR = ./obj/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

UNAME_S := $(shell uname -s)
LINKS := -lncurses
ifeq ($(UNAME_S),Linux)
	LINKS += -lSDL2 -lSDL2_ttf -lSDL2_image
endif

SDL_PATH = ./framework

INCLUDES :=

ifeq ($(UNAME_S),Darwin)
INCLUDES += -I./frameworks/SDL2.framework/Headers \
			-I./frameworks/SDL2_ttf.framework/Headers \
			-I./frameworks/SDL2_image.framework/Headers \
			-F./frameworks 
endif

FRAMEWORKS :=
ifeq ($(UNAME_S),Darwin)
FRAMEWORKS += 	-F./frameworks \
				-rpath ./frameworks \
				-framework AppKit -framework OpenGL \
				-framework SDL2 -framework SDL2_image -framework SDL2_ttf
endif

all: obj_dir $(NAME)
	echo "Compilated"

obj_dir:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/other
	mkdir -p $(OBJ_DIR)/modules
	mkdir -p $(OBJ_DIR)/display

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(FRAMEWORKS) $(OBJ) -o $(NAME) $(LINKS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HEADERS)
	$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all