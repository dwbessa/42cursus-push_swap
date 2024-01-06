/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:42:27 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/06 17:44:45 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

typedef struct s_stack
{
	int	top;
	int	*data;
}	t_stack;

int				is_sorted(t_stack *stack);
void 			sort_stack(t_stack *stack_a, t_stack *stack_b);
t_stack			*create_stack(char **av, int size, int check);
void			use_sort(t_stack *stack_a, t_stack *stack_b, int size);
int				split_len(char **av);

//************ operations a
void			sa(t_stack *stack_a);
void			pa(t_stack *stack_a, t_stack *stack_b);
void			ra(t_stack *stack_a);
void			rra(t_stack *stack_a);

//************ operations b
void			sb(t_stack *stack_b);
void			pb(t_stack *stack_b, t_stack *stack_a);
void			rb(t_stack *stack_b);
void			rrb(t_stack *stack_b);

//************ operations multi
void			ss(t_stack *stack_a, t_stack *stack_b);
void			rr(t_stack *stack_a, t_stack *stack_b);
void			rrr(t_stack *stack_a, t_stack *stack_b);


//************ sort algorithms
void			sort_3(t_stack *stack_a);
void			sort_5(t_stack *stack_a, t_stack *stack_b);

//*********** exclude

void			print_stack(t_stack *stack_a);

#endif