NAME	=	push_swap
LIBFT	=	libft/libft.a
SRCS	=	src/*.c

all: $(NAME) 

$(LIBFT):
	$(MAKE) -C libft/

$(NAME): $(LIBFT)
	cc -Wall -Wextra -Werror $(SRCS) $(LIBFT) -o $(NAME)

clean:
	@$(MAKE) fclean -C ./libft
	@rm -rf $(NAME)

fclean: clean

re: fclean all