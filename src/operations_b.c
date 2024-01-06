/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:01:22 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/06 18:16:06 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *stack_b)
{
	int	temp;

	temp = stack_b->data[stack_b->top];
	stack_b->data[stack_b->top] = stack_b->data[stack_b->top - 1];
	stack_b->data[stack_b->top - 1] = temp;
	ft_printf("sb\n");
}

void	pb(t_stack *stack_b, t_stack *stack_a)
{
	if (stack_a->top >= 0)
	{
		stack_b->top++;
		stack_b[stack_b->top] = stack_a[stack_a->top];
		stack_a->top--;
	}
	ft_printf("pb\n");
}

void	rb(t_stack *stack_b)
{
	int	temp;
	int	i;

	i = stack_b->top;
	temp = stack_b->data[stack_b->top];
	while (i > 0)
	{
		stack_b->data[i] = stack_b->data[i - 1];
		i--;
	}
	stack_b->data[0] = temp;
	ft_printf("rb\n");
}

void	rrb(t_stack *stack_b)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack_b->data[0];
	while (i < stack_b->top)
	{
		stack_b->data[i] = stack_b->data[i + 1];
		i++;
	}
	stack_b->data[stack_b->top] = temp;
	ft_printf("rrb\n");
}
