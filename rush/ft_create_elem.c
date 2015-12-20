#include <stdlib.h>
#include "libft.h"

t_list	*ft_create_elem(char *elem)
{
	t_list *list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->next = NULL;
	list->str = ft_strdup(elem);
	list->a = 65;
//	list->prev = list;
	return (list);
/*
	if (!(list = (t_list *)malloc(sizeof(t_list))))
	{
		ft_putstr("fail malloc\n");
		return (NULL);
	}
	if (!elem)
	{
		ft_putstr("ELEM NOt FOUND\n");
		list->str = NULL;
		list->next = NULL;
	}
	else
	{
		ft_putstr("can put elem\n");
		list->str = ft_strdup(elem);
		list->next = NULL;
		ft_putstr("elem put ok\n");
	}
	return (list);
	*/
}
