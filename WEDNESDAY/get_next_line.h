/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 16:31:37 by tiprata           #+#    #+#             */
/*   Updated: 2016/01/14 16:49:13 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define BUF_SIZE 8

typedef struct	s_rest
{
	char		*tmp;
	char		*s;
	int			ret;
	char		*sfree;
	int			i;
	int			j;
}				t_rest;

int				get_next_line(int const fd, char **line);
#endif
