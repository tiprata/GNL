/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 19:40:34 by tiprata           #+#    #+#             */
/*   Updated: 2016/01/13 17:31:14 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"

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
		str[i] = s1[i];
	while (s2[++j] && j < l)
		str[i++] = s2[j];
	str[i] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}

//t_rest	ft_read(t_rest st, )

/*int		ft_static_exist(t_rest st, char **line, char *str)
{
	int i;

	i = 0;
	str = ft_strchr(st.s, '\n');
	if (str == NULL)
	{
		*line = ft_strdup(st.s);
		return (2);
	}
	else
	{
		i = str - st.s;
		*line = ft_strsub(st.s, 0, i);
			st.s = ((&str[1]) != NULL) ? ft_strdup(&str[1]) : NULL;
//		st.s = ((&str[1]) != NULL) ? ft_strdup(&str[1]) : NULL;
		return (st.ret == 0 && st.s[0] == '\0' ? 0 : 1);
	}
}*/

int	ft_strdelete(char **s, char **str)
{
	if (s)
		ft_strdel(s);
	if (str)
		ft_strdel(str);
	return (0);
}

int	ft_static_exist(char **s, char **line, char **str, int ret)
{
	int i;

	i = 0;
	*str = ft_strchr(*s, '\n');
	if (*str == NULL)
	{
		*line = ft_strdup(*s);
		return (2);
	}
	else
	{
		i = *str - *s;
		*line = ft_strsub(*s, 0, i);
		*s = ((&(*str[1])) != NULL) ? ft_strdup(&(*str[1])) : NULL;
		return (ret == 0 && *s[0] == '\0' ? 0 : 1);
	}
}

int	get_next_line(int const fd, char **line)
{
	static t_rest st;
	int i = 0;
	int j = 0;
	char *str = NULL;

	st.tmp = NULL;
 	if (fd < 0 || line == NULL )
		return (-1);
	*line = NULL;
	if (st.s)
		if ((ft_static_exist(&st.s, line, &str, st.ret)) != 2)
			return (st.ret == 0 && st.s[0] == '\0' ? ft_strdelete(&st.s, &str) : 1);
	if (st.s == NULL && st.sfree != NULL)
		ft_strdel(&st.s);
	while (j == 0)
	{
		if (!(st.tmp))
			st.tmp = ft_memalloc(BUF_SIZE + 1);
		if ((st.ret = read(fd, st.tmp, BUF_SIZE)) && st.ret == -1)
			return (-1);
		j = st.ret == 0 ? 1 : 0;
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
			st.sfree = st.s;
			ft_strdel(&st.tmp);
			return (st.ret == 0 ? ft_strdelete(&st.s, &str) : 1);
		}
	}
	return (st.ret == 0 ? ft_strdelete(&st.s, &str) : 1);
}

int   main(int ac, char **av)
{
	//int fd;
	int ret;
	char *line = NULL;
	int i;
	int stop;

(void)ac;
(void)av;
	stop = 0;
	i = 0;
	ret = 0;
	//if (ac > 1)
	//{
//		fd = open(av[1], O_RDONLY);
	//	if (fd == -1)
	//	{
	//		ft_putstr("ALERT FD -1\n");
	//		return (0);
	//	}
		while (1)
		{
			ret = get_next_line(0, &line);
//			ft_putstr(line);
//			ft_pinkchar('|');
			ft_strdel(&line);
			//if (ret == 0)
			//	stop = 1;
			i++;
		}
	//}
	return (0);
}
