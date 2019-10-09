/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:25:03 by equiana           #+#    #+#             */
/*   Updated: 2019/10/09 16:26:52 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdio.h>
void ft_get_xy(char **str, t_figure **figure)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while(str[i][j])
		{
			if (str[i][j] == '#')
				break ;
			j++;
		}
		if (str[i][j] == '#')
			break ;
		i++;
	}
	(*figure)->x = i;
	(*figure)->y = j;
}

void ft_clear_figure(char ***field, t_figure *figure)
{
	int i;
	int j;
	char **str;
	
	i = 0;
	str = *field;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == figure->letter)
				str[i][j] = '.';
			j++;
		}
		i++;
	}
}

void ft_error(void)
{
	ft_putstr("error\n");
	exit (0);
}

void ft_put_field(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}

void ft_output(t_list *lst)
{
	t_list *tmp;
	char ch;
	char **str;
	int height;
	int width;
	int x;
	int y;

	tmp = lst;
	while (tmp)
	{
		ch = ((t_figure*)(tmp->content))->letter;
		height = ((t_figure*)(tmp->content))->height;
		width = ((t_figure*)(tmp->content))->width;
		str = ((t_figure*)(tmp->content))->arr;
		x = ((t_figure*)(tmp->content))->x;
		y = ((t_figure*)(tmp->content))->y;
//		ft_putchar(ch);
//		ft_putchar('\n');
		printf("figure: %c with height: %d width: %d, x: %d, y %d\n", ch, height, width, x, y);
		ft_put_field(str);
		tmp = tmp->next;
	}
}

