NAME = ft_shmup

SRC = main.cpp AEntity.cpp Player.cpp Bullet.cpp Asteroid.cpp Enemy.cpp ColorUtils.cpp

OBJ = $(SRC:.cpp=.o)

CPP = c++ -Wall -Wextra -Werror 

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

.PHONY: all clean fclean re play