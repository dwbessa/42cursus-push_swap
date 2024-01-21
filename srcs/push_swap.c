/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:40:14 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/21 10:44:52 by dbessa           ###   ########.fr       */
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
	if (ac == 1 || (ac == 2 && count_args(av[1], ' ') == 1))
		return (1 - (check_args(av + 1, check, 1)));
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	else if (ac > 2)
		check = 1;
	size_list = split_len(av, ac);
	if (check_all(ac, av, check, size_list) == 1)
		return (0);
	stack_a = create_stack(av, size_list, check, 1);
	stack_b = create_stack(av, size_list, check, 0);
	use_sort(stack_a, stack_b, size_list);
	free_stack(stack_a, stack_b, av, ac);
	return (0);
}
