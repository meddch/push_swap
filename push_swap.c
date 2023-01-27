/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:14:59 by mechane           #+#    #+#             */
/*   Updated: 2023/01/15 15:03:54 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	all_to_b(t_stack *a, t_stack *b, int sort[], int ac)
{
	int	number;
	int	index;
	int	i;

	i = 0;
	while (*a)
	{
		number = position(*a, sort[i], &index);
		if (index == -1)
			i++;
		else
		{	
			push_one_a_to_b(a, index, number);
			if (number > (sort[i + ac]))
			{	
				pb(a, b);
				rb(b);
			}
			else
				pb(a, b);
		}
	}
}

void	push_swap(t_stack *a, t_stack *b, int sort[], t_vars var)
{
	int	number;
	int	number2;
	int	index;
	int	index2;

	all_to_b(a, b, sort, var.len);
	while (*b)
	{
		number = find_max(*b, &index, var.min);
		number2 = find_bf_max(*b, &index2, number, var.min);
		if (calcul_numinstr(b, index, index2) > 0 && index2 != -1)
		{
			push_one_b_to_a(a, b, index2, number2);
			push_one_b_to_a(a, b, index, number);
			sa(a);
		}
		else if (calcul_best(b, index, index2) > 1 && index2 != -1)
		{	
			push_one_b_to_a(a, b, index2, number2);
			push_one_b_to_a(a, b, index, number);
			sa(a);
		}
		else
			push_one_b_to_a(a, b, index, number);
	}
}

void	free_stack(t_stack *a)
{
	t_stack	tmp;

	while (*a != NULL)
	{
		tmp = *a;
		(*a) = (*a)->next;
		free(tmp);
	}
}

void	go_push(t_stack *a, t_stack *b, int *arr, t_vars var)
{
	int	len;

	len = len_stack(*a);
	if (len < 10)
		small_number(a, b, len);
	else
		push_swap(a, b, arr, var);
}
