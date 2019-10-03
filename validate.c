/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:47:06 by equiana           #+#    #+#             */
/*   Updated: 2019/10/03 21:23:11 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int	check_size(int ret, char *str)
{
	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n')
		return (0);
	if (str[19] != '\n')
		return (0);
	if ((ret > 20) && str[20] != '\n')
		return (0);
	return (1);
}

int	check_element(char *str, int i)
{
	int cp;

	cp = 0;
	cp = cp + (int)((i % 5 != 0) && (str[i - 1] == '#'));
	cp = cp + (int)((i > 4) && (str[i - 5] == '#'));
	cp = cp + (int)((i % 5 < 3) && (str[i + 1] == '#'));
	cp = cp + (int)((i < 14) && (str[i + 5] == '#'));
	return (cp);
}

int	check_matrix(char *str)
{
	int i;
	int count;
	int n;
	int cp;

	i = 0;
	count = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (0);
		if (str[i] == '#')
		{
			count++;
			cp = check_element(str, i);
			n = n + cp;
			if (cp == 0)
				return (0);
		}
		i++;
	}
	if (count != 4 || !(n == 6 || n == 8))
		return (0);
	return (1);
}

int	validate(int fd)
{
	int		ret;
	int		i;
	char	buf[BUFF_SIZE + 1];
	char	*last_line;

	i = 1;
	ret = 1;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!check_size(ret, buf))
			return (0);
		if (!check_matrix(buf))
			return (0);
		last_line = buf;
		i++;
	}
	if (ret == 0 && ft_strlen(last_line) != 20)
		return (0);
	return (1);
}
