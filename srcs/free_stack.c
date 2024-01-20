/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:22:05 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/20 15:04:30 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack_a, t_stack *stack_b, char **av, int ac)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[i] != NULL)
			free(av[i++]);
		free(av);
	}
	free(stack_a->data);
	free(stack_b->data);
	free(stack_a);
	free(stack_b);
}

void	free_split(char **av)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
		free(av[i++]);
	free(av);
}
