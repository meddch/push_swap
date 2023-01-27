/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_moves2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:19:37 by mechane           #+#    #+#             */
/*   Updated: 2023/01/26 17:57:14 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_stack *a)
{
	t_stackNode	*head;
	t_stackNode	*tmp;
	t_stackNode	*last;

	if (len_stack(*a) < 2)
		return ;
	if (len_stack(*a) == 2)
		return (sa(a));
	last = (*a);
	head = (*a)->next;
	tmp = ft_last(a);
	tmp->next = last;
	(tmp)->next->next = NULL;
	(*a) = head;
}

void	rb(t_stack *b)
{
	t_stackNode	*head;
	t_stackNode	*tmp;
	t_stackNode	*last;

	if (len_stack(*b) < 2)
		return ;
	last = (*b);
	head = (*b)->next;
	tmp = ft_last(b);
	tmp->next = last;
	(tmp)->next->next = NULL;
	(*b) = head;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack *a)
{
	t_stackNode	*tmp;
	t_stackNode	*tmp1;
	t_stackNode	*head;
	t_stackNode	*last;

	if (len_stack(*a) < 2)
		return ;
	tmp = (*a);
	tmp1 = (*a);
	head = ft_last(a);
	last = ft_prv_last(&tmp1);
	head->next = (tmp);
	last->next = NULL;
}

void	rrb(t_stack *b)
{
	t_stackNode	*tmp;
	t_stackNode	*tmp1;
	t_stackNode	*head;
	t_stackNode	*last;

	if (len_stack(*b) < 2)
		return ;
	tmp = (*b);
	tmp1 = (*b);
	head = ft_last(b);
	last = ft_prv_last(&tmp1);
	head->next = (tmp);
	last->next = NULL;
}
