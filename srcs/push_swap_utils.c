/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:58:13 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/20 13:29:49 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_repeated(char **av, int check)
{
	int	i;
	int	j;
	int	a;
	int	b;

	i = check;
	while (av[i] != NULL)
	{
		j = i + 1;
		a = ft_atoi(av[i]);
		while (av[j] != NULL)
		{
			b = ft_atoi(av[j]);
			if (a == b)
			{
				write(2, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(char **av, int check)
{
	int		i;
	int		a;
	int		b;
	long	c;

	i = check;
	c = ft_atol(av[check]);
	while (av[i + 1] != NULL)
	{
		a = ft_atol(av[i]);
		b = ft_atol(av[i + 1]);
		if (a > b)
			return (0);
		else if (a == b)
			return (is_repeated(av, check));
		i++;
	}
	if (av[check + 1] == NULL && (c >= INT_MIN && c <= INT_MAX))
		return (1);
	else if (c < INT_MIN || c > INT_MAX)
		write(2, "Error\n", 6);
	return (1);
}

int	check_digits(char **av, int check)
{
	int	j;
	int	count;

	while (av[check] != NULL)
	{
		j = 0;
		count = 0;
		if (array_is_sign(av[check]) == 1)
			return (1);
		while (av[check][j])
		{
			if (av[check][j] == '-' || av[check][j] == '+')
				count++;
			if (!ft_isdigit(av[check][j]) && (av[check][j] != '-' || \
				av[check][j] == '+' || count > 1))
			{
				write(2, "Error\n", 6);
				return (1);
			}
			j++;
		}
		check++;
	}
	return (0);
}

int	is_integer(char **av, int check)
{
	int		i;
	long	a;

	i = check;
	while (av[i] != NULL)
	{
		a = ft_atol(av[i]);
		if (a < INT_MIN || a > INT_MAX)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_args(char **av, int check, int size_list)
{
	if (size_list == 1)
	{
		if (is_integer(av, check) == 1)
			return (1);
		if (check_digits(av, check) == 1)
			return (1);
		return (1);
	}
	if (check_digits(av, check) == 1)
		return (1);
	if (is_integer(av, check) == 1)
		return (1);
	if (is_sorted(av, check) == 1)
		return (1);
	if (is_repeated(av, check) == 1)
		return (1);
	return (0);
}
