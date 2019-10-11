/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:09:32 by equiana           #+#    #+#             */
/*   Updated: 2019/10/11 15:42:25 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	ft_lstdelall(t_list **alst)
{
	t_list *tmp;
	t_list *ttmp;

	tmp = *alst;
	ttmp = tmp;
	while (tmp)
	{
		ttmp = tmp;
		if (tmp->next)
			tmp = tmp->next;
		else
			tmp = NULL;
		del_content((t_figure*)(ttmp->content));
		free(ttmp);
	}
	*alst = NULL;
}

void	del_content(t_figure *tmp)
{
	int		i;
	char	**str;

	i = 0;
	str = tmp->arr;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(str);
}
