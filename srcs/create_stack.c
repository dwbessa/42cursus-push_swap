/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:03:57 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/07 11:09:43 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_len(char **av, int ac)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
		i++;
	if (ac > 2)
		i--;
	return (i);
}

t_stack	*create_stack(char **av, int size, int check)
{
	t_stack	*stack;
	int		i;
	int		size_list;

	i = check;
	size_list = size - 1;
	stack = malloc(sizeof(t_stack));
	stack->top = size - 1;
	stack->data = malloc(sizeof(int) * size);
	if (size > 0)
	{
		while (i <= size && check == 1)
		{
			stack->data[size_list] = ft_atoi(av[i]);
			i++;
			size_list--;
		}
		while (i < size && check == 0)
		{
			stack->data[size_list] = ft_atoi(av[i]);
			i++;
			size_list--;
		}
	}
	return (stack);
}
