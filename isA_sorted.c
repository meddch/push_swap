/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isA_sorted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:18:52 by mechane           #+#    #+#             */
/*   Updated: 2023/01/15 01:10:15 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_number(t_stack a, int *position, int *len)
{
	int	number;
	int	i;

	i = 0 ;
	number = a->data;
	while (a != NULL)
	{
		if (number > a->data)
		{
			*position = i;
			number = a->data;
		}
		a = a->next ;
		*len += 1;
		i++;
	}
	return (number);
}

void	push_min_number(t_stack *a, t_stack *b, int lens)
{
	int	number;
	int	position;
	int	len ;
	int	i ;

	i = 0;
	while (i < lens)
	{
		position = 0 ;
		len = 0;
		number = min_number(*a, &position, &len);
		if (position > len / 2)
		{
			while ((*a)->data != number)
				rra(a);
		}
		else
		{
			while ((*a)->data != number)
				ra(a);
		}
		pb(a, b);
		i++;
	}
}

int	calcul_numinstr(t_stack *a, int index1, int index2)
{
	int	len;

	len = len_stack(*a);
	if ((index1 > (len / 2)) && (index2 > (len / 2)) && (index2 > index1))
		return (1);
	if ((index1 <= (len / 2)) && (index2 <= (len / 2)) && (index2 < index1))
		return (1);
	return (0);
}

void	push_one_a_to_b(t_stack *a, int index, int number)
{
	if (index > (len_stack(*a) / 2))
	{	
		while ((*a)->data != number)
			rra(a);
	}
	else
	{	
		while ((*a)->data != number)
			ra(a);
	}
}

void	push_one_b_to_a(t_stack *a, t_stack *b, int index, int number)
{
	if (index > (len_stack(*b) / 2))
	{	
		while ((*b)->data != number)
			rrb(b);
	}
	else
	{	
		while ((*b)->data != number)
			rb(b);
	}
	pa(a, b);
}
