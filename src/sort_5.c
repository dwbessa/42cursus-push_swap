/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:54:14 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/06 11:37:01 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_low_index(t_stack *stack_a)
{
	int	min;
	int	index;
	int	i;

	min = stack_a->data[stack_a->top];
	i = stack_a->top - 1;
	index = stack_a->top;
	while (i >= 0)
	{
		if (stack_a->data[i] < min)
		{
			min = stack_a->data[i];
			index = i;
		}
		i--;
	}
	return (index);
}

int	find_lowers(t_stack *stack_a)

{
	int	min;
	int	i;

	min = stack_a->data[stack_a->top];
	i = stack_a->top - 1;
	while (i >= 0)
	{
		if (stack_a->data[i] < min)
			min = stack_a->data[i];
		i--;
	}
	return (min);
}

void	sort_5(t_stack	*stack_a, t_stack *stack_b)
{
	int	small;
	int	i;
	int	index;

	while (stack_a->top > 2)
	{
		small = find_lowers(stack_a);
		index = find_low_index(stack_a);
		i = stack_a->top;
		i--;
		if (stack_a->data[stack_a->top] != small)
		{
			while (index < stack_a->top)
			{
				if (stack_a->data[stack_a->top] == small || index >= 4)
					break ;
				if (index >= (stack_a->top - 2) && index < stack_a->top)
				{
					ra(stack_a);
					index++;
				}
				else
				{
					rra(stack_a);
					index--;
				}
				if (stack_a->data[stack_a->top] == small)
					break ;
			}
		}
		pb(stack_b, stack_a);
	}
	sort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}