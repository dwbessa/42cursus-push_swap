/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:03:57 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/20 09:30:14 by dbessa           ###   ########.fr       */
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

t_stack	*create_stack(char **av, int size_list, int check, int is_aux)
{
	t_stack	*stack;
	int		i;
	int		size_index;

	i = check;
	size_index = size_list - 1;
	stack = malloc(sizeof(t_stack));
	stack->top = size_index;
	stack->data = malloc(sizeof(int) * size_list);
	if (is_aux == 1)
	{
		while (size_index >= 0 && check == 1)
			stack->data[size_index--] = ft_atoi(av[i++]);
		while (size_index >= 0 && check == 0)
			stack->data[size_index--] = ft_atoi(av[i++]);
	}
	else
		stack->top = -1;
	return (stack);
}

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

void	use_sort(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size <= 5)
		sort_5(stack_a, stack_b);
	else if (size > 5)
		sort_big(stack_a, stack_b);
}

int	array_is_sign(char *string)
{
	if (ft_strncmp(string, "-", 20) == 0 || ft_strncmp(string, "+", 20) == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
