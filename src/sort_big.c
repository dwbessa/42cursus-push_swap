/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:41:42 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/12 19:22:30 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*bubble_sort(t_stack *stack)
{
	int	i;
	int	j;
	int	swap;

	i = stack->top;
	while (i > 0)
	{
		j = stack->top;
		while (j > 0)
		{
			if (stack->data[j] > stack->data[j - 1])
			{
				swap = stack->data[j];
				stack->data[j] = stack->data[j - 1];
				stack->data[j - 1] = swap;
			}
			j--;
		}
		i--;
	}
	return (stack);
}

void	insert_index(t_stack *stack_a)
{
	t_stack	*stack_c;
	int		i;
	int		j;

	stack_c = malloc(sizeof(t_stack));
	stack_c->data = malloc(sizeof(int) * stack_a->top);
	ft_memcpy(stack_c->data, stack_a->data, (sizeof(int) * (stack_a->top + 1)));
	stack_c->top = stack_a->top;
	bubble_sort(stack_c);
	i = stack_a->top;
	while (i > -1)
	{
		j = stack_a->top;
		while (j > -1)
		{
			if (stack_a->data[i] == stack_c->data[j])
			{
				stack_a->data[i] = j;
				j--;
				break ;
			}
			j--;
		}
		i--;
	}
}

int	calculate_num_bits(int num)
{
	int	num_bits;

	num_bits = 0;
	while (num > 0)
	{
		num >>= 1;
		num_bits++;
	}
	return (num_bits);
}

int	find_max(t_stack *stack)
{
	int	max_num;
	int	i;

	max_num = stack->data[0];
	i = 1;
	while (i <= stack->top)
	{
		if (stack->data[i] > max_num)
			max_num = stack->data[i];
		i++;
	}
	return (max_num);
}

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	int	max_num;
	int	num_bits;
	int	bit_position;
	int	i;

	insert_index(stack_a);
	max_num = find_max(stack_a);
	num_bits = calculate_num_bits(max_num);
	bit_position = 0;
	while (bit_position <= num_bits)
	{
		i = stack_a->top;
		while (i >= 0)
		{
			if ((stack_a->data[stack_a->top] & (1 << bit_position)))
				pb(stack_b, stack_a);
			else
				ra(stack_a);
			i--;
		}
		while (stack_b->top >= 0)
			pa(stack_a, stack_b);
		if (is_sorted_stack(stack_a) == 0)
			return ;
		bit_position++;
	}
}
