/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:40:14 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/03 17:55:49 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac > 2)
	{
		t_stack	*stack_a;
		t_stack	*stack_b;
		int		size_list;
		int		i;

		i = 0;
		size_list = ac - 1;
		stack_a = malloc(sizeof(t_stack) * 1);
		stack_b = malloc(sizeof(t_stack) * 1);
		stack_a->data = malloc(sizeof(int) * size_list);
		stack_a->top = size_list - 1;
		stack_b->data = malloc(sizeof(int) * size_list);
		while(i < size_list)
		{
			stack_a->data[size_list] = ft_atoi(av[1]);
			size_list--;
		}
		sort_stack(stack_a, stack_b);
		i = 0;
		while (i < stack_a->top)
		{
			ft_printf("%d\n", stack_a->data[stack_a->top]);
			stack_a->top--;
		}
		free(stack_a);
		free(stack_b);
	}
	else
		exit(EXIT_FAILURE);
	return (0);
}