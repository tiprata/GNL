/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 19:40:34 by tiprata           #+#    #+#             */
/*   Updated: 2016/01/11 14:39:09 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		ft_bluestr("||");
		ft_redstr(s1);
		ft_bluestr("||");
		ft_pinkstr(s2);
		ft_bluestr("||");
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
//  st.s = NULL;
	if (fd < 0)
		return (-1);
  if (st.s)
  {
		ft_bluestr("OK OK OK \n");
		str = ft_strchr(st.s, '\n');
		if (str == NULL)
		{
			*line = ft_strdup(st.s);
		}
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
		if (st.ret == 0)
			j = 1;
		if (!(st.tmp))
			st.tmp = ft_memalloc(BUF_SIZE + 1);
		st.ret = read(fd, st.tmp, BUF_SIZE);
		if (st.ret == -1)
			return (-1);
		st.tmp[st.ret + 1] = '\0';
  	str = ft_strchr(st.tmp, '\n');
    if (str == NULL)
    {
      if (!(*line))
			{
				*line = ft_strdup(st.tmp);
			}
			else
			{
      	*line = ft_dupstrcat(*line, st.tmp, ft_strlen(st.tmp));
			/*	ft_putchar('$');
				ft_redstr(st.tmp);
				ft_putchar('$');*/
			}
			ft_strdel(&st.tmp);
    }
    else
      {
        i = str - st.tmp;
				ft_pinkchar('X');
				ft_greenstr(str);
				ft_pinkchar('X');
        *line = ft_dupstrcat(*line, st.tmp, i);
        st.s = ft_strdup(&str[1]);
				ft_bluestr(st.s);
				ft_strdel(&st.tmp);
      }
	}
	if (st.s != NULL)
		ft_greenstr("DAMN\n");
	return (st.ret == 0 ? 0 : 1);
}

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
		while (stop != 1)
		{
			ret = get_next_line(fd, &line);
			ft_putstr(line);
			ft_pinkchar('|');
			ft_pinkchar('\n');
			ft_strdel(&line);
			if (ret == 0)
				stop = 1;
			i++;
		}
	}
	return (0);
}
