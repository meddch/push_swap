/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:32:16 by mechane           #+#    #+#             */
/*   Updated: 2023/01/26 15:37:59 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*tronsfer_array(char **array, int argc)
{
	int	i;
	int	*arr;
	int	j;

	i = 0;
	arr = malloc(sizeof(int) * argc + 1);
	if (!arr)
		return (0);
	j = 0;
	while (array[i])
	{
		arr[j] = ft_atoi(array[i]);
		i++;
		j++;
	}
	return (arr);
}

static void	simple(int *sort, int len, int i)
{
	int	tmp;
	int	j;

	j = i + 1;
	while (j < len)
	{
		if (sort[i] > sort[j])
		{
			tmp = sort[i];
			sort[i] = sort[j];
			sort[j] = tmp;
		}
		j++;
	}
}

int	*sortarray(int *a, int len)
{
	int	i;
	int	*sort;

	sort = malloc(sizeof(int) * len);
	if (!sort)
		return (0);
	i = 0 ;
	while (i < len)
	{
		sort[i] = a[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		simple(sort, len, i);
		i++;
	}
	free(a);
	return (sort);
}

int	*file_array(int *array, int *r)
{
	int	*a;
	int	len;
	int	offset;
	int	i;
	int	div;

	if (*r > 150)
		len = 9;
	else
		len = 5;
	a = malloc(sizeof(int) * 2 * len);
	offset = *r / len;
	div = offset;
	i = 0;
	while (i < (len - 1))
	{
		a[i] = array[offset - 1];
		a[i + len] = array[offset -(div / 2) - 1];
		offset += *r / len ;
		i++;
	}
	a[i] = array[*r - 1];
	a[i + len] = array[offset -(div / 2) - 1];
	*r = len;
	return (a);
}

int	*array_to_chuncks(int *arr, int *len, int *min)
{
	int	*g;

	*min = arr[0];
	g = file_array(arr, len);
	free(arr);
	return (g);
}
