/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 19:40:34 by tiprata           #+#    #+#             */
/*   Updated: 2016/01/14 20:31:10 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"

char	*ft_dupstrcat(char *s1, char *s2, int l)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == NULL || s1[0] == '\0')
	{
		if (!(str = ft_memalloc(l + 1)))
			return (NULL);
		ft_redstr(s2);
		ft_pinkchar('{');
		ft_putnbr(l + 1);
		ft_pinkchar('}');
		return ((str = ft_strncpy(str, s2, l)));
	}
	if (!(str = ft_memalloc(ft_strlen(s1) + l + 1)))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] && j < l)
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		ft_strd(char **s, char **str)
{
	if (s)
		ft_strdel(s);
	if (str)
		ft_strdel(str);
	return (0);
}

int		ft_static_exist(char **s, char **line, char **str, int ret)
{
	int i;

	i = 0;
	*str = ft_strchr(*s, '\n');
	if (*str == NULL)
	{
		ft_bluestr("Kabom");
		*line = ft_strdup(*s);
		ft_bluestr(*s);  // ICI ICI ICI
		return (2);
	}
	else
	{
		i = *str - *s;
		*line = ft_strsub(*s, 0, i);
		*s = ((&(*str[1])) != '\0') ? (ft_strdup(&(*str[1]))) : NULL;
//		if (*s == NULL)
		ft_redstr("==>");
		ft_greenstr(&(*str[1])); // ICI ICI ICI
		ft_redstr("<==");
		return (ret == 0 && *s[0] == '\0' ? 0 : 1);
	}
}

/*int		ft_read(t_rest *st, char **str, char **line, int const fd)
{
	while (st->j == 0)
	{
		st.tmp = st.tmp == NULL ? ft_memalloc(BUF_SIZE + 1) : st.tmp;
		if ((st->ret = read(fd, st->tmp, BUF_SIZE)) && st->ret == -1)
			return (-1);
		st->j = st->ret == 0 ? 1 : 0;
		st->tmp[st->ret + 1] = '\0';
		*str = ft_strchr(st->tmp, '\n');
		if (str == NULL)
		{
		*line = ft_dupstrcat(*line, st->tmp, ft_strlen(st->tmp));
		ft_strdel(&st->tmp);
		}
		else //if (str != NULL && (st->i = *str - st->tmp) && st->i >= 0) 
		{
//			st->i = *str - st->tmp;
			*line = ft_dupstrcat(*line, st->tmp, st->i);
			st->s = ft_strdup(str[1]);
			st->sfree = st->s;
			ft_strdel(&st->tmp);
			return (st->ret == 0 ? ft_strd(&st->s, str) : 1);
		}
	}
	}*/
int		get_next_line(int const fd, char **line)
{
	static t_rest	st;
	char			*str;
	
	str = NULL;
	st.i = 0;
	st.j = 0;
	st.tmp = NULL;
	st.sfree = NULL;
	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	if (st.s)
	{
		ft_bluestr("Existence\n");
		if ((ft_static_exist(&st.s, line, &str, st.ret)) != 2)
			return (st.ret == 0 && st.s[0] == '\0' ? ft_strd(&st.s, &str) : 1);
	}
	if (st.s == NULL && st.sfree != NULL)
	{
		ft_redstr("Freeance\n");
		ft_strdel(&st.sfree);
	}
//	ft_read(&st, &str, line, fd);
	while (st.j == 0)
	{
		st.tmp = (st.tmp == NULL ? ft_memalloc(BUF_SIZE + 1) : st.tmp);
		if ((st.ret = read(fd, st.tmp, BUF_SIZE)) && st.ret == -1)
			return (-1);
		st.j = st.ret == 0 ? 1 : 0;
		st.tmp[st.ret] = '\0';
		str = ft_strchr(st.tmp, '\n');
		if (str == NULL)
		{
			*line = ft_dupstrcat(*line, st.tmp, ft_strlen(st.tmp));
			ft_strdel(&st.tmp);
		}
		else
		{
			st.i = str - st.tmp;
			*line = ft_dupstrcat(*line, st.tmp, st.i);
			ft_greenstr(st.tmp);
			st.s = (&str[1]) != '\0' ? ft_strdup(&str[1]) : NULL;
			st.sfree = st.s;
			ft_strdel(&st.tmp);
			return (st.ret == 0 ? 0 : 1);//ft_strd(&st.s, &str) : 1);
		}
	}
//	ft_putnbr(st.ret);
	return (st.ret == 0 ? ft_strd(&st.s, &str) : 1);
}

int   main(int ac, char **av)
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
		}
		close(fd);
	}
	return (0);
}
