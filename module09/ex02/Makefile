NAME = PmergeMe
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -MMD
SRC = main.cpp PmergeMe.cpp
OBJ = $(SRC:.cpp=.o)
DEP = $(OBJ:.o=.d)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp Makefile
	$(CC) $(FLAGS) -c $< -o $@

%.s: %.cpp Makefile
	$(CC) < -o $@

clean:
	rm -f $(OBJ) $(DEP) *.s

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
