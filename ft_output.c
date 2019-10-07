/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:47:07 by equiana           #+#    #+#             */
/*   Updated: 2019/10/07 16:13:44 by equiana          ###   ########.fr       */
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

void ft_print_arr(char **str)
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

//	printf("ft_output start here\n");	
	tmp = lst;
//	printf("tmp = NULL?: %d\n", (tmp == NULL));
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
		ft_print_arr(str);
		tmp = tmp->next;
	}
}
