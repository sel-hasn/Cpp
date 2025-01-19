NAME = Zombie

FLAGS = -Wall -Wextra -Werror -std=c++98

CPP = c++

SRC = Zombie.cpp newZombie.cpp  randomChump.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp Zombie.hpp
	$(CPP) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all