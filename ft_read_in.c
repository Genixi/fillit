/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:25:39 by equiana           #+#    #+#             */
/*   Updated: 2019/10/05 16:26:06 by equiana          ###   ########.fr       */
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

t_list	*ft_get_figure(char letter, char *buf)
{
	t_list *tmp;
	t_figure *figure;

	if (!(figure = (t_figure*)malloc(sizeof(t_figure))))
		ft_error();
	figure->letter = letter;
	figure->arr = buf;
	tmp = ft_lstnew(figure, sizeof(t_figure));
//	printf("element char: %c\n", ((t_figure*)(tmp->content))->letter);
//	printf("element size: %zu\n", (tmp->content_size));
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
//		printf("letter: %c\n", letter);
//		printf("lst still null?: %d\n", (lst == NULL));
		letter++;
	}
	if (!ft_validate(ret, l_line))
		ft_error();
	return (lst);
}
