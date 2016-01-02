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
  char tmp[BUF_SIZE + 1];
  int stop;
  char *stock = NULL;
  int i;
  int j;
  int count;
  
  count = 0;
  j = 0;
  i = 0;
  stop = 0; // IF DEUX BACKSLASH N DAFFILE ATTENTION LA FONCTION BEUGUE
  if (s.str != NULL)
    {
      stop = ft_strchr(s.str, '\n');
      if (stop > 0)
		{
	  *line = ft_strsub(s.str, 0, stop - 1);
	  while (i != stop + 1)
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
		return (s.ret);
		}
		stop = 0;
		stock = ft_strdup(s.str);
	}
	else
		stock = ft_memalloc(BUF_SIZE + 1);
	while ((s.ret = read(fd, tmp, BUF_SIZE)))
    {
		tmp[s.ret] = '\0';
		stop = ft_strchr(tmp, '\n');
		if (stop >= 0 && s.str == NULL)
		{
			//	s.str = ft_strnew(ft_strlen(tmp) - stop - 1);
			stock = ft_dupnstrcat(stock, tmp, stop - 1);
			s.str = ft_strsub(tmp, stop + 1, ft_strlen(tmp) - stop - 1);
			s.tmp = s.str;
			*line = ft_strdup(stock);
			return (s.ret);
		}
		else
		{
			stock = ft_dupstrcat(stock, tmp);
			free(s.str);
			s.str = NULL;
		}
    }
	*line = ft_strdup(stock);
	free(stock);
	stock = NULL;
	return (s.ret);
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
			i++;
		}
	}
	line[i] = NULL;
	i = 0;
	while (line[i])
	{
		ft_putstr(line[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
