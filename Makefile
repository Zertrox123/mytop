##
## EPITECH PROJECT, 2024
## delivery
## File description:
## Makefile
##

SRC	=	main.c	\
		src/display_first_line.c	\

CFLAGS = -g3

OBJ	=	$(SRC:.c=.o)

NAME	=	my_top

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) -lncurses

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
