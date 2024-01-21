NAME	=	push_swap
LIBFT	=	libft/libft.a
SRCS	=	srcs/*.c

all: $(NAME) 

$(LIBFT):
	@$(MAKE) -s -C libft/ > /dev/null

$(NAME): $(LIBFT)
	@cc -Wall -Wextra -Werror -I includes/ $(SRCS) $(LIBFT) -o $(NAME)

clean:
	@$(MAKE) fclean -C ./libft > /dev/null
	@rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re