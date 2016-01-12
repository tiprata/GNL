/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 16:31:37 by tiprata           #+#    #+#             */
/*   Updated: 2016/01/12 17:30:50 by tiprata          ###   ########.fr       */
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
# define BUF_SIZE 2

typedef struct	s_rest
{
	struct s_list *list;
	char *tmp;
	char *s;
	int ret;
}		            t_rest;

int     get_next_line(int const fd, char **line);
#endif
