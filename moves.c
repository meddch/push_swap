/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 12:15:59 by mechane           #+#    #+#             */
/*   Updated: 2023/01/14 22:40:04 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	long	temp1;
	long	temp2;

	temp1 = pop(a);
	if (temp1 == (2147483648))
		return ;
	temp2 = pop(a);
	if (temp2 == (2147483648))
	{
		push(temp2, a);
		return ;
	}
	push(temp1, a);
	push(temp2, a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	long	temp1;
	long	temp2;

	temp1 = pop(b);
	if (temp1 == (2147483648))
		return ;
	temp2 = pop(b);
	if (temp2 == (2147483648))
	{
		push(temp2, b);
		return ;
	}
	push(temp1, b);
	push(temp2, b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

int	pa(t_stack *a, t_stack *b)
{
	long	temp;

	temp = pop(b);
	if (temp == (2147483648))
		return (0);
	push(temp, a);
	write(1, "pa\n", 3);
	return (1);
}

int	pb(t_stack *a, t_stack *b)
{
	long	temp;

	temp = pop(a);
	if (temp == (2147483648))
		return (0);
	push(temp, b);
	write(1, "pb\n", 3);
	return (1);
}
