/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:58:13 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/12 18:42:48 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_stack(t_stack *stack_a)
{
	int	i;

	i = stack_a->top;
	while (i >= 0)
	{
		if (stack_a->data[i] > stack_a->data[i - 1])
			return (1);
		i--;
	}
	return (0);
}

int	is_sorted(char **av, int check)
{
	int	i;
	int	a;
	int	b;

	i = check;
	while (av[i + 1] != NULL)
	{
		a = ft_atoi(av[i]);
		b = ft_atoi(av[i + 1]);
		if (a > b)
			return (0);
		i++;
	}
	return (1);
}

int	check_args(char **av, int check)
{
	int	i;
	int	j;

	if (is_sorted(av, check))
		return (1);
	i = check;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != '-')
			{
				ft_printf("Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
