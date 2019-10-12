# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 13:27:10 by apavlov           #+#    #+#              #
#    Updated: 2019/10/12 13:50:43 by apavlov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++

FLAGS =  -Wall -Wextra -Werror -Wconversion

NAME = ft_gkrellm

SRC = main.cpp

SRC_DIR = ./src/

OBJ_DIR = ./obj/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

UNAME_S := $(shell uname -s)
LINKS := 
ifeq ($(UNAME_S),Linux)
	LINKS += -lSDL2 -lSDL2_ttf
endif

SDL_PATH = ./framework

INCLUDES :=

ifeq ($(UNAME_S),Darwin)
INCLUDES += -I./frameworks/SDL2.framework/Headers \
			-I./frameworks/SDL2_ttf.framework/Headers \
			-F./frameworks 
endif

FRAMEWORKS :=
ifeq ($(UNAME_S),Darwin)
FRAMEWORKS += 	-F./frameworks \
				-rpath ./frameworks \
				-framework AppKit -framework OpenGL \
				-framework SDL2 -framework SDL2_image
endif

all: obj_dir $(NAME)
	echo "Compilated"

obj_dir:
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(FRAMEWORKS) $(OBJ) -o $(NAME) $(LINKS)

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all