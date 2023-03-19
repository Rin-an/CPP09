NAME = RPN
HEADERS = RPN.hpp
SRCS = RPN.cpp main.cpp
OBJS := $(SRCS:.cpp=.o)

RM = rm -rf
CC = c++ -Wall -Werror -Wextra -std=c++98

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o : %.cpp $(HEADERS)
	$(CC) -c $< -o $@

all : $(NAME)

clean :
	$(RM) $(OBJS)
fclean : clean
	$(RM) $(NAME)

re : fclean all
.PHONY: all clean fclean re
