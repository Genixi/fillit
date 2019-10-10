/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:50:43 by equiana           #+#    #+#             */
/*   Updated: 2019/10/10 19:40:20 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdio.h>
char	**ft_field_gen(int size)
{
	int		i;
	int		j;
	char	**field;

	i = 0;
	if (!(field = (char**)malloc(sizeof(char*) * (size + 1))))
		ft_error();
	field[size] = 0;
	while (i < size)
	{
		if (!(field[i] = ft_strnew(size)))
			ft_error();
		j = 0;
		while (j < size)
		{
			field[i][j] = '.';
			j++;
		}
		i++;
	}
	return (field);
}

int		ft_check(char **fld, int i, int j, t_figure *fgr)
{
	int		k;
	int		l;
	int		y_f;
	int		size;
	char	**str;

	k = -1;
	y_f = fgr->y;
	str = fgr->arr;
	size = ft_strlen(fld[0]);
	//check point
//	ft_put_field(fld);
//	ft_put_field(str);
	while (str[fgr->x + (++k)])
	{
		l = 0;
		while (str[fgr->x + k][l])
		{
			if (str[fgr->x + k][l] != '.')
				if (i + k >= size || j + l - y_f >= size)
					return (0);
			if (i + k < size && j + l - y_f < size)
				if (fld[i + k][j + l - y_f] != '.' && str[fgr->x + k][l] != '.')
					return (0);
			l++;
		}
	}
	return (1);
}

void	ft_place_figure(char ***field, int i, int j, t_figure *figure)
{
	int		k;
	int		l;
	char	**tmp;
	int		count;

	k = 0;
	count = 0;
	tmp = *field;
	while ((figure->arr)[figure->x + k])
	{
		l = 0;
		while ((figure->arr)[figure->x + k][l])
		{
			if ((figure->arr)[figure->x + k][l] == '#')
			{
				tmp[i + k][j + (l - figure->y)] = figure->letter;
				count++;
				if (count == 4)
					return ;
			}
			l++;
		}
		k++;
	}
}

int		ft_recursion(char ***field, t_list *lst)
{
	int			i;
	int			j;
	char		**str;

	i = 0;
	str = *field;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (ft_check(str, i, j, (t_figure*)(lst->content)))
			{
				ft_place_figure(field, i, j, (t_figure*)(lst->content));
				if (!lst->next || ft_recursion(field, lst->next))
					return (1);
				else
					ft_clear_figure(field, (t_figure*)(lst->content));
			}
			j++;
		}
		i++;
	}
	return (0);
}

char	**ft_find_solution(t_list *lst)
{
	int		size;
	int		len;
	char	**field;
// 	check point
	int		reserve;

	size = 2;
	len = ft_list_size(lst);
	while (size * size < len * 4)
		size++;
	field = ft_field_gen(size);
	reserve = size;
	while (!ft_recursion(&field, lst))
	{
		free(field);
		size++;
		field = ft_field_gen(size);
		printf("field size: %d\n", size);
	}
	printf("start size: %d\n", reserve);
	printf("final size: %d\n", size);
	return (field);
}
