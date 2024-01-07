NAME	=	push_swap
LIBFT	=	libft/libft.a
SRCS	=	src/create_stack.c src/push_swap.c src/use_sort.c src/sort_3.c src/sort_5.c \
				src/operations_a.c src/operations_b.c src/operations_multi.c \
				.ignore/excluir_print_stack.c src/push_swap_utils.c

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

run:
	ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG