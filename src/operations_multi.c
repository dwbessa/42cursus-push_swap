/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_multi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:34:13 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/07 10:28:36 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	temp_a;
	int	temp_b;

	temp_a = stack_a->data[stack_a->top];
	stack_a->data[stack_a->top] = stack_a->data[stack_a->top - 1];
	stack_a->data[stack_a->top - 1] = temp_a;
	temp_b = stack_b->data[stack_b->top];
	stack_b->data[stack_b->top] = stack_b->data[stack_b->top - 1];
	stack_b->data[stack_b->top - 1] = temp_b;
	ft_printf("ss\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	int	temp_a;
	int	temp_b;
	int	i;
	int	k;

	i = stack_a->top;
	temp_a = stack_a->data[stack_a->top];
	while (i > 0)
	{
		stack_a->data[i] = stack_a->data[i - 1];
		i--;
	}
	stack_a->data[0] = temp_a;
	k = stack_b->top;
	temp_b = stack_b->data[stack_b->top];
	while (k > 0)
	{
		stack_b->data[k] = stack_b->data[k - 1];
		k--;
	}
	stack_b->data[0] = temp_b;
	ft_printf("rr\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	int	temp_a;
	int	temp_b;
	int	i;
	int	k;

	i = 0;
	temp_a = stack_a->data[0];
	while (i < stack_a->top)
	{
		stack_a->data[i] = stack_a->data[i + 1];
		i++;
	}
	stack_a->data[stack_a->top] = temp_a;
	k = 0;
	temp_b = stack_b->data[0];
	while (k < stack_b->top)
	{
		stack_b->data[k] = stack_b->data[k + 1];
		k++;
	}
	stack_b->data[stack_b->top] = temp_b;
	ft_printf("rrr\n");
}
