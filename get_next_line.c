/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 19:40:34 by tiprata           #+#    #+#             */
/*   Updated: 2016/01/12 14:29:13 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*ft_dupstrcat(char *s1, char *s2, int l)
{
	int i;
	int j;
	char *str;

	i = -1;
	j = -1;
	if (s1 == NULL)
		s1 = ft_strdup("");
	if (!(str = ft_memalloc(ft_strlen(s1) + l + 1)))
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];// == '\n' ? '\0' : s1[i];
	while (s2[++j] && j < l)
		str[i++] = s2[j];// == '\n' ? '\0' : s2[j];
	str[i] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}

int	get_next_line(int const fd, char **line)
{
	static t_rest st;
	int i = 0;
	int j = 0;
  char *str = NULL;

	st.tmp = NULL;
  //st.s = NULL;
	if (fd < 0)
		return (-1);
  if (st.s)
  {
		str = ft_strchr(st.s, '\n');
		if (str == NULL)
			*line = ft_strdup(st.s);
		else
    {
      i = str - st.s;
      *line = ft_strsub(st.s, 0, i);
			if (&str[1])
      	st.s = ft_strdup(&str[1]);
      return (st.ret == 0 && st.s[0] == '\0' ? 0 : 1);
    }
  }
	while (j == 0)
	{
		if (!(st.tmp))
			st.tmp = ft_memalloc(BUF_SIZE + 1);
		st.ret = read(fd, st.tmp, BUF_SIZE);
		if (st.ret == 0)
			j = 1;
		if (st.ret == -1)
			return (-1);
		st.tmp[st.ret + 1] = '\0';
  	str = ft_strchr(st.tmp, '\n');
    if (str == NULL)
    {
      if (!(*line))
				*line = ft_strdup(st.tmp);
			else
      	*line = ft_dupstrcat(*line, st.tmp, ft_strlen(st.tmp));
			ft_strdel(&st.tmp);
    }
    else
      {
        i = str - st.tmp;
        *line = ft_dupstrcat(*line, st.tmp, i);
        st.s = ft_strdup(&str[1]);
				ft_strdel(&st.tmp);
				return (st.ret == 0 ? 0 : 1);
      }
	}
	return (st.ret == 0 ? 0 : 1);
}

/*int		main(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	fd = 1;
	out = dup(fd);
	pipe(p);
	dup2(p[1], fd);
	write(fd, "aaa\nbbb\nccc\nddd\n", 16);
	dup2(out, fd);
	close(p[1]);
	get_next_line(p[0], &line);
	if ((strcmp(line, "aaa")) == 0)
	{
		ft_greenstr(line);
		ft_putchar('\n');
//	ft_greenstr("FIRST LINE : OK|\n");
	}
	else
		ft_redstr("False\n");
	get_next_line(p[0], &line);
	if ((strcmp(line, "bbb")) == 0)
	{
		ft_greenstr(line);
		ft_putchar('\n');
//	ft_greenstr("SECOND LINE : OK|\n");
	}
	else
		ft_redstr("False\n");
	ft_strdel(&line);
	get_next_line(p[0], &line);
	if ((strcmp(line, "ccc")) == 0)
	{
		ft_greenstr(line);
		ft_putchar('\n');
//		ft_bluestr("THIRD LINE : OK|\n");
	}
	else
		ft_redstr("False\n");
	get_next_line(p[0], &line);
	if ((strcmp(line, "ddd")) == 0)
	{
		ft_greenstr(line);
		ft_putchar('\n');
	//	ft_bluestr("FOURTH LINE : OK|\n");
	}
else
	ft_redstr("False");
int x = get_next_line(p[0], &line);
if ((strcmp(line, "")) == 0)
	ft_bluestr("joooooo");
	if (x == 0)
	ft_greenstr("POOOOO");
get_next_line(p[0], &line);
ft_bluestr(line);

	return (0);
}
*/
int	main(int ac, char **av)
{
	int fd;
	int ret;
	char *line = NULL;
	int i;
	int stop;

	stop = 0;
	i = 0;
	ret = 0;
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			{
				ft_putstr("ALERT FD -1\n");
				return (0);
			}
		while ((ret = get_next_line(fd, &line)))
		{
//			if (ret == 0)
//			stop = 1;
			ft_putstr(line);
			ft_pinkchar('|');
			ft_pinkchar('\n');
			ft_strdel(&line);
		}
		get_next_line(fd, &line);
		ft_putstr(line);

	}
	return (0);
}
