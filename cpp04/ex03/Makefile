NAME = AMateria

FLAGS = -Wall -Wextra -Werror -std=c++98

CPP = c++

SRC = AMateria.cpp Character.cpp Cure.cpp Ice.cpp main.cpp MateriaSource.cpp

OBJ = $(SRC:.cpp=.o)

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp AMateria.hpp Character.hpp Cure.hpp Ice.hpp IMateriaSource.hpp MateriaSource.hpp ICharacter.hpp
	$(CPP) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all