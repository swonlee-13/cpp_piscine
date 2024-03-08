CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = brain

SRCS = main.cpp


OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

.cpp.o : 
	${CC} $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:	
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all bonus clean fclean re
