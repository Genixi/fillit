/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:50:43 by equiana           #+#    #+#             */
/*   Updated: 2019/10/07 17:16:01 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdio.h>
char **ft_field_gen(int size)
{
	int i;
	int j;
	char **field;

	i = 0;
	if (!(field = (char**)malloc(sizeof(char*) * size + 1)))
		ft_error();
	field[size] = '\0';
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

int ft_check_place(char **field, int i, int j, t_figure *figure)
{
	int k;
	int l;
	int x_f;
	int y_f;
	char **str;
	
	k = 0;
	str = figure->arr;
	x_f = figure->x;
	y_f = figure->y;
	while (k < figure->height)
	{
		l = 0;
		while (l < figure->width)
		{
			if (field[i + k][j + l] != '.' && str[x_f + k][y_f + l] != '.')
				return (0);
			l++;
		}
		k++;
	}
	return (1);				
}

void ft_place_figure(char ***field, int i, int j, t_figure *figure)
{
	int k;
	int l;
	char **tmp;
	char **str;

	k = 0;
	l = 0;
	*tmp = field;
	str = figure->arr;
	while (k < figure->width
//!!! дописать отсюда
	
}	


char **ft_find_solution(t_list *lst)
{
	int i;
	int size;
	char **field;

	i = 4;
	while (!(size = ft_sqrt(ft_list_size(lst) * i)))
		i++;
	field = ft_field_gen(size);
	while(!ft_recursion(&field, lst))
	{
		free(field);
		size++;
		field = ft_field_gen(size);
	}
	return (field);
}
