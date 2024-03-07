##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## it's a Makefile
##

SRC =	main.c\
		play_game.c\
		rectangle.c\
		create.c\
		create_1.c\
		create_2.c\
		draw_window.c\
		cursor.c\
		mob.c\
		mage.c

OBJTEST =	$(SRCTEST:.c=.o)

OBJ = $(SRC:.c=.o)

NAME =	my_hunter

CFLAGS	=	-Wall\
					-Wextra\
					-I include/\
					-lcsfml-graphics\
					-lcsfml-system\
					-lcsfml-window\
					-lcsfml-audio\

all:	$(NAME)

make_lib:
	make -C ../lib/my

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ) $(OBJTEST)

fclean:	clean
	rm -f $(NAME) $(NAMETEST)

re:	fclean
	make all
