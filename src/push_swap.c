/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:40:14 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/05 16:46:42 by dbessa           ###   ########.fr       */
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
		stack_a = create_stack(av, size_list);
		stack_b = create_stack(av, 0);
		i = stack_a->top;
		ft_printf("Before sorting\n");
		while (i >= 0)
		{
			ft_printf("%d - ", stack_a->data[i]);
			i--;
		}
		ft_printf("\n\n");
		use_sort(stack_a, stack_b, size_list);
		i = stack_a->top;
		while (i >= 0)
		{
			ft_printf("%d - ", stack_a->data[i]);
			i--;
		}
		free(stack_a);
		free(stack_b);
	}
	else
		exit(EXIT_FAILURE);
	return (0);
}