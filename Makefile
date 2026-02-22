NAME = ft_shmup

SRC = main.cpp AEntity.cpp Player.cpp Bullet.cpp Asteroid.cpp Enemy.cpp ColorUtils.cpp

OBJ = $(SRC:.cpp=.o)

CPP = c++ -Wall -Wextra -Werror 

VAL = valgrind --leak-check=full --track-origins=yes --track-fds=yes --show-leak-kinds=all
VALSUP = valgrind --leak-check=full --track-origins=yes --track-fds=yes --show-leak-kinds=all --suppressions=ncurses.supp

all: $(NAME)

$(NAME): $(OBJ)
	@$(CPP) $(OBJ) -o $(NAME) -lncurses -g

%.o: %.cpp
	@$(CPP) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "clean done"

fclean: clean
	@rm -f $(NAME)
	@echo "fclean done"

re: fclean all

play: all clean
	@./$(NAME)

val: $(NAME)
	@$(VAL) ./$(NAME)

valsup: $(NAME)
	@$(VALSUP) ./$(NAME)

.PHONY: all clean fclean re play