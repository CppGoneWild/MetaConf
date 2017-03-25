CXX = clang++

NAME = test.out

SRC =   test_02-01.cpp

OBJ = $(SRC:.cpp=.o)

CXXFLAGS = -Wall -Wextra -std=c++1z
LDFLAGS = 

all : $(NAME)


$(NAME) : $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
