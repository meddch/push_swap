/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:43:13 by mechane           #+#    #+#             */
/*   Updated: 2023/01/26 18:49:47 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stackNode	*ft_last(t_stack *mystack)
{
	if (!mystack)
		return (NULL);
	while ((*mystack)->next != NULL)
	{
		(*mystack) = (*mystack)->next;
	}
	return (*mystack);
}

t_stackNode	*ft_prv_last(t_stack *mystack)
{
	if (!mystack)
		return (NULL);
	while ((*mystack)->next->next != NULL)
	{
		(*mystack) = (*mystack)->next;
	}
	return (*mystack);
}

t_stack	*push(int value, t_stack *head)
{
	t_stackNode	*new;

	new = malloc(sizeof(t_stackNode));
	if (!new)
		return (0);
	new->data = value;
	new->next = *head;
	*head = new;
	return (head);
}

long	pop(t_stack *head)
{
	long		pop_value;
	t_stackNode	*tmp;

	if (!*head)
		return (2147483648);
	pop_value = (*head)->data;
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
	return (pop_value);
}

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
