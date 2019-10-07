/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:25:03 by equiana           #+#    #+#             */
/*   Updated: 2019/10/07 16:33:42 by equiana          ###   ########.fr       */
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
