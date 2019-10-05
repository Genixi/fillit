/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:44:45 by equiana           #+#    #+#             */
/*   Updated: 2019/10/05 15:49:21 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# define BUFF_SIZE 21

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

int				ft_validate(int fd, char *buf);
t_list			*ft_read_in(int fd);
void			ft_error(void);
void			ft_output(t_list *lst);

typedef struct	s_figure
{
	char letter;
	char *arr;
}				t_figure;

#endif
