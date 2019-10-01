/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:30:17 by equiana           #+#    #+#             */
/*   Updated: 2019/10/01 22:39:22 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		ft_putstr("invalide arguments\n");
		return (0);
	}
	fd = opne(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() fail\n");
		return (0);
	}
	if (!validate(fd))
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_putstr("all good!!\n");
	close(fd);
	return (0);
}
