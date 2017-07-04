##
## Makefile for Makefile in /home/walter_h/PSU_2016_my_sokoban
##
## Made by Hugo WALTER
## Login   <walter_h@epitech.net>
##
## Started on  Fri Nov 25 10:55:04 2016 Hugo WALTER
## Last update Tue Dec 20 17:48:30 2016 Hugo WALTER
##

NAME    =       my_sokoban

SRC     =	sokoban.c		\
		move.c			\
		print.c			\
		fonctions.c		\
		lib/my/my_strlen.c	\
		lib/my/my_putstr.c	\
		lib/my/my_putchar.c	\
		lib/my/my_strcat.c

OBJ     =       $(SRC:.c=.o)

CC      =       gcc

CFLAGS  =       -I./include -Wall -pedantic -lncurses -g

RM      =       rm -rf

all:    $(NAME)

$(NAME):$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:     fclean all
