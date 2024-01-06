#include "../src/push_swap.h"

void	print_stack(t_stack *stack_a)
{
	int i;

	i = stack_a->top;
	ft_printf("\n----------------------\n");
	while (i >= 0)
	{
		ft_printf("%d - ", stack_a->data[i]);
		i--;
	}
	ft_printf("\n\n");
}