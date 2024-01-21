/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:42:27 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/21 10:45:45 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/includes/libft.h"

typedef struct s_stack
{
	int	top;
	int	*data;
}	t_stack;

int			is_sorted_stack(t_stack *stack);
void		sort_stack(t_stack *stack_a, t_stack *stack_b);
t_stack		*create_stack(char **av, int size_list, int check, int is_aux);
void		use_sort(t_stack *stack_a, t_stack *stack_b, int size);
int			split_len(char **av, int ac);
int			check_args(char **av, int check, int size_list);
int			array_is_sign(char *string);
void		free_stack(t_stack *stack_a, t_stack *stack_b, char **av, int ac);
void		free_split(char **av);
int			check_all(int ac, char **av, int check, int size_list);
int			count_args(const char *str, char c);

//************ operations a
void		sa(t_stack *stack_a);
void		pa(t_stack *stack_a, t_stack *stack_b);
void		ra(t_stack *stack_a);
void		rra(t_stack *stack_a);

//************ operations b
void		sb(t_stack *stack_b);
void		pb(t_stack *stack_b, t_stack *stack_a);
void		rb(t_stack *stack_b);
void		rrb(t_stack *stack_b);

//************ operations multi
void		ss(t_stack *stack_a, t_stack *stack_b);
void		rr(t_stack *stack_a, t_stack *stack_b);
void		rrr(t_stack *stack_a, t_stack *stack_b);

//************ sort algorithms
void		sort_3(t_stack *stack_a);
void		sort_5(t_stack *stack_a, t_stack *stack_b);
void		sort_big(t_stack *stack_a, t_stack *stack_b);

#endif