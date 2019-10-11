/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:25:39 by equiana           #+#    #+#             */
/*   Updated: 2019/10/11 15:43:47 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	ft_form_list(t_list **begin, t_list *new)
{
	t_list *tmp;

	if (*begin == NULL)
		ft_lstadd(begin, new);
	else
	{
		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_list	*ft_get_figure(char letter, char *buf)
{
	t_list		*tmp;
	char		**field;
	t_figure	*figure;

	if (!(figure = (t_figure*)malloc(sizeof(t_figure))))
		ft_error();
	field = ft_strsplit(buf, '\n');
	figure->letter = letter;
	figure->arr = field;
	ft_get_xy(field, &figure);
	tmp = ft_lstnew(figure, sizeof(t_figure));
	free(*field);
	free(field);
	del_content(figure);
	free(figure);
	return (tmp);
}

t_list	*ft_read_in(int fd)
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
	return (lst);
}
