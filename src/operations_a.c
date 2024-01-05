/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:01:22 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/05 16:51:29 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	int	temp;

	temp = stack_a->data[stack_a->top];
	stack_a->data[stack_a->top] = stack_a->data[stack_a->top - 1];
	stack_a->data[stack_a->top - 1] = temp;
	ft_printf("sa\n");
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->top >= 0)
	{
		stack_a->top++;
		stack_a[stack_a->top] = stack_b[stack_b->top];
		stack_b->top--;
	}
	ft_printf("pa\n");
}

void	ra(t_stack *stack_a)
{
	int	temp;
	int	i;

	i = stack_a->top;
	temp = stack_a->data[stack_a->top];
	while(i > 0)
	{
		stack_a->data[i] = stack_a->data[i - 1];
		i--;
	}
	stack_a->data[0] = temp;
	ft_printf("ra\n");
}

void	rra(t_stack *stack_a)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack_a->data[0];
	while (i < stack_a->top)
	{
		stack_a->data[i] = stack_a->data[i + 1];
		i++;
	}
	stack_a->data[stack_a->top] = temp;
	ft_printf("rra\n");
}
