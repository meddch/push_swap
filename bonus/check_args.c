/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:01:57 by mechane           #+#    #+#             */
/*   Updated: 2023/01/27 12:04:00 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		if (!av[i] || !*av[i] || !ft_strncmp_c(av[i], " ", 2))
			return (NULL);
		tmp = args;
		args = ft_strjoin_c(tmp, av[i]);
		free(tmp);
		i++;
	}
	ags = ft_split_c(args, ' ');
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

int	ft_atoi(const char *str)
{
	long long		res;
	int				sign;
	int				i;

	i = 0;
	res = 0;
	sign = 1;
	if (str[0] == '\0')
		return (0);
	while (((((str[i] >= 9) && (str[i] <= 13))
				|| (str[i] == ' ')) && (str[i] != '\0')))
				i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if ((sign * res) > INT_MAX || (sign * res) < INT_MIN)
		return (ft_abort());
	return (sign * res);
}
