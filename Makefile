##
## Makefile for  in /Users/Rouis/Desktop/ftl
## 
## Made by EL GOHARY Rouis
## Login   <elgoha_r@etna-alternance.net>
## 
## Started on  Thu Nov 10 13:32:21 2016 EL GOHARY Rouis
## Last update Sat Nov 12 18:13:11 2016 EL GOHARY Rouis
##
CC		=		gcc
NAME	=		my_ftl
SRC		=		air_shed.c		\
				container.c		\
				enemy.c			\
				freight.c		\
				menu.c			\
				my_string.c		\
				readline.c		\
				ship_command.c	\
				system_control.c\
				system_repair.c	\
				tools.c			\
				zone.c			\
				main.c
OBJ		=		$(SRC:%.c=%.o)
RM		=		rm -f
CFLAGS	+=		-W -Werror -Wall -Wextra
CFLAGS	+=		-ansi -pedantic

$(NAME):		$(OBJ)
				$(CC) $(OBJ) -o $(NAME)

all:			$(NAME)

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
