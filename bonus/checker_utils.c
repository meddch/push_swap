/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:53:31 by mechane           #+#    #+#             */
/*   Updated: 2023/01/26 18:49:53 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_is_sorted(t_stack a)
{
	int	tmp;

	tmp = a->data;
	while (a)
	{
		if (tmp > a->data)
			return (0);
		tmp = a->data;
		a = a->next;
	}
	return (1);
}

void	free_stack(t_stack *a)
{
	t_stack	tmp;

	if (!a)
		return ;
	while (*a != NULL)
	{
		tmp = *a;
		(*a) = (*a)->next;
		free(tmp);
	}
}

int	ft_abort_stack(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	return (exit(0), 0);
}

int	ft_abort(void)
{
	write(2, "Error\n", 6);
	return (exit(0), 0);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
