/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:58:13 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/09 17:52:12 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_stack(t_stack *stack_a)
{
	while (stack_a->top >= 0)
	{
		if (stack_a->data[stack_a->top] > stack_a->data[stack_a->top - 1])
			return (1);
		stack_a->top--;
	}
	return (0);
}

static int	is_sorted(char **av, int check)
{
	int	i;

	i = check;
	while (av[i] != NULL)
	{
		if (av[i] > av[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	check_args(char **av, int check)
{
	int	i;
	int	j;

	i = check;
	if (is_sorted(av, check))
		exit(EXIT_FAILURE);
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				ft_printf("Error\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (0);
}
