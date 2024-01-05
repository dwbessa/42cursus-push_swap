NAME	=	push_swap
LIBFT	=	libft/libft.a
SRCS	=	src/create_stack.c src/push_swap.c src/use_sort.c src/sort_3.c src/sort_5.c \
				src/operations_a.c src/operations_b.c src/operations_multi.c

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