/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 12:36:33 by mechane           #+#    #+#             */
/*   Updated: 2023/01/27 12:15:10 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void free_all(int ac, char **av)
{
	while(ac >= 0)
		free(av[ac--]);
	free(av);
	return ;
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

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	**args;
	int		*arr;
	t_vars	var;

	if (ac <= 1)
		return (0);
	args = get_args(ac, av);
	if (!(check_args(args, &ac)) || !(check_double(args)))
		return (ft_abort(), free_all(ac, args), 0);
	if (check_if_sorted(args))
		return (free_all(ac, args), 0);
	arr = tronsfer_array(args, ac);
	arr = sortarray(arr, ac);
	arr = array_to_chuncks(arr, &ac, &var.min);
	var.len = ac;
	fill(check_double(args), args, &a);
	go_push(&a, &b, arr, var);
	free(arr);
	free_stack(&a);
	return (0);
}
