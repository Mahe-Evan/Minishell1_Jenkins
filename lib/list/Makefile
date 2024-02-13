##
## EPITECH PROJECT, 2024
## list
## File description:
## List Library
##

SRC	=	list_display.c	\
		list_add.c	\
		list_remove.c	\
		list_reverse.c	\
		list_size.c	\
		list_get.c	\
		list_find.c	\
		list_move.c	\
		list_include.c	\
		list_apply.c	\
		list_apply_on_matching.c	\
		list_destroy.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	liblist.a

CFLAGS += -I./ -I../my/ -Werror -Wall -Wextra -Wshadow -L./lib/my -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp list.h ../../include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
