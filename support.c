/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:25:03 by equiana           #+#    #+#             */
/*   Updated: 2019/10/11 15:34:49 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	ft_get_xy(char **str, t_figure **figure)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
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

void	ft_clear_figure(char ***field, t_figure *figure)
{
	int		i;
	int		j;
	char	**str;

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

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

void	ft_put_field(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putstr(str[i]);
		ft_putchar('\n');
		ft_strdel(&(str[i]));
		i++;
	}
	free(str);
}

void	ft_output(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		ft_put_field(((t_figure*)(tmp->content))->arr);
		tmp = tmp->next;
	}
	free(tmp);
}
