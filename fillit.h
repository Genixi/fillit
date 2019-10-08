/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equiana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:44:45 by equiana           #+#    #+#             */
/*   Updated: 2019/10/08 13:54:57 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# define BUFF_SIZE 21

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_figure
{
	char		letter;
	char		**arr;
	int			x;
	int			y;
	int			height;
	int			width;
}				t_figure;

int				ft_validate(int fd, char *buf);
t_list			*ft_read_in(int fd);
void			ft_get_xy(char **str, t_figure **figure);
void			ft_clear_figure(char ***field, t_figure *figure);
void			ft_error(void);
void			ft_output(t_list *lst);
void			ft_put_field(char **str);
char			**ft_find_solution(t_list *lst);

#endif
