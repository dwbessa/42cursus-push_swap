/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:54:14 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/15 17:36:36 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_low_index(t_stack *stack_a)
{
	int	index;
	int	min;
	int	i;

	min = stack_a->data[stack_a->top];
	i = stack_a->top - 1;
	index = stack_a->top;
	while (i >= 0)
	{
		if (stack_a->data[i] < min)
			index = i;
		i--;
	}
	return (index);
}

static int	find_lowers(t_stack *stack_a)

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

static void	check_and_sort(t_stack *stack_a, int small, int index)
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
			check_and_sort(stack_a, small, index);
		pb(stack_b, stack_a);
	}
	sort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_3(t_stack *stack_a)
{
	if (stack_a->data[2] > stack_a->data[1] && stack_a->data[1] > \
	stack_a->data[0] && stack_a->data[2] > stack_a->data[0])
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (stack_a->data[2] > stack_a->data[1] && stack_a->data[1] < \
	stack_a->data[0] && stack_a->data[2] < stack_a->data[0])
		sa(stack_a);
	else if (stack_a->data[2] < stack_a->data[1] && stack_a->data[1] > \
	stack_a->data[0] && stack_a->data[2] < stack_a->data[0])
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (stack_a->data[2] > stack_a->data[1] && stack_a->data[1] < \
	stack_a->data[0] && stack_a->data[2] > stack_a->data[0])
		ra(stack_a);
	else if (stack_a->data[2] < stack_a-> data[1] && stack_a->data[1] > \
	stack_a->data[0] && stack_a->data[2] > stack_a-> data[0])
		rra(stack_a);
}