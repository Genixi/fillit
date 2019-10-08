/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:25:39 by equiana           #+#    #+#             */
/*   Updated: 2019/10/08 19:48:39 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdio.h>
void ft_form_list(t_list **begin, t_list *new)
{
	t_list *tmp;

	if (*begin == NULL)
	{
//		printf("case 1\n");
		ft_lstadd(begin, new);
	}
	else
	{
//		printf("case 2\n");
		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int ft_get_height(char **str)
{
	int i;
	int j;
	int size;	
	int last;
	int first;
	
	i = 0;
	last = -1;
	first = -1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '#')
			{
				if (first == -1)
					first = i;
				if (last == -1 || i > last)
					last = i;
			}
			j++;
		}
		i++;
	}
	size = last - first + 1;
	if (!size && first != -1)
		size = 1;
	return size;
}

int ft_get_width(char **str)
{
	int i;
	int j;
	int last;
	int first;
	int size;

	i = 0;
	last = -1;
	first = -1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '#')
			{
				if (j < first || first == -1)
					first = j;
				if (j > last || last == -1)
					last = j;
			}
			j++;
		}
		i++;
	}
	size = last - first + 1;	
	if (!size && first != -1)
		size = 1;
	return size;
}

t_list	*ft_get_figure(char letter, char *buf)
{
	t_list *tmp;
	char **field;
	t_figure *figure;

	if (!(figure = (t_figure*)malloc(sizeof(t_figure))))
		ft_error();
	field = ft_strsplit(buf, '\n');
	figure->letter = letter;
	figure->arr = field;	
	figure->width = ft_get_width(field);
	figure->height = ft_get_height(field);
	ft_get_xy(field, &figure);
	tmp = ft_lstnew(figure, sizeof(t_figure));
	return (tmp);
}

t_list *ft_read_in(int fd)
{
	t_list	*lst;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*l_line;
	char	letter;

	ret = 1;
	letter = 'A';
	lst = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!ft_validate(ret, buf))
			ft_error();
		l_line = buf;
		ft_form_list(&lst, ft_get_figure(letter, buf));
		letter++;
	}
	if (!ft_validate(ret, l_line))
		ft_error();
	printf("ft_read_in return\n");
	return (lst);
}
