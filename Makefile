##
## EPITECH PROJECT, 2024
## Project
## File description:
## Makefile
##

SRC	=	main.c	\
		parsing.c	\
		debugging.c	\
		cd.c	\
		my_getenv.c	\
		setenv.c	\
		env.c	\

NAME	=	mysh

OBJ	=	$(SRC:.c=.o)

CFLAGS += -I./include/ -Werror -Wall -Wextra -Wshadow

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C commands/
	make -C lib/my/
	make -C lib/my_printf/
	make -C lib/list/
	gcc -o $(NAME) $(OBJ)	\
	-L./lib/my -lmy	\
	-L./lib/my_printf -lmy_printf	\
	-L./lib/list -llist	\

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

NAME_TEST	=	unit_tests

SRC_TESTS =	tests/test.c	\

FLAGS_TEST = -L./lib/my -lmy	\
			-L./lib/my_printf -lmy_printf	\
			-L./lib/list -llist	\
			-lcriterion --coverage

unit_tests: re
	gcc -o $(NAME_TEST) $(SRC_TESTS) $(CFLAGS) $(FLAGS_TEST)

tests_run: unit_tests
	./$(NAME_TEST)
