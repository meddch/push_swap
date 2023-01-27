/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:01:57 by mechane           #+#    #+#             */
/*   Updated: 2023/01/27 12:04:17 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_args(int ac, char **av)
{
	char	*args;
	char	*tmp;
	char	**ags;
	int		i;

	i = 1;
	args = NULL;
	while (i < ac)
	{
		if (!av[i] || !*av[i] || !ft_strncmp(av[i], " ", 2))
			return (NULL);
		tmp = args;
		args = ft_strjoin(tmp, av[i]);
		free(tmp);
		i++;
	}
	ags = ft_split(args, ' ');
	free(args);
	return (ags);
}

int	check_args(char **av, int *p)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	if (!av || !*av)
		return (0);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && (av[i][j] == '-' || av[i][j] == '+'))
				j++;
			if ((av[i][j] < '0' || av[i][j] > '9'))
				return (0);
			j++;
		}
		i++;
	}
	*p = i;
	return (1);
}

int	check_double(char **av)
{
	int	i;
	int	j;

	i = 0;
	ft_atoi(av[i]);
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}
