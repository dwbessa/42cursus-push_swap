/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:40:14 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/06 23:25:17 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		size_list;
	int		check;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac > 1)
	{
		check = 0;
		if (ac == 1 || (ac == 2 && !av[1][0]))
			return (1);
		else if (ac == 2)
			av = ft_split(av[1], ' ');
		size_list = split_len(av);
		if (ac > 2)
		{
			size_list--;
			check = 1;
		}
		stack_a = create_stack(av, size_list, check);
		stack_b = create_stack(av, 0, check);
		use_sort(stack_x, stack_y, size_list);
		free(stack_a);
		free(stack_b);
		return (0);
	}
	exit(EXIT_FAILURE);
}
