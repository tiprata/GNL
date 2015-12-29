/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 16:30:50 by tiprata           #+#    #+#             */
/*   Updated: 2015/12/29 19:40:23 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int kol = 0;
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
  ft_greenstr("LET's GO ! \n");
	if (s.i == 2)
	{
		ft_greenstr("PUTAIN");
		*line = ft_strdup(s.str);
		return (ret);
	}
	if (s.str != NULL)
	{
		ft_pinkchar('{');
		ft_putnbr(kol);
		kol++;
		ft_pinkchar('}');
		ft_pinkchar('{');
		ft_redstr(s.str);
		ft_pinkchar('}');
		ft_putchar('\n');
		ft_redstr(s.str);
		stop = ft_strchr(s.str, '\n');
		if (stop)
		{
			*line = ft_strsub(s.str, 0, stop);
			while (i <= stop + 1)
			{
				s.str++;
				i++;
			}
      if (*s.str == '\0')
      {
        free(s.str);
        s.str = NULL;
      }
			ft_redstr(stock);
			return (fd);
		}
		stop = 0;
		stock = ft_strdup(s.str);
		free(s.str);
		s.str = NULL;
	}
	else
		stock = ft_memalloc(BUF_SIZE + 1);
	while ((ret = read(fd, tmp, BUF_SIZE)))
	{
		tmp[ret] = '\0';
ft_bluestr(tmp);
ft_putchar('\n');
		stop = ft_strchr(tmp, '\n');
		if (stop)
			s.str = ft_strnew(ft_strlen(tmp) - stop - 1);
    else
		{
			//	  ft_putendl(tmp);
			stock = ft_dupstrcat(stock, tmp);
			free(s.str);
			s.str = NULL;
		} 
	}
	*line = ft_strdup(stock);
	free(stock);
	stock = NULL;
	return (ret);
}

int	main(int ac, char **av)
{
	int fd;
	int ret;
	char **line;
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
			ft_putchar('\n');
			i++;
		}
	}
	line[i] = NULL;
	return (0);
}
