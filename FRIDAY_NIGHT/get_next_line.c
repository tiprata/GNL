/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 16:30:50 by tiprata           #+#    #+#             */
/*   Updated: 2016/01/08 17:14:58 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int const fd, char **line)
{
	static t_rest st;
	int i = 0;
	int j = 0;
  char *str = NULL;
	st.list = NULL;

	if (fd < 0 || line == NULL || *line == NULL)
		return (-1);
	while (j != 1)
	{
		if ((st.ret = read(fd, st.tmp, BUF_SIZE)) && st.ret == -1)
			return (-1);
		st.tmp[ret] = '\0';
		if (st.ret == 0)
			j = 1;
    str = ft_strchr(st.tmp, '\n');
    if (str == NULL)
    {
      if (!(line))
        *line = ft_memalloc(BUF_SIZE + 1);
      *line = ft_strdupcat(*line, st.tmp);
    }
    else
      {
        i = st.tmp - &str;
        if (!(line))
          *line = ft_memalloc(BUF_SIZE + 1);
        *line = ft_dupnstrcat(*line, st.tmp, i);

      }
	}
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
