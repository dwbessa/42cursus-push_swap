/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:45:05 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/03 18:00:23 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->top >= 0) {
		// Find the minimum element in stack_a
		int min_index = 0;
		int min_value = stack_a->data[0];
		int i = 0;
		while (i <= stack_a->top) {
			if (stack_a->data[i] < min_value) {
				min_value = stack_a->data[i];
				min_index = i;
			}
			ra(stack_a);
			i++;
		}

		// Move the stack_a back to its original state
		while (i-- > 0) {
			rra(stack_a);
		}

		// Move the minimum element to stack_b
		while (min_index-- > 0) {
			ra(stack_a);
		}
		pb(stack_b, stack_a);
	}

	// Move all elements back to stack_a
	while (stack_b->top >= 0) {
		pa(stack_a, stack_b);
	}
}