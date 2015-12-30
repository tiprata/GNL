/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 16:30:50 by tiprata           #+#    #+#             */
/*   Updated: 2015/12/30 19:39:58 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int const fd, char **line)
{
	static t_rest s;
	int ret;
	char tmp[BUF_SIZE + 1];
	int stop;
	char *stock = NULL;
	int i;
	int j;
	int count;
	
	count = 0;
	j = 0;
	i = 0;
	stop = 0;
	ret = 0;
	if (s.str != NULL)
	{
//		ft_greenstr(s.str);
		stop = ft_strchr(s.str, '\n');
		if (stop > 0)
		{
			*line = ft_strsub(s.str, 0, stop - 1);
//			ft_bluestr(*line);
			while (i <= stop + 1)
			{
				s.str++;
				i++;
			}
			if (*s.str == '\0')
			{
				free(s.tmp);
				s.str = NULL;
				s.tmp = NULL;
			}
			//		ft_redstr(stock);
			return (fd);
		}
		stop = 0;
		stock = ft_strdup(s.str);
		free(s.str);
		s.str = NULL;
	}
	else
	{
		stock = ft_memalloc(BUF_SIZE + 1);
	}
	while ((ret = read(fd, tmp, BUF_SIZE)))
    {
		tmp[ret] = '\0';
		//ft_bluestr(tmp);
		stop = ft_strchr(tmp, '\n');
//		ft_putnbr(stop);
		if (stop >= 0 && s.str == NULL)
		{
			//		ft_putnbr(stop);
			//	ft_putchar('\n');
			//	s.str = ft_strnew(ft_strlen(tmp) - stop - 1);
			stock = ft_dupnstrcat(stock, tmp, stop - 1);
			ft_redstr(stock);
			ft_putchar('{');
			ft_putnbr(stop);
			ft_putchar('}');
			s.str = ft_strsub(tmp, stop + 1, ft_strlen(tmp) - stop - 1);
			s.tmp = s.str;
			if (!(line))
				ft_greenstr("jump off the bridge");
			*line = ft_strdup(stock);
			return (ret);
		}
		else
		{
//			ft_redstr("BREW UPDATE\n");
			stock = ft_dupstrcat(stock, tmp);
			free(s.str);
			s.str = NULL;
		}
    }
//	ft_putchar('|');
//	ft_greenstr(stock);
	ft_putchar('|');
	ft_redstr(stock);
	*line = ft_strdup(stock);
	free(stock);
	stock = NULL;
	return (ret);
}

int	main(int ac, char **av)
{
	int fd;
	int ret;
	char **line = NULL;
	int i;

	i = 0;
		line = (char **)malloc(sizeof(char *) * 10);
	ret = 0;
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		while ((ret = get_next_line(fd, &line[i])))
		{
			ft_bluestr(line[i]);
//			ft_putchar('\n');
			i++;
		}
	}
	line[i] = NULL;
	return (0);
}
