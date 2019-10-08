/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:50:43 by equiana           #+#    #+#             */
/*   Updated: 2019/10/08 19:50:37 by equiana          ###   ########.fr       */
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

int ft_check_place(char **field, int i, int j, t_figure *figure)
{
	int k;
	int l;
	int y_f;
	int size;
	char **str;
	
	k = 0;
	y_f = figure->y;
	str = figure->arr;
	size = ft_strlen(field[0]);
	while (str[figure->x + k])
	{
		l = 0;
		while (str[figure->x + k][l])
		{
			if ((i + k >= size || j + l >= size) && str[figure->x + k][l] != '.')
				return (0);
			if (i + k < size && j + l < size)
				if (field[i + k][j + (l - y_f)] != '.' && str[figure->x + k][l] != '.')
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
	int count;
	
	k = 0;
	l = 0;
	count = 0;
	tmp = *field;
	str = figure->arr;
	while (str[figure->x + k])
	{
		l = 0;
		while (str[figure->x + k][l])
		{
			if (str[figure->x + k][l] == '#')
			{
				tmp[i + k][j + (l - figure->y)] = figure->letter;
				if(++count == 4)
					return ;
			}
			if (figure->letter == 'D')
//				printf("row for D: %d, column for D: %d\n", i+k, j+l);
			l++;
		}
		k++;
	}
}

int ft_recursion(char ***field, t_list *lst)
{
	int i;
	int j;
	t_figure *figure;
	char **str;

	i = 0;
	j = 0;
	str = *field;
	while (str[i])
	{
		j = 0;
		while(str[i][j])
		{
			figure = (t_figure*)(lst->content);
//			printf("working with figure: %c\n", figure->letter);
			if (ft_check_place(str, i, j, figure))
			{
				ft_place_figure(field, i, j, figure);
				// check point
//				printf("place new figure\n");
				ft_put_field(str);
				if (!lst->next || ft_recursion(field, lst->next))
					return (1);
				else
					ft_clear_figure(field, figure);
			}
			j++;
		}
		i++;
	}
	return (0);
}

char **ft_find_solution(t_list *lst)
{
	int i;
	int size;
	char **field;

	i = 4;
	printf("start find_solution\n");
	ft_output(lst);
	while (!(size = ft_sqrt(ft_list_size(lst) * i)))
		i++;
	field = ft_field_gen(size);
//  check point:
	printf("new field, size: %d\n", size);
	ft_put_field(field);
	while(!ft_recursion(&field, lst))
	{
		free(field);
		size++;
		field = ft_field_gen(size);
//	check point
		printf("new field, size: %d\n", size);
		ft_put_field(field);
	}
	return (field);
}
