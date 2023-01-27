/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:04:24 by mechane           #+#    #+#             */
/*   Updated: 2023/01/15 01:09:00 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_bf_max(t_stack a, int *index, int max, int min)
{
	int	number;
	int	i;

	number = min - 1;
	i = 0 ;
	while (a != NULL)
	{
		if (a->data < max && a->data > number)
		{
			*index = i ;
			number = a->data;
		}
		a = a->next;
		i++;
	}
	return (number);
}

int	check_if_sorted(char **av)
{
	int	i;

	i = 0;
	while (av[i + 1])
	{
		if (ft_atoi(av[i]) < ft_atoi(av[i + 1]))
			i++;
		else
			return (0);
	}
	return (1);
}
