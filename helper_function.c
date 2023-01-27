/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:52:42 by mechane           #+#    #+#             */
/*   Updated: 2023/01/26 18:52:48 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_stack(t_stack a)
{
	int	i;

	i = 0;
	if (!a)
		return (0);
	while (a != 0)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	position(t_stack a, int number, int *index)
{
	int	i;

	i = 0;
	while (a != NULL)
	{
		if (a->data <= number)
		{
			*index = i;
			return (a->data);
		}
		a = a->next;
		i++;
	}
	*index = -1;
	return (0);
}

int	find_max(t_stack a, int *index, int min)
{
	int	number;
	int	i;

	number = min - 1;
	i = 0 ;
	while (a != NULL)
	{
		if (a->data > number)
		{
			*index = i ;
			number = a->data;
		}
		a = a->next;
		i++;
	}
	return (number);
}

int	calcul_best(t_stack *a, int index1, int index2)
{
	int	len;

	len = len_stack(*a);
	if (index1 > len / 2)
		index1 = len - index1;
	if (index2 > len / 2)
		index2 = len - index2;
	return (index1 - index2);
}
