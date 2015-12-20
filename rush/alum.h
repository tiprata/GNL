#ifndef ALUM_H
# define ALUM_H

# define BUF_SIZE 2
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct	s_list
{
  int i;
  struct s_list *next;
}		t_list;

void	ft_redstr_fd(char *str, int fd);
void    *ft_memalloc(size_t size);
void    *ft_memset(void *b, int c, size_t n);
void    ft_putchar(char c);
void    ft_putnbr(int n);
void    ft_putendl(char const *s);
int     ft_strlen(const char *s);
void    ft_list_push_back(t_list **begin_list, int newelem);
int     ft_atoi(const char *str);
#endif
