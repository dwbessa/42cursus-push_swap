NAME	=	push_swap
LIBFT	=	libft/libft.a
SRCS	=	srcs/*.c

all: $(NAME) 

$(LIBFT):
	$(MAKE) -C libft/

$(NAME): $(LIBFT)
	cc -g -Wall -Wextra -Werror -I includes/ $(SRCS) $(LIBFT) -o $(NAME)

clean:
	@$(MAKE) fclean -C ./libft
	@rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re