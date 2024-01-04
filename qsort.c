/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:27:47 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/03 17:39:04 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/push_swap.c"

void	quick_sort_stack(t_stack *stack) {
	int	pivot;
	int	pivot_count;
	t_stack	temp_stack;
	
	int pivot = stack->data[stack->top]; // Choose the top element as pivot
	temp_stack.data = malloc(sizeof(int) * (stack->top + 1));
	temp_stack.top = -1;
	int pivot_count = 0;

	// Partition
	while (stack->top >= 0) {
		if (stack->data[stack->top] == pivot)
		{
			pivot_count++;
			stack->top--;
		}
		else if (stack->data[stack->top] < pivot)
		{
			temp_stack.data[++temp_stack.top] = stack->data[stack->top--];
		}
		else
		{
			stack->data[stack->top - pivot_count] = stack->data[stack->top--];
		}
	}
	// Recursively sort the stacks
	quick_sort_stack(&temp_stack);
	quick_sort_stack(stack);
	// Merge the stacks
	while (temp_stack.top >= 0)
		stack->data[++stack->top] = temp_stack.data[temp_stack.top--];
	while (pivot_count > 0)
	{
		stack->data[++stack->top] = pivot;
		pivot_count--;
	}
	free(temp_stack.data);
}