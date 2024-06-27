CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRC = philosofers.c  ft_atoi.c ft_usleep.c add_philosofers.c routine_utils.c
OSRC = $(SRC:.c=.o)
NAME = philo
FSANITIZE = -fsanitize=thread

all: $(NAME)

$(NAME) : $(OSRC) $(libft) philosofers.h
	$(CC) $(CFLAGS) $(libft) $(OSRC) -o $(NAME)

%.o :%c philosofers.h
	$(CC) -c $(CFLAGS) $< -o $@
	
clean:
	$(RM) $(OSRC)
fclean:clean
	$(RM) $(NAME)
re: fclean all
	