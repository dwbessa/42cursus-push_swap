/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:40:14 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/20 09:06:56 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		size_list;
	int		check;
	t_stack	*stack_a;
	t_stack	*stack_b;

	check = 0;
	if (ac == 1)
		return (0);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	else if (ac > 2)
		check = 1;
	size_list = split_len(av, ac);
	if (check_args(av, check, size_list) == 1)
		return (0);
	stack_a = create_stack(av, size_list, check, 1);
	stack_b = create_stack(av, size_list, check, 0);
	use_sort(stack_a, stack_b, size_list);
	free(stack_a->data);
	free(stack_b->data);
	free(stack_a);
	free(stack_b);
	return (0);
}
