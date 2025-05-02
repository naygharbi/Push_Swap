NAME=push_swap
CC=cc
CFLAGS=-Wall -Werror -Wextra 
RM=rm -f
LIBFT= libft/libft.a
FILES = main.c parse.c utils.c stak_init.c ft_swap.c \
		ft_reverse.c ft_rotate.c ft_issorted.c utils2.c \
		ft_execute.c ft_push.c ft_target_cost.c miscelaneous.c

OBJS=$(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) ${LIBFT} -o $(NAME)

debug:
	cc $(CFLAGS) *.c libft/libft.a -g

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make bonus -c libft

clean:
	@make clean -sC libft
	@$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 