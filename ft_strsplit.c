/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:37:45 by equiana           #+#    #+#             */
/*   Updated: 2019/09/14 17:18:53 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		free_memory(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(str);
}

static	char	**fill_array(char **res, char const *str, char c, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = 0;
	while (str[i] && (len <= size))
	{
		if (str[i] != c)
		{
			while (str[i] != c && str[i] != '\0')
			{
				res[len][j] = str[i];
				i++;
				j++;
			}
			res[len][j] = '\0';
			j = 0;
			len++;
		}
		i++;
	}
	return (res);
}

static	size_t	number_of_words(char const *str, char c)
{
	int num;
	int white;
	int el;
	int j;

	j = 0;
	num = 0;
	el = 0;
	while (str[j] != '\0')
	{
		if ((str[j] != c) && (el == 0))
		{
			num++;
			white = 0;
			el = 1;
		}
		if ((str[j] == c) && (white == 0))
		{
			white = 1;
			el = 0;
		}
		j++;
	}
	return (num);
}

static char		**form_array(char **res, char const *str, char c, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	len = 0;
	j = 0;
	while (str[i] && (len <= size))
	{
		if (str[i] != c && str[i])
		{
			while (str[i] != c && str[i])
			{
				i++;
				j++;
			}
			if (!(res[len] = (char *)malloc(sizeof(char) * (j + 1))))
				return (NULL);
			len++;
		}
		i++;
		j = 0;
	}
	return (res);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**res;
	size_t	size;

	if (!str || !c)
		return (NULL);
	size = number_of_words(str, c);
	if (!(res = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	if (!form_array(res, str, c, size))
	{
		free_memory(res);
		return (NULL);
	}
	fill_array(res, str, c, size);
	res[size] = NULL;
	return (res);
}
