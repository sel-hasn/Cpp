NAME = Brain

FLAGS = -Wall -Wextra -Werror -std=c++98

CPP = c++

SRC = Animal.cpp Cat.cpp Dog.cpp main.cpp Brain.cpp

OBJ = $(SRC:.cpp=.o)

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp Animal.hpp Cat.hpp Dog.hpp Brain.hpp
	$(CPP) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all