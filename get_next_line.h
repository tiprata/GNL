/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 16:31:37 by tiprata           #+#    #+#             */
/*   Updated: 2015/12/14 16:31:54 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define BUF_SIZE 5

void    ft_redstr(char *str);
void    ft_pinkchar(char c);
void    ft_bluestr(char *str);
void    ft_pinkstr(char *str);
void    ft_greenstr(char *str);
int     get_next_line(int const fd, char **line);
int	ft_strlen(const char *s);
void	ft_putab(char **str);
void	ft_putnbr(int n);
void    ft_putstr(char const *s);
int	ft_strchr(const char *s, int c);
int     ft_strcmp(const char *s1, const char *s2);
char    *ft_strnjoin(char *s1, char *s2, int n);
char    *ft_strcpy(char *dest, const char *src);
char    *ft_strdup(const char *s1);
char    *ft_strsub(char const *s, unsigned int start, size_t len);
char    *ft_dupstrcat(char *s1, char *s2);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strnew(size_t size);
char    *ft_dupnstrcat(char *s1, char *s2, int n);
char    *ft_strncpy(char *dest, const char *src, size_t n);
void	*ft_putchar(char c);
void    ft_memdel(void **ap);
void    *ft_memset(void *b, int c, size_t n);
void    ft_putendl(char const *s);
void    *ft_memalloc(size_t size);
#endif
