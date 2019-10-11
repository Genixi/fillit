/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:30:17 by equiana           #+#    #+#             */
/*   Updated: 2019/10/11 15:34:09 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		ft_putstr("invalid arguments\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() fail\n");
		return (0);
	}
	ft_put_field(ft_find_solution(ft_read_in(fd)));
	close(fd);
	return (0);
}
