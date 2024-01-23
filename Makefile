NAME	=	push_swap
LIBFT	=	libft/libft.a
SRCS	=	$(wildcard srcs/*.c)
OBJS	=	$(patsubst srcs/%.c, objs/%.o, $(SRCS))

all: $(NAME) 

$(LIBFT):
	@$(MAKE) -s -C libft/ > /dev/null

objs:
	@mkdir -p objs

$(OBJS): objs/%.o: srcs/%.c | objs
	@cc -Wall -Wextra -Werror -I includes/ -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@cc -Wall -Wextra -Werror -I includes/ $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@$(MAKE) clean -C ./libft > /dev/null
	@rm -f $(OBJS)
	@rm -rf objs

fclean: clean
	@$(MAKE) fclean -C ./libft > /dev/null
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
