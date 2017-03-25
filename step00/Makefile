CXX = clang++

NAME = test.out

SRC =   test_staticpow.cpp

OBJ = $(SRC:.cpp=.o)

CXXFLAGS = -Wall -Wextra -std=c++14
LDFLAGS = 

all : $(NAME)


$(NAME) : $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
