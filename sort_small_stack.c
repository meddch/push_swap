/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:37:33 by mechane           #+#    #+#             */
/*   Updated: 2023/01/15 01:14:07 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_number(t_stack *a, t_stack *b, int len)
{
	int	j;

	j = len - 3;
	if (len == 2)
		sa(a);
	else
	{
		push_min_number(a, b, j);
		push_swap_three(a);
		while (*b)
			pa(a, b);
	}
}

void	sort_s(t_stack *a, int number)
{
	if (number == 1)
		sa(a);
	else if (number == 2)
	{
		sa(a);
		rra(a);
	}
	else if (number == 3)
		ra(a);
	else if (number == 4)
	{
		sa(a);
		ra(a);
	}
	else if (number == 5)
		rra(a);
}

int	check_three(int array[])
{
	if (array[1] < array[0] && array[0] < array[2])
		return (1);
	else if (array[0] > array[1] && array[1] > array[2])
		return (2);
	else if (array[1] < array[2] && array[0] > array[2])
		return (3);
	else if (array[1] > array[2] && array[0] < array[2])
		return (4);
	else if (array[1] > array[0] && array[0] > array[2])
		return (5);
	return (0);
}

void	push_swap_three(t_stack *a)
{
	int		number;
	int		i;
	int		*arr;
	t_stack	b;

	b = *a;
	i = 0;
	arr = malloc(sizeof(int) * 3);
	if (!arr)
		return ;
	while (i < 3)
	{
		arr[i] = (b)->data;
		b = b->next;
		i++;
	}
	number = check_three(arr);
	sort_s(a, number);
	free(arr);
}
