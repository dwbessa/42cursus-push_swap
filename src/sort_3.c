/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:25:01 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/06 18:28:35 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
