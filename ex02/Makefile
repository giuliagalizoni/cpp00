CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
NAME = accounts

SRCS = tests.cpp \
		Account.cpp \

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
