/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:49:34 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/12 08:51:54 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
