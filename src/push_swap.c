/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:40:14 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/06 18:00:28 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		t_stack	*stack_a;
		t_stack	*stack_b;
		int		size_list;
		int		check;

		check = 0;
		if (ac == 1 || (ac == 2 && !av[1][0]))
			return (1);
		else if (ac == 2)
			av = ft_split(av[1], ' ');
		size_list = split_len(av);
		// ft_printf("%d %d\n", size_list, check);
		if (ac > 2)
		{
			size_list--;
			check = 1;
		}
		// ft_printf("%d %d\n", size_list, check);
		stack_a = create_stack(av, size_list, check);
		stack_b = create_stack(av, 0, check);
		// print_stack(stack_a);
		use_sort(stack_a, stack_b, size_list);
		// print_stack(stack_a);
		free(stack_a);
		free(stack_b);
	}
	else
		exit(EXIT_FAILURE);
	return (0);
}