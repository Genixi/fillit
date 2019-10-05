/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:47:07 by equiana           #+#    #+#             */
/*   Updated: 2019/10/05 16:26:44 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdio.h>
void ft_error(void)
{
	ft_putstr("error\n");
	exit (0);
}

void ft_output(t_list *lst)
{
	t_list *tmp;
	char ch;

//	printf("ft_output start here\n");	
	tmp = lst;
//	printf("tmp = NULL?: %d\n", (tmp == NULL));
	while (tmp)
	{
		ch = ((t_figure*)(tmp->content))->letter;
		ft_putchar(ch);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
