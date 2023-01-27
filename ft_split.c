/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:37:11 by mechane           #+#    #+#             */
/*   Updated: 2023/01/15 00:59:01 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sbr;
	unsigned int	i;
	unsigned int	j;

	j = len;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		j = ft_strlen(s + start);
	sbr = (char *)malloc((j + 1) * sizeof(char));
	if (sbr == NULL)
		return (NULL);
	i = j;
	while (j--)
	{
		*sbr = s[start];
		start++;
		sbr++;
	}
	*sbr = '\0';
	return (sbr - i);
}

static int	num_word(const char *str, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		while (str[i] != c && str[i])
		{
			if (str[i + 1] == c || str[i + 1] == '\0')
				n++;
			i++;
		}
	}
	return (n);
}

static int	word_len(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
	}
	return (i);
}

static char	**free_all(char **tab, int j)
{
	while (j >= 0)
		free(tab[j--]);
	free(tab);
	tab = NULL;
	return (tab);
}

char	**ft_split(const char *str, char c)
{
	int			i;
	int			j;
	char		**tab;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	tab = (char **)malloc((num_word(str, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		if (str[i] != c)
		{
			tab[j] = ft_substr(str, i, (word_len((str + i), c)));
			if (!tab[j])
				return (free_all(tab, j));
			i = i + word_len(str + i, c) - 1;
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}
