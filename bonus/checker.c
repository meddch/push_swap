/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:37:40 by mechane           #+#    #+#             */
/*   Updated: 2023/01/27 12:16:43 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_more(char *line, t_stack *a, t_stack *b)
{
	int	r;

	r = 1;
	if (!ft_strncmp_c(line, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp_c(line, "rra\n", ft_strlen(line)))
		rra(a);
	else if (!ft_strncmp_c(line, "rrb\n", ft_strlen(line)))
		rrb(b);
	else if (!ft_strncmp_c(line, "rrr\n", ft_strlen(line)))
		rrr(a, b);
	else if (!ft_strncmp_c(line, "rb\n", ft_strlen(line)))
		rb(b);
	else
		r = 0;
	return (r);
}

static void	read_instruction(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!ft_strncmp_c(line, "pa\n", ft_strlen(line)))
			pa(a, b);
		else if (!ft_strncmp_c(line, "pb\n", ft_strlen(line)))
			pb(a, b);
		else if (!ft_strncmp_c(line, "sa\n", ft_strlen(line)))
			sa(a);
		else if (!ft_strncmp_c(line, "sb\n", ft_strlen(line)))
			sb(b);
		else if (!ft_strncmp_c(line, "ss\n", ft_strlen(line)))
			ss(a, b);
		else if (!ft_strncmp_c(line, "ra\n", ft_strlen(line)))
			ra(a);
		else
		{
			if (!check_more(line, a, b))
				ft_abort_stack(a, b);
		}
		free(line);
		line = get_next_line(0);
	}
}

static void	fill(int ac, char **av, t_stack *a)
{
	while (--ac >= 0)
	{	
		a = push(ft_atoi(av[ac]), a);
		free(av[ac]);
	}
	free(av);
	return ;
}

static void free_all(int ac, char **av)
{
	while(ac >= 0)
		free(av[ac--]);
	free(av);
	return ;
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	**args;

	if (ac <= 1)
		return (0);
	args = get_args(ac, av);
	if (!(check_args(args, &ac)) || !(check_double(args)))
		return (ft_abort(), free_all(ac, args), 0);
	fill(check_double(args), args, &a);
	read_instruction(&a, &b);
	if (check_is_sorted(a) && !b)
		write(2, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
