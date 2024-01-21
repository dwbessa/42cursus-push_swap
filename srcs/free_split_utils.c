/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:22:05 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/21 10:45:37 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack_a, t_stack *stack_b, char **av, int ac)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[i] != NULL)
			free(av[i++]);
		free(av);
	}
	free(stack_a->data);
	free(stack_b->data);
	free(stack_a);
	free(stack_b);
}

void	free_split(char **av)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
		free(av[i++]);
	free(av);
}

int	check_all(int ac, char **av, int check, int size_list)
{
	if (ac == 2 && check_args(av, check, size_list) == 1)
	{
		free_split(av);
		return (1);
	}
	else if (check_args(av, check, size_list) == 1)
		return (1);
	return (0);
}

int	count_args(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}
