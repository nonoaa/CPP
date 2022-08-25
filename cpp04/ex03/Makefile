NAME = amateria

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Amateria.cpp ICharacter.cpp
OBJS = $(SRCS:%.cpp=%.o)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re