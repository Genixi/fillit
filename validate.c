/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:47:06 by equiana           #+#    #+#             */
/*   Updated: 2019/10/01 22:39:18 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* 
** return 1 if correct, 0 otherwise
*/

int check_size(int ret, char *str)
{
	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n')
		return (0);
	if (str[19] != '\n' || str[20] != '\n')
		return (0);
	if (ret && str[21] != '\n')
		return (0);	
	return (1);
}

/*
** return 1 if correct, 0 otherwise
*/

int check_matrix(char *str)
{
	int i;
	int count;
	int cp

	i = 0;
	count = 0;
	while (str[i])
	{
		cp = 0;
		if (str[i] != '.' || str[i] != '#' || str[i] != '\n')
			return (0);
		if (str[i] == '#')
		{
			count++;
			cp = cp + (int)(i % 5 != 0 && str[i - 1] == '#');
			cp = cp + (int)(i > 4 && str[i - 5] == '#');
			cp = cp + (int)(i % 5 < 3 && str[i + 1] == '#');
			cp = cp + (int)(i < 14 && str[i + 5] == '#');
			if (cp == 0)
				return (0);
		}
		i++;
	}
	if (count != 4)
		return(0)
	return (1);
}

/*
** return 1 if valid, 0 otherwise
*/

int validate(int fd)
{
	int ret
	char buf[BUFF_SIZE + 1];

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!check_size(ret, buf))
			return (0);
		if (!check_matrix(buf))
			return (0);
	}

	return (1);
}
