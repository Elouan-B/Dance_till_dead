##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## build a lib
##

SRC	=	running.c\
		main.c\
		draw_grid.c\

OBJ	=	$(SRC:.c)

NAME	=	Dance_till_dead

all:
	gcc -o $(NAME) $(SRC) -g -lcsfml-window -lcsfml-graphics \
	-lcsfml-audio -lcsfml-system


clean:
	rm .gitignore

fclean: clean

re: fclean all

auteur:
	echo $(USER) > auteur
