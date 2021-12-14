FILES = main.cpp	\
		conway.cpp

INC = -I inc/

NAME = conway

CC = g++

FLAGS = -std=c++17 -g3 -fsanitize=address -ggdb

RM = rm -rf

SRC = $(addprefix srcs/, $(FILES))

all: $(NAME)

$(NAME):
			$(CC) $(FLAGS) $(INC) -o $(NAME) $(SRC)

clean:
			@$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re