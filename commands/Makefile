##
## EPITECH PROJECT, 2024
## Project
## File description:
## Makefile
##

SRC1	=	help.c
SRC2	=	setenv.c
SRC3	=	unsetenv.c
SRC4	=	env.c

NAME1	=	help
NAME2	=	setenv
NAME3	=	unsetenv
NAME4	=	env

OBJ1	=	$(SRC1:.c=.o)
OBJ2	=	$(SRC2:.c=.o)
OBJ3	=	$(SRC3:.c=.o)
OBJ4	=	$(SRC4:.c=.o)

CFLAGS += -I../include/ -Werror -Wall -Wextra -Wshadow

# all:	$(NAME1) $(NAME2) $(NAME3) $(NAME4)
all:	$(NAME2) $(NAME3) $(NAME4)

$(NAME1):	$(OBJ1)
	make -C ../lib/my/
	make -C ../lib/my_printf/
	make -C ../lib/list/
	gcc -o $(NAME1) $(OBJ1)	\
	-L../lib/my -lmy	\
	-L../lib/my_printf -lmy_printf	\
	-L../lib/list -llist	\

$(NAME2):	$(OBJ2)
	make -C ../lib/my/
	make -C ../lib/my_printf/
	make -C ../lib/list/
	gcc -o $(NAME2) $(OBJ2)	\
	-L../lib/my -lmy	\
	-L../lib/my_printf -lmy_printf	\
	-L../lib/list -llist	\

$(NAME3):	$(OBJ3)
	make -C ../lib/my/
	make -C ../lib/my_printf/
	make -C ../lib/list/
	gcc -o $(NAME3) $(OBJ3)	\
	-L../lib/my -lmy	\
	-L../lib/my_printf -lmy_printf	\
	-L../lib/list -llist	\

$(NAME4):	$(OBJ4)
	make -C ../lib/my/
	make -C ../lib/my_printf/
	make -C ../lib/list/
	gcc -o $(NAME4) $(OBJ4)	\
	-L../lib/my -lmy	\
	-L../lib/my_printf -lmy_printf	\
	-L../lib/list -llist	\

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
