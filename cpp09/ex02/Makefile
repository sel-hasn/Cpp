NAME = PmergeMe

FLAGS = -Wall -Wextra -Werror -std=c++98

CPP = c++

SRC = main.cpp PmergeMe.cpp

OBJ = $(SRC:.cpp=.o)

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ)
		$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp PmergeMe.hpp
		$(CPP) $(FLAGS) -c $< -o $@

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all