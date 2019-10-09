/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:50:43 by equiana           #+#    #+#             */
/*   Updated: 2019/10/09 18:20:23 by equiana          ###   ########.fr       */
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

int ft_check(char **field, int i, int j, t_figure *figure)
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
//	printf("checking position i: %d, j:%d at field:\n", i, j);
	ft_put_field(field);
//	printf("with figure:\n");
	ft_put_field(str);
	while (str[figure->x + k])
	{
		l = 0;
		while (str[figure->x + k][l])
		{
			if ((i + k >= size || j + l - y_f >= size) && str[figure->x + k][l] != '.')
			{
//				printf("check failed case 1 i+k: %d, j+l: %d str: %c\n", i+k, j+l, str[figure->x+k][l]);
				return (0);
			}
			if (i + k < size && j + l - y_f < size)		
				if (field[i + k][j + (l - y_f)] != '.' && str[figure->x + k][l] != '.')
				{
//					printf("check failed case 2 i+k: %d, j+l: %d str: %c\n", i+k, j+l, str[figure->x+k][l]);
					return (0);
				}
			l++;
		}
		k++;
	}
//	printf("check passed!!\n");
	return (1);				
}

void ft_place_figure(char ***field, int i, int j, t_figure *figure)
{
	int k;
	int l;
	char **tmp;
	int count;
	
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
				if(count == 4)
					return ;
			}
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
			if (ft_check(str, i, j, figure))
			{
				ft_place_figure(field, i, j, figure);
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
	int size;
	char **field;

//	ft_output(lst);
	size = 2;
	field = ft_field_gen(size);
	while(!ft_recursion(&field, lst))
	{
		free(field);
		size++;
		field = ft_field_gen(size);
	}
//	printf("final size: %d\n", size);
	return (field);
}
