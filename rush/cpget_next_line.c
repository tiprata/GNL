/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:25:02 by pboutin           #+#    #+#             */
/*   Updated: 2015/12/20 17:20:07 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*stock_endof_buf(char *buf, int i);

int		get_next_line(int const fd, char **line)
{
	static char		*stock = "";
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*line1;
	int				j;
	int				y;
	static int				flag;
	size_t				v;
	static int		fdbis;


	v = 0;
	y = 0;
//	printf("$$$%s$$$$", stock);
	if (stock && fdbis != fd)
		stock = "";
//	printf("$$$%s$$$$", stock);
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0 && ret != -1 )
	{
//		printf("####%s####", buf);
//		printf("******%s*******", stock);
		buf[ret] = '\0';
		stock = ft_strjoin(stock, buf);
		if (stock && ft_strchr(stock, '\n'))
		{
//			printf("YOMEC1");
	//		ft_putchar('A');
			y = 0;
			j = 0;
			while (stock[y] != '\n')
				y++;
			y++;
			line1 = (char *)malloc(sizeof(char) * y);
			while (stock[j] != '\n')
			{
				line1[j] = stock[j];
				j++;
			}
			line1[j] = '\0';
//			(*line) = line1;
//			ft_putendl(stock);
			stock = ft_strchr(stock, '\n');
//			if (stock[1] != '\0')
//				flag = 0;
			stock++;
			(*line) = line1;
			y = 0;
	//		ft_putendl(stock);
			fdbis = fd;
			return (1);
		}
	}
	if (ft_strchr(stock, '\n') && flag == 0 )
	{
//		printf("YOMEC2");
//		ft_putchar('B');
		while (stock[y] != '\n')
			y++;
		y++;
		j = 0;
		line1 = (char *)malloc(sizeof(char) * y);
		while (stock[j] != '\n')
		{
			line1[j] = stock[j];
			j++;
		}
		line1[j] = '\0';
		(*line) = line1;
		while (stock[v] != '\0' && stock[v] != '\n')
			v++;
		if (v == ft_strlen(stock))
			flag = 1;
		stock = ft_strchr(stock, '\n');
		stock++;
		y = 0;
		fdbis = fd;
		return (1);
	}
/*	if (stock[1] == '\0' && ret == 0)
	{
		while(stock[y] != '\0')
		{
			stock[y] = '\0';
			y++;
		}
		free(stock);
	}*/
	if (ret == -1)
		return (-1);
	if (!(ft_strchr(stock, '\n')) && stock[0] != '\0' && flag == 0)
	{
//		printf("YOMEC3");
//		ft_putchar('C');
		j = 0;
		y = 0;
		while (stock[y] != '\0')
			y++;
		y++;
		line1 = (char *)malloc(sizeof(char) * y);
		while (stock[j] != '\0')
		{
			line1[j] = stock[j];
			j++;
		}
		line1[j] = '\0';
		(*line) = line1;
		while (stock[v] != '\0' && stock[v] != '\n')
			v++;
		if (v == ft_strlen(stock))
			flag = 1;
		fdbis = fd;
		return (0);
	}
	if (ret == 0)
	{
		(*line) = "";
		fdbis = fd;
		return (0);
	}
	fdbis = fd;
	return (0);
}
