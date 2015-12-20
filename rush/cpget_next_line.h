/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:25:20 by pboutin           #+#    #+#             */
/*   Updated: 2015/12/19 23:33:25 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#define BUFF_SIZE 20

int		get_next_line(int const fd, char **line);

#endif
