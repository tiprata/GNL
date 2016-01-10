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

char	*ft_dupstrcat(char *s1, char *s2, int l)
{
	int i;
	int j;
	char *str;

	i = -1;
	j = -1;
	if (!(str = ft_memalloc(ft_strlen(s1) + l + 1)))
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j] && j < l)
		str[i] = s2[j];
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

	st.list = NULL;
	st.tmp = NULL;
  st.s = NULL;
	ft_putstr("DEBUT FONCTION\n");
	if (fd < 0)
	{
		ft_putstr("FIN FONCTION :::::: ERREUR\n");
		return (-1);
	}
    if (st.s)
    {
			ft_putstr("clear\n");
      if ((str = ft_strchr(st.s, '\n')) != NULL)
      {
        i = st.s - str;
        *line = ft_strsub(st.s, 0, i);
        st.s = &str[1];
        return (st.ret == 0 && st.s[0] == '\0' ? 0 : 1);
      }
      else
        *line = ft_strdup(st.s);
    }
	while (j != 1)
	{
		ft_putstr("debut du bug\n");
		if (!(st.tmp))
			st.tmp = ft_memalloc(BUF_SIZE + 1);
		st.ret = read(fd, st.tmp, BUF_SIZE);
ft_bluestr("st.ret = ");
		ft_putnbr(st.ret);
		ft_putchar('\n');
		if (st.ret == -1)
			return (-1);
		st.tmp[st.ret + 1] = '\0';
		ft_redstr(st.tmp);
		if (st.ret == 0)
			j = 1;
    str = ft_strchr(st.tmp, '\n');
    if (str == NULL)
    {
      if (!(*line))
			{
				ft_greenstr("line == null \n");
				*line = ft_strdup(st.tmp);
				ft_putstr(*line);
			}
			else
			{
				ft_bluestr("LINE exiSTE\n");
      	*line = ft_dupstrcat(*line, st.tmp, ft_strlen(st.tmp));
				ft_redstr(*line);
			}
			ft_strdel(&st.tmp);
    }
    else
      {
        i = str - st.tmp;
        if (!(line))
          *line = ft_memalloc(BUF_SIZE + 1);
        *line = ft_dupstrcat(*line, st.tmp, i);
				ft_putstr("WHY THE BUG\n");
        st.s = ft_strdup(&str[1]);
				ft_strdel(&st.tmp);
        return (st.ret == 0 ? 0 : 1);
      }
	}
  return (1);
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
		while (stop != 1)
		{
			ret = get_next_line(fd, &line);
			ft_putendl(line);
			if (ret == 0)
				stop = 1;
			i++;
		}
	}
	return (0);
}
